/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_light_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 21:28:14 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/13 08:39:30 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

static void			rt_shadow_acne(t_inter *inter)
{
	float			offset;

	offset = 1e-3;
	inter->x += inter->norm.x * offset;
	inter->y += inter->norm.y * offset;
	inter->z += inter->norm.z * offset;
}

#include <stdio.h>

static int			rt_compare_dist(t_pos inte, t_pos va, t_inter vb)
{
	t_pos			v_lum;
	t_pos			v_inter;
	double			a;
	double			b;

	v_lum = rt_get_vector(inte, va);
	v_inter.x = vb.x - inte.x;
	v_inter.y = vb.y - inte.y;
	v_inter.z = vb.z - inte.z;
	a = sqrt(pow(v_lum.x, 2) + pow(v_lum.y, 2) + pow(v_lum.z, 2));
	b = sqrt(pow(v_inter.x, 2) + pow(v_inter.y, 2) + pow(v_inter.z, 2));
	if (a < b)
		return (1);
	return (0);
}

t_inter				rt_light_manager(t_env *env, int index)
{
	int				i;
	int				j;
	static void		(*lst_func[NBR_FORM])(t_pos, t_pos, t_form, t_inter*) = {
		rt_sphere, rt_plan, rt_cylindre, rt_cone};
	t_pos			vlight;
	double			angle;
	t_color			fcolor;
	double			spec;
	t_color			specular;
	t_color			diffuse;

	t_pos			inte;

	t_pos			inte_tmp;
	t_pos			vl_tmp;


	rt_shadow_acne(&env->inter[index]);
	inte.x = env->inter[index].x;
	inte.y = env->inter[index].y;
	inte.z = env->inter[index].z;
	ft_bzero(&fcolor, sizeof(t_color));
	i = -1;
	while (++i < env->nbr_lum)
	{
		j = -1;
		vlight = rt_get_vector(inte, env->lum[i].pos);
		vlight = rt_normalize(vlight);
		while (++j < env->nbr_form)
		{
			inte_tmp = inte;
			vl_tmp = vlight;
			rt_set_ref(&inte, &vlight, env->form[j]);
			lst_func[env->form[j].ftype](inte, vlight,
					env->form[j], &env->inter[j]);
			rt_reset_point(env->form[j], &inte);
			if (!env->inter[j].out && !rt_compare_dist(inte,
						env->lum[i].pos, env->inter[j]))
			{
				inte = inte_tmp;
				break ;
			}
			inte = inte_tmp;
			vlight = vl_tmp; // after dot_product ?
		}
		if (j == env->nbr_form)
		{
			angle = rt_dot_product(env->inter[index].norm, vlight);
			if (angle > 0.0)
			{
				spec = pow(angle, 256);
				specular.r = env->lum[i].color.r * spec * 0.5 * env->lum[i].color.r;
				specular.g = env->lum[i].color.g * spec * 0.5 * env->lum[i].color.g;
				specular.b = env->lum[i].color.b * spec * 0.5 * env->lum[i].color.b;
				diffuse.r = env->lum[i].color.r * angle;
				diffuse.g = env->lum[i].color.g * angle;
				diffuse.b = env->lum[i].color.b * angle;
				fcolor.r += env->inter[index].color.r * (specular.r + diffuse.r);
				fcolor.g += env->inter[index].color.g * (specular.g + diffuse.g);
				fcolor.b += env->inter[index].color.b * (specular.b + diffuse.b);
			}
		}
	}
	env->inter[index].color = fcolor;
	return (env->inter[index]);
}
