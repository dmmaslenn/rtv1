/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 14:59:25 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/10/18 16:32:48 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void	inmat(t_str *e)
{
	e->materials = (t_m *)malloc(sizeof(t_m) * 5);
	e->materials[0].diffuse.red = 1;
	e->materials[0].diffuse.green = 0;
	e->materials[0].diffuse.blue = 0;
	e->materials[0].reflection = 0.2;
	e->materials[1].diffuse.red = 0;
	e->materials[1].diffuse.green = 1;
	e->materials[1].diffuse.blue = 0;
	e->materials[1].reflection = 0.5;
	e->materials[2].diffuse.red = 0;
	e->materials[2].diffuse.green = 0;
	e->materials[2].diffuse.blue = 1;
	e->materials[2].reflection = 0.9;
	e->materials[3].diffuse.red = 0.9;
	e->materials[3].diffuse.green = 0.5;
	e->materials[3].diffuse.blue = 0.4;
	e->materials[3].reflection = 0.1;
	e->materials[4].diffuse.red = 0.9;
	e->materials[4].diffuse.green = 0.5;
	e->materials[4].diffuse.blue = 0.9;
	e->materials[4].reflection = 0.1;
}

void	inlight(t_str *e)
{
	e->lights = (t_l *)malloc(sizeof(t_l) * 1);
	e->lights[0].pos.x = 200;
	e->lights[0].pos.y = -400;
	e->lights[0].pos.z = -400;
	e->lights[0].intensity.red = 0.7;
	e->lights[0].intensity.green = 0.7;
	e->lights[0].intensity.blue = 0.7;
}

void	hide(t_str *e)
{
	e->spheres = (t_sp *)malloc(sizeof(t_sp) * 4);
	e->spheres[3].radius = 80;
	e->spheres[3].material = 0;
	e->spheres[2].radius = 30;
	e->spheres[2].material = 4;
	e->spheres[1].radius = 10;
	e->spheres[1].material = 1;
	e->spheres[0].radius = 50;
	e->spheres[0].material = 3;
	e->r.dir = normalize(e->r.dir);
	e->pln = normalize(e->pln);
	e->v = normalize(e->v);
	e->con = normalize(e->con);
	e->pl.point.x = 0;
	e->pl.point.y = 0;
	e->pl.point.z = 100;
	e->st = -500;
}

void	cc(t_str *e, t_r lightray, t_v n, t_m currentmat)
{
	t_l	currentlight;

	currentlight = e->lights[0];
	if (checkintersecttwo(e, &lightray) == 0)
	{
		e->lambert = vectordot(&lightray.dir, &n) * e->coef;
		e->red += e->lambert * currentmat.diffuse.red \
			* currentlight.intensity.red;
		e->green += e->lambert * currentmat.diffuse.green\
			* currentlight.intensity.green;
		e->blue += e->lambert * currentmat.diffuse.blue \
			* currentlight.intensity.blue;
	}
}

void	calc(t_str *e, t_v newstart, t_v n, t_m currentmat)
{
	t_r	lightray;
	t_l	currentlight;
	t_v	dist;

	e->coef = 1.0;
	e->j = -1;
	while (++e->j < 1)
	{
		currentlight = e->lights[e->j];
		dist = vectorsub(&currentlight.pos, &newstart);
		if (vectordot(&n, &dist) <= 0.0f)
			continue;
		e->q = sqrtf(vectordot(&dist, &dist));
		if (e->q <= 0.0f)
			continue;
		lightray.start = newstart;
		lightray.start = normalize(lightray.start);
		lightray.dir = vectorscale((1 / e->q), &dist);
		lightray.dir = normalize(lightray.dir);
		cc(e, lightray, n, currentmat);
	}
}
