/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 12:33:35 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/10/18 16:45:14 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

int			intersectplane(t_r *r, t_str *e)
{
	t_v		dist;
	float	t;

	dist = vectorsub(&r->start, &e->pl.point);
	dist = vectorscale(-1, &dist);
	if (vectordot(&r->dir, &e->pln) == 0)
		return (0);
	t = (vectordot(&dist, &e->pln) / vectordot(&r->dir, &e->pln));
	if (t < e->distp)
	{
		e->distp = t;
		return (1);
	}
	else
		return (1);
}

void		ccc(t_str *e, t_v n, t_m currentmat, t_r lightray)
{
	t_l		currentlight;

	currentlight = e->lights[0];
	if (checkintersecttwo(e, &lightray) == 0)
	{
		e->lambert = vectordot(&lightray.dir, &n) \
			* e->coef;
		e->red += e->lambert * currentmat.diffuse.red \
			* currentlight.intensity.red;
		e->green += e->lambert * currentmat.diffuse.green \
			* currentlight.intensity.green;
		e->blue += e->lambert * currentmat.diffuse.blue \
			* currentlight.intensity.blue;
	}
}

void		helpd(t_str *e, t_v n, t_m currentmat, t_v newstart)
{
	t_r		lightray;
	t_v		dist;
	t_l		currentlight;

	e->coef = 1.0;
	e->j = -1;
	while (++e->j < 1)
	{
		currentlight = e->lights[e->j];
		dist = vectorsub(&currentlight.pos, &newstart);
		e->q = sqrtf(vectordot(&dist, &dist));
		if (e->q <= 0.0f)
			continue;
		lightray.start = newstart;
		lightray.dir = vectorscale((1 / e->q), &dist);
		ccc(e, n, currentmat, lightray);
	}
}

void		drawpl(t_str *e)
{
	t_m		currentmat;
	t_v		n;
	t_v		newstart;
	t_v		scaled;

	scaled = vectorscale(e->distp, &e->r.dir);
	newstart = vectoradd(&e->r.start, &scaled);
	if (vectordot(&e->r.dir, &e->pln) < 0)
		n = vectorscale(-1, &e->pln);
	else
		n = e->pln;
	n = normalize(n);
	currentmat = e->materials[2];
	helpd(e, n, currentmat, newstart);
}
