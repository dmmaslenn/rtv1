/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:24:22 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/10/18 17:02:50 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

int			intersectraysphere(t_r *r, t_sp *sp, t_str *e)
{
	float	discr;
	t_v		dist;

	e->a = vectordot(&r->dir, &r->dir);
	dist = vectorsub(&r->start, &sp->pos);
	e->b = 2 * vectordot(&r->dir, &dist);
	e->c = vectordot(&dist, &dist) - (sp->radius * sp->radius);
	discr = e->b * e->b - 4 * e->a * e->c;
	if (discr < 0)
		return (0);
	else
	{
		e->sqrtdiscr = sqrtf(discr);
		e->t0 = (-e->b + e->sqrtdiscr) / (2);
		e->t1 = (-e->b - e->sqrtdiscr) / (2);
		if (e->t0 > e->t1)
			e->t0 = e->t1;
		if ((e->t0 > 0.001f) && (e->t0 < e->dists))
			e->dists = e->t0;
		return (1);
	}
}

int			intersectraysphere1(t_r *r, t_sp *sp, t_str *e)
{
	t_v		dist;
	float	discr;

	e->a = vectordot(&r->dir, &r->dir);
	dist = vectorsub(&r->start, &sp->pos);
	e->b = 2 * vectordot(&r->dir, &dist);
	e->c = vectordot(&dist, &dist) - (sp->radius * sp->radius);
	discr = e->b * e->b - 4 * e->a * e->c;
	if (discr < 0)
		return (0);
	else
	{
		e->sqrtdiscr = sqrtf(discr);
		e->t0 = (-e->b + e->sqrtdiscr) / (2);
		e->t1 = (-e->b - e->sqrtdiscr) / (2);
		if (e->t0 > e->t1)
			e->t0 = e->t1;
		if ((e->t0 > 0.001f) && (e->t0 < e->dists1))
			e->dists1 = e->t0;
		return (1);
	}
}

void		draw(t_str *e)
{
	t_v		scaled;
	t_v		newstart;
	t_v		n;
	t_m		currentmat;

	scaled = vectorscale(e->dists, &e->r.dir);
	newstart = vectoradd(&e->r.start, &scaled);
	n = vectorsub(&newstart, &e->spheres[0].pos);
	n = normalize(n);
	e->temp = vectordot(&n, &n);
	if (e->temp == 0)
		return ;
	e->temp = 1.0f / sqrtf(e->temp);
	n = vectorscale(e->temp, &n);
	n = normalize(n);
	currentmat = e->materials[e->spheres[0].material];
	calc(e, newstart, n, currentmat);
}

void		draw1(t_str *e)
{
	t_v		scaled;
	t_v		newstart;
	t_v		n;
	t_m		currentmat;

	scaled = vectorscale(e->dists1, &e->r.dir);
	newstart = vectoradd(&e->r.start, &scaled);
	n = vectorsub(&newstart, &e->spheres[3].pos);
	n = normalize(n);
	e->temp = vectordot(&n, &n);
	if (e->temp == 0)
		return ;
	e->temp = 1.0f / sqrtf(e->temp);
	n = vectorscale(e->temp, &n);
	n = normalize(n);
	currentmat = e->materials[e->spheres[3].material];
	calc(e, newstart, n, currentmat);
}
