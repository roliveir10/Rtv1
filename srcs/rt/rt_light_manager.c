/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_light_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 21:28:14 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/19 10:05:05 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

static int			rt_compare_dist(t_vector inte, t_vector va, double dist)
{
	t_vector		v_lum;
	double			d_lum;

	v_lum = rt_vsub(va, inte);
	d_lum = sqrt(pow(v_lum.x, 2) + pow(v_lum.y, 2) + pow(v_lum.z, 2));
	if (d_lum < dist)
		return (1);
	return (0);
}

t_vector				rt_light_manager(t_env *env, t_inter inter)
{
	int				i;
	int				j;
//	double			angle;
	t_ray			ray;
	t_vector		color;
	double			dist;

	i = -1;
	ft_bzero(&color, sizeof(t_vector));
	while (++i < env->nbr_lum)
	{
		j = -1;
		while (++j < env->nbr_form)
		{
			ray.o = inter.pos;
			ray.dir = rt_get_vector(ray.o, env->lum[i].pos);
			if ((dist = rt_getinter(env->form[j].ftype, &ray, env->form[j])) > 0)
			{
				rt_reset_point(env->form[j], &ray.o);
				if (!rt_compare_dist(ray.o, env->lum[i].pos, dist))
					break ;
			}
		}
		if (j == env->nbr_form)
		{
		/*	if (env->lum[i].type == LCAST)
				angle = rt_dot(inter.norm, env->lum[i].pos);
			else
				angle = rt_dot(inter.norm, ray.dir);*/
			//ray dir a remettre dans la base monde ?
			if (env->lum[i].type == LCAST)
				inter.lightdir = env->lum[i].pos;
			else
				inter.lightdir = ray.dir;
			color = rt_vadd(rt_get_color(env->lum[i], inter, env->form[inter.id].material), color);
		}
		else
			color = rt_vadd(rt_get_ambient_only(env->lum[i], env->form[inter.id].material, inter), color);
	}
	return (color);
}
