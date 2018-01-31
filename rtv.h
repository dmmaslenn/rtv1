/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 14:34:28 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/10/19 13:45:01 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RTV_H
# define __RTV_H
# include "mlx.h"
# include "libft/libft.h"
# include <math.h>
# define MIN(a,b) (((a) < (b)) ? (a) : (b))

typedef struct	s_v
{
	float		x;
	float		y;
	float		z;
}				t_v;

typedef struct	s_sp
{
	t_v			pos;
	float		radius;
	int			material;
}				t_sp;

typedef struct	s_r
{
	t_v			start;
	t_v			dir;
}				t_r;

typedef struct	s_c
{
	float		red;
	float		green;
	float		blue;
}				t_c;

typedef struct	s_l
{
	t_v			pos;
	t_c			intensity;
}				t_l;

typedef struct	s_m
{
	t_c			diffuse;
	float		reflection;
}				t_m;

typedef struct	s_p
{
	t_v			point;
}				t_p;

typedef struct	s_str
{
	int			j;
	float		coef;
	float		q;
	float		lambert;
	t_v			con;
	t_v			v;
	t_v			pln;
	float		temp;
	float		sqrtdiscr;
	float		t1;
	float		t0;
	float		a;
	float		b;
	float		c;
	float		t;
	float		st;
	float		distp;
	float		distcn;
	float		distpl;
	float		k;
	float		dists;
	float		dists1;
	float		dists2;
	float		distc;
	float		distc1;
	float		red;
	float		green;
	float		blue;
	char		*str;
	void		*img;
	int			v1;
	int			v2;
	int			v3;
	void		*mlx;
	void		*win;
	int			x;
	float		ll;
	t_m			*materials;
	t_l			*lights;
	t_sp		*spheres;
	t_p			pl;
	t_r			r;
	t_v			cc;
}				t_str;

float			vectordot(t_v *v1, t_v *v2);
t_v				vectorsub(t_v *v1, t_v *v2);
t_v				vectorscale(float c, t_v *v);
t_v				vectoradd(t_v *v1, t_v *v2);
void			draww(t_str *e);
int				my_key_funct(int keycode, void *e);
int				exitb(int keycode, t_str *e);
void			calc(t_str *e, t_v newstart, t_v n, t_m currentmat);
void			hide(t_str *e);
int				intersectraysphere1(t_r *r, t_sp *sp, t_str *e);
void			drawc3(t_str *e);
void			drawc2(t_str *e);
void			drawc1(t_str *e);
void			draw2(t_str *e);
void			draw1(t_str *e);
void			inmat(t_str *e);
void			inlight(t_str *e);
void			insphere(t_str *e);
void			initialize(t_str *e);
t_v				normalize(t_v vt);
int				checkintersecttwo(t_str *e, t_r *ray);
int				checkintersect(t_str *e, t_r *ray);
int				intersectraycone(t_r *r, t_sp *s, t_str *e);
int				intersectplane(t_r *r, t_str *e);
void			drawc(t_str *e);
void			draw(t_str *e);
void			drawcn(t_str *e);
void			newimg(t_str *e);
void			pix(t_str *e, int x, int y);
void			drawpl(t_str *e);
int				intersectraysphere(t_r *r, t_sp *sp, t_str *e);
int				intersectraycylinder(t_r *r, t_sp *s, t_str *e);

#endif
