/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:17:08 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/20 02:34:09 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

void			rt_attribute_color(int color, t_vector *s_color)
{
	s_color->x = (double)(color >> 16 & 0xFF) / 255;
	s_color->y = (double)(color >> 8 & 0xFF) / 255;
	s_color->z = (double)(color & 0xFF) / 255;
}

t_vector		rt_get_color(t_lum lum, t_inter inter, t_material mat)
{
	t_vector	color;
	t_vector	ltot;
	double		attenuation;
	double		angle;

	angle = rt_dot(inter.norm, inter.lightdir);
	ft_bzero(&color, sizeof(t_vector));
	if (angle > 0.0)
	{
		attenuation = rt_attenuation(lum, rt_dist(lum.pos, inter.pos));
		ltot = rt_vadd(rt_vadd(
					rt_spec(lum.color, inter, mat, attenuation),
					rt_diffuse(lum.color, angle, mat, attenuation)),
					rt_ambient(lum.color, mat, attenuation));
		color = rt_vvmul(ltot, inter.color);
	}
	return (color);
}

t_vector		rt_ambient_only(t_lum lum, t_material mat, t_inter inter)
{
	return (rt_vvmul(rt_ambient(lum.color, mat, 1), inter.color));
}
