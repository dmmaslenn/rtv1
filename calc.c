/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 15:19:21 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/10/18 15:40:26 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

float		vectordot(t_v *v1, t_v *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_v			vectorsub(t_v *v1, t_v *v2)
{
	t_v		result;

	result.x = v1->x - v2->x;
	result.y = v1->y - v2->y;
	result.z = v1->z - v2->z;
	return (result);
}

t_v			vectorscale(float c, t_v *v)
{
	t_v		result;

	result.x = v->x * c;
	result.y = v->y * c;
	result.z = v->z * c;
	return (result);
}

t_v			vectoradd(t_v *v1, t_v *v2)
{
	t_v		result;

	result.x = v1->x + v2->x;
	result.y = v1->y + v2->y;
	result.z = v1->z + v2->z;
	return (result);
}

void		newimg(t_str *e)
{
	e->img = mlx_new_image(e->mlx, 700, 700);
	e->str = mlx_get_data_addr(e->img, &e->v1, &e->v2, &e->v3);
	draww(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
