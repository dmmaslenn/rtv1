/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 15:20:21 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/10/18 16:46:19 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

int			exitb(int keycode, t_str *e)
{
	t_str	*w;

	w = (t_str *)e;
	keycode = 0;
	exit(1);
	return (0);
}

int			my_key_funct(int keycode, void *e)
{
	t_str	*w;

	w = (t_str *)e;
	if (keycode == 53)
		exit(1);
	return (0);
}

int			checkintersecttwo(t_str *e, t_r *ray)
{
	e->t = INFINITY;
	e->dists = INFINITY;
	e->distcn = INFINITY;
	e->distc = INFINITY;
	e->dists1 = INFINITY;
	if ((intersectraysphere(ray, &e->spheres[0], e) == 1) && (e->t > e->dists))
		e->t = e->dists;
	if ((intersectraycone(ray, &e->spheres[1], e) == 1) && (e->t > e->distcn))
		e->t = e->distcn;
	if ((intersectraycylinder(ray, &e->spheres[2], e) == 1)\
		&& (e->t > e->distc))
		e->t = e->distc;
	if ((intersectraysphere1(ray, &e->spheres[3], e) == 1)\
		&& (e->t > e->dists1))
		e->t = e->dists1;
	if (e->t == INFINITY)
		return (0);
	return (1);
}

t_v			normalize(t_v vt)
{
	float	l;

	l = sqrtf((vt.x * vt.x) + (vt.y * vt.y) + (vt.z * vt.z));
	vt.x = vt.x / l;
	vt.y = vt.y / l;
	vt.z = vt.z / l;
	return (vt);
}
