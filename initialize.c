/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:26:53 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/10/18 16:34:28 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void	insphere(t_str *e)
{
	e->spheres[0].pos.x = 0;
	e->spheres[0].pos.y = 0;
	e->spheres[0].pos.z = -10;
	e->spheres[1].pos.x = -150;
	e->spheres[1].pos.y = 0;
	e->spheres[1].pos.z = 0;
	e->spheres[2].pos.x = 100;
	e->spheres[2].pos.y = 250;
	e->spheres[2].pos.z = 0;
	e->spheres[3].pos.x = 230;
	e->spheres[3].pos.y = 0;
	e->spheres[3].pos.z = 0;
}

void	initialize(t_str *e)
{
	e->r.dir.x = -0.1;
	e->r.dir.y = 0;
	e->r.dir.z = 1;
	e->v.x = 0;
	e->v.y = 1;
	e->v.z = 0;
	e->con.x = 0;
	e->con.y = 1;
	e->con.z = 0;
	e->pln.x = -0.1;
	e->pln.y = 0;
	e->pln.z = 1;
}
