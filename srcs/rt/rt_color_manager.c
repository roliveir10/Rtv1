/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:17:08 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/17 05:07:36 by roliveir         ###   ########.fr       */
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

/*t_vector		rt_get_color(t_env *env, int i, int index, double angle)
{
	double		spec;
	t_vector	specular;
	t_vector	diffuse;
	t_vector	color;

	ft_bzero(&color, sizeof(t_vector));
	if (angle > 0.0)
	{
		spec = pow(angle, 256) * 0.5;
		specular.x = env->lum[i].color.x * spec;
		specular.y = env->lum[i].color.y * spec;
		specular.z = env->lum[i].color.z * spec;
		diffuse.x = env->lum[i].color.x * angle;
		diffuse.y = env->lum[i].color.y * angle;
		diffuse.z = env->lum[i].color.z * angle;
		color.x = env->inter[index].color.x * (specular.x + diffuse.x);
		color.y = env->inter[index].color.y * (specular.y + diffuse.y);
		color.z = env->inter[index].color.z * (specular.z + diffuse.z);
	}
	return (color);
}*/
