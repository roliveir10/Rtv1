/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 04:57:13 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/19 08:54:36 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

void		rt_vect_rotation(t_vector *vec, double mat[3][3])
{
	double	tmpx;
	double	tmpy;

	tmpx = vec->x;
	tmpy = vec->y;
	vec->x = mat[0][0] * tmpx + mat[0][1] * tmpy + mat[0][2] * vec->z;
	vec->y = mat[1][0] * tmpx + mat[1][1] * tmpy + mat[1][2] * vec->z;
	vec->z = mat[2][0] * tmpx + mat[2][1] * tmpy + mat[2][2] * vec->z;
}

void		rt_set_ref(t_ray *ray, t_form form)
{
	int		i;

	i = -1;
	ray->o = rt_vsub(ray->o, form.center);
	while (++i < 3)
	{
		rt_vect_rotation(&ray->dir, form.mat[i]);
		rt_vect_rotation(&ray->o, form.mat[i]);
	}
}

void		rt_reset_point(t_form form, t_vector *inte)
{
	int		i;

	i = 3;
	while (--i + 1)
		rt_vect_rotation(inte, form.mati[i]);
	*inte = rt_vadd(*inte, form.center);
}
