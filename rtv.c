/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 14:33:14 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/10/19 13:50:35 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

int			checkintersect2(t_str *e, t_r *ray, int i)
{
	if ((intersectraycylinder(ray, &e->spheres[2], e) == 1) \
		&& (e->t > e->distc))
	{
		e->t = e->distc;
		i = 3;
	}
	if ((intersectplane(ray, e) == 1) && (e->t > e->distp))
	{
		e->t = e->distp;
		i = 4;
	}
	if ((intersectraysphere1(ray, &e->spheres[3], e) == 1) \
		&& (e->t > e->dists1))
	{
		e->t = e->dists1;
		i = 5;
	}
	return (i);
}

int			checkintersect(t_str *e, t_r *ray)
{
	int		i;

	i = 0;
	e->t = INFINITY;
	e->dists = INFINITY;
	e->distcn = INFINITY;
	e->distc = INFINITY;
	e->distp = INFINITY;
	e->dists1 = INFINITY;
	if ((intersectraysphere(ray, &e->spheres[0], e) == 1) && (e->t > e->dists))
	{
		e->t = e->dists;
		i = 1;
	}
	if ((intersectraycone(ray, &e->spheres[1], e) == 1) && (e->t > e->distcn))
	{
		e->t = e->distcn;
		i = 2;
	}
	return (checkintersect2(e, ray, i));
}

void		drawww(t_str *e, int x, int y)
{
	int		k;

	e->r.start.x = x - 300;
	e->r.start.y = y - 350;
	e->r.start.z = e->st;
	e->red = 0;
	e->green = 0;
	e->blue = 0;
	k = checkintersect(e, &e->r);
	if (k != 0)
	{
		if (k == 1)
			draw(e);
		else if (k == 2)
			drawcn(e);
		else if (k == 3)
			drawc(e);
		else if (k == 4)
			drawpl(e);
		else if (k == 5)
			draw1(e);
	}
	pix(e, x, y);
}

void		draww(t_str *e)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < 700)
	{
		x = 0;
		while (x < 700)
		{
			drawww(e, x, y);
			x++;
		}
		y++;
	}
}

int			main(int argc, char **argv)
{
	t_str	e;

	if (ft_strcmp(argv[argc - 1], "./RTv1") != 0)
	{
		ft_putstr("Usage: ./RTv1\n");
		return (0);
	}
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 700, 700, "42");
	hide(&e);
	initialize(&e);
	insphere(&e);
	inlight(&e);
	inmat(&e);
	newimg(&e);
	mlx_hook(e.win, 2, 5, my_key_funct, &e);
	mlx_hook(e.win, 17, 1L << 17, exitb, &e);
	mlx_loop(e.mlx);
	return (0);
}
