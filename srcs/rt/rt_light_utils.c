/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_light_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 02:07:21 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/20 10:34:26 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

t_vector		rt_spec(t_vector light, t_inter inter, t_material mat,
		double attenuation)
{
	t_vector	spec;
	double		angle;

	if (BLINN == 1)
		angle = rt_dot(inter.norm, rt_normalize(rt_vadd(inter.lightdir,
						inter.viewdir)));
	else
		angle = rt_dot(inter.norm, inter.lightdir);
	spec = rt_vmul(mat.specular, pow(angle, 256 * mat.shininess));
	return (rt_vmul(rt_vvmul(light, spec), attenuation));
}

t_vector		rt_diffuse(t_vector light, double angle, t_material mat,
		double attenuation)
{
	return (rt_vmul(rt_vvmul(light, rt_vmul(mat.diffuse, angle)), attenuation));
}

t_vector		rt_ambient(t_vector light, t_material mat, double attenuation)
{
	return (rt_vmul(rt_vvmul(light, mat.ambient), attenuation));
}

double			rt_attenuation(t_lum lum, double dist)
{
	if (lum.type != LPOINT)
		return (1);
	return (1.0 / (lum.constant + lum.linear * dist + lum.quadratic * dist));
}
