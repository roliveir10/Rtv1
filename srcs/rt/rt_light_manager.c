/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_light_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 21:28:14 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/10 18:32:37 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

static void			rt_shadow_acne(t_inter *inter, t_pos norm)
{
	float			offset;

	offset = 0.0002;
	inter->x += norm.x * offset;
	inter->y += norm.y * offset;
	inter->z += norm.z * offset;
}

#include <stdio.h>

t_inter				rt_light_manager(t_env *env, int index)
{
	int				i;
	int				j;
	static void		(*lst_func[NBR_FORM])(t_pos, t_pos, t_form, t_inter*) = {
		rt_sphere, rt_plan};
	t_pos			norm;
	t_pos			vlight;
	double			angle;
	t_color			fcolor;

	t_pos			inte;
	
	norm = rt_get_normal(env->inter[index], env->form[index]);
	rt_shadow_acne(&env->inter[index], norm);
	inte.x = env->inter[index].x;
	inte.y = env->inter[index].y;
	inte.z = env->inter[index].z;
	ft_bzero(&fcolor, sizeof(t_color));
	i = -1;
	while (++i < env->nbr_lum)
	{
		j = -1;
		vlight = rt_get_vector(inte, env->lum[i].pos);
		while (++j < env->nbr_form)
		{
			lst_func[env->form[j].ftype](inte, vlight,
					env->form[j], &env->inter[j]);
			if (!env->inter[j].out)
				break ;
		}
		if (j == env->nbr_form)
		{
			angle = rt_dot_product(norm, rt_vmul(vlight, -1.0));
			if (angle > 0.0)
			{
				fcolor.r = env->lum[i].color.r * env->inter[index].color.r * angle;
				fcolor.g = env->lum[i].color.g * env->inter[index].color.g * angle;
				fcolor.b = env->lum[i].color.b * env->inter[index].color.b * angle;
			}
		}
			fcolor.r = norm.x;
			fcolor.g = norm.y;
			fcolor.b = norm.z;
	}
	env->inter[index].color = fcolor;
	return (env->inter[index]);
}
