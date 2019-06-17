/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 04:57:13 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/17 05:14:00 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

static void		rt_fill_matrot(double (*mat)[3][3][3], double dteta)
{
	double		mcos;
	double		msin;
	double		teta;

	teta = dteta * M_PI / 180.0;
	mcos = cos(teta);
	msin = sin(teta);
	ft_bzero(mat, sizeof(double) * 27);
	(*mat)[0][0][0] = 1.0;
	(*mat)[0][1][1] = mcos;
	(*mat)[0][1][2] = -msin;
	(*mat)[0][2][1] = msin;
	(*mat)[0][2][2] = mcos;

	(*mat)[1][0][0] = mcos;
	(*mat)[1][0][2] = msin;
	(*mat)[1][1][1] = 1.0;
	(*mat)[1][2][0] = -msin;
	(*mat)[1][2][2] = mcos;

	(*mat)[2][0][0] = mcos;
	(*mat)[2][0][1] = -msin;
	(*mat)[2][1][0] = msin;
	(*mat)[2][1][1] = mcos;
	(*mat)[2][2][2] = 1.0;
}

void				rt_vect_rotation(t_vector *vec, double mat[3][3])
{
	double			tmpx;
	double			tmpy;

	tmpx = vec->x;
	tmpy = vec->y;
	vec->x = mat[0][0] * tmpx + mat[0][1] * tmpy + mat[0][2] * vec->z;
	vec->y = mat[1][0] * tmpx + mat[1][1] * tmpy + mat[1][2] * vec->z;
	vec->z = mat[2][0] * tmpx + mat[2][1] * tmpy + mat[2][2] * vec->z;
}

void				rt_set_ref(t_ray *ray, t_form form)
{
	int				i;
	int				j;
	double			mat[3][3][3];

	i = -1;
	ray->o.x -= form.center.x;
	ray->o.y -= form.center.y;
	ray->o.z -= form.center.z;
	while (++i < 3)
	{
		j = -1;
		rt_fill_matrot(&mat, -form.rotation[i]);
		while (++j < 3)
			rt_vect_rotation(&ray->dir, mat[i]);
	}
}

void				rt_reset_point(t_form form, t_vector *inte)
{
	int				i;
	double			mat[3][3][3];

	i = 3;
	while (--i + 1)
	{
		rt_fill_matrot(&mat, form.rotation[i]);
		rt_vect_rotation(inte, mat[i]);
	}
	inte->x += form.center.x;
	inte->y += form.center.y;
	inte->z += form.center.z;
}
