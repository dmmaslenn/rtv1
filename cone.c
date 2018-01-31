/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 17:43:42 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/10/19 13:46:42 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void		hh(t_r *r, float k, t_str *e, t_v dist)
{
	e->a = vectordot(&r->dir, &r->dir) - (1 + k * k)\
		* (vectordot(&r->dir, &e->con) * vectordot(&r->dir, &e->con));
	e->b = 2 * (vectordot(&r->dir, &dist) - ((1 + k * k)\
			* vectordot(&r->dir, &e->con) * vectordot(&dist, &e->con)));
	e->c = vectordot(&dist, &dist) - ((1 + k * k)\
			* vectordot(&dist, &e->con) * vectordot(&dist, &e->con));
}

int			intersectraycone(t_r *r, t_sp *s, t_str *e)
{
	float	k;
	t_v		dist;
	float	discr;

	k = 0.4;
	dist = vectorsub(&r->start, &s->pos);
	hh(r, k, e, dist);
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
			e->distcn = e->t0;
		return (1);
	}
}

void		drawcn(t_str *e)
{
	t_m		currentmat;
	t_v		scaled;
	t_v		newstart;
	t_v		n;
	t_v		b;

	scaled = vectorscale(e->distcn, &e->r.dir);
	newstart = vectoradd(&e->r.start, &scaled);
	n = vectorsub(&newstart, &e->spheres[1].pos);
	n = normalize(n);
	b = vectorscale((1 + 0.6 * 0.6), &e->v);
	b = normalize(b);
	n = vectorsub(&n, &b);
	n = normalize(n);
	e->temp = vectordot(&n, &n);
	if (e->temp == 0)
		return ;
	e->temp = 1.0f / sqrtf(e->temp);
	n = vectorscale(e->temp, &n);
	n = normalize(n);
	currentmat = e->materials[e->spheres[1].material];
	calc(e, newstart, n, currentmat);
}

void		pix(t_str *e, int x, int y)
{
	int		c;

	c = 4 * (700 * y + x);
	if (c < 700 * 700 * 4)
	{
		e->str[c] = (unsigned char)MIN(e->blue * 255, 255);
		e->str[c + 1] = (unsigned char)MIN(e->green * 255, 255);
		e->str[c + 2] = (unsigned char)MIN(e->red * 255, 255);
	}
}
