/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:17:08 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/19 07:08:06 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

void				rt_attribute_color(int color, t_vector *s_color)
{
	s_color->x = (double)(color >> 16 & 0xFF) / 255;
	s_color->y = (double)(color >> 8 & 0xFF) / 255;
	s_color->z = (double)(color & 0xFF) / 255;
}

static t_vector		rt_get_spec(t_vector light, t_inter inter, t_material mat,
		double attenuation)
{
	t_vector		spec;
	double			angle;
	
	if (BLINN == 1)
		angle = rt_dot(inter.norm, rt_normalize(rt_vadd(inter.lightdir, inter.viewdir)));
	else
		angle = rt_dot(inter.norm, inter.lightdir);
	spec = rt_vmul(mat.specular, pow(angle, 256 * mat.shininess));
	return (rt_vmul(rt_vvmul(light, spec), attenuation));
}

static t_vector		rt_get_diffuse(t_vector light, double angle, t_material mat,
		double attenuation)
{
	return (rt_vmul(rt_vvmul(light, rt_vmul(mat.diffuse, angle)), attenuation));
}

static t_vector		rt_get_ambient(t_vector light, t_material mat,
		double attenuation)
{
	return (rt_vmul(rt_vvmul(light, mat.ambient), attenuation));
}

t_vector			rt_get_color(t_lum lum, t_inter inter, t_material mat)
{
	t_vector	color;
	t_vector	l_total;
	t_vector	l_color;
	double		dist;
	double		attenuation;
	double		angle;

	dist = 1;
	angle = rt_dot(inter.norm, inter.lightdir);
	ft_bzero(&color, sizeof(t_vector));
	if (angle > 0.0)
	{
		if (lum.type == LPOINT)
			dist = sqrt(rt_dot(rt_vsub(lum.pos, inter.pos),
						rt_vsub(lum.pos, inter.pos)));
		attenuation = 1.0 / (lum.constant + lum.linear * dist
				+ lum.quadratic * dist);
		l_color = lum.color;

		l_total = rt_vadd(rt_vadd(rt_get_spec(l_color, inter, mat, attenuation),
					rt_get_diffuse(l_color, angle, mat, attenuation)),
				rt_get_ambient(l_color, mat, attenuation));
		color = rt_vvmul(l_total, inter.color);
	}
	return (color);
}

t_vector			rt_get_ambient_only(t_lum lum, t_material mat, t_inter inter)
{
	t_vector		color;

	ft_bzero(&color, sizeof(t_vector));
	color = rt_vvmul(rt_get_ambient(lum.color, mat, 1), inter.color);
	return (color);
}
