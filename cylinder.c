/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:27:56 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/10/18 15:58:08 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

int			intersectraycylinder(t_r *r, t_sp *s, t_str *e)
{
	t_v		dist;
	float	discr;

	e->a = vectordot(&r->dir, &r->dir) - \
		(vectordot(&r->dir, &e->v) * vectordot(&r->dir, &e->v));
	dist = vectorsub(&r->start, &s->pos);
	e->b = 2 * (vectordot(&r->dir, &dist) - \
			(vectordot(&r->dir, &e->v) * vectordot(&dist, &e->v)));
	e->c = vectordot(&dist, &dist) - (vectordot(&dist, &e->v)\
			* vectordot(&dist, &e->v)) - (s->radius * s->radius);
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
		if ((e->t0 > 0.001f) && (e->t0 < e->distc))
			e->distc = e->t0;
		return (1);
	}
}

void		drawc(t_str *e)
{
	t_v		scaled;
	t_v		newstart;
	t_v		n;
	t_m		currentmat;
	float	temp;

	scaled = vectorscale(e->distc, &e->r.dir);
	newstart = vectoradd(&e->r.start, &scaled);
	n = vectorsub(&newstart, &e->spheres[2].pos);
	n = normalize(n);
	n = vectorsub(&n, &e->v);
	n = normalize(n);
	temp = vectordot(&n, &n);
	if (temp == 0)
		return ;
	temp = 1.0f / sqrtf(temp);
	n = vectorscale(temp, &n);
	n = normalize(n);
	currentmat = e->materials[e->spheres[2].material];
	calc(e, newstart, n, currentmat);
}
