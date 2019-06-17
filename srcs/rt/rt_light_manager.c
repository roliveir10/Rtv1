/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_light_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 21:28:14 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/17 05:14:02 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

/*static void			rt_shadow_acne(t_inter *inter)
{
	float			offset;

	offset = 1e-3;
	inter->pos.x += inter->norm.x * offset;
	inter->pos.y += inter->norm.y * offset;
	inter->pos.z += inter->norm.z * offset;
}

static int			rt_compare_dist(t_vector inte, t_vector va, t_vector vb)
{
	t_vector		v_lum;
	t_vector		v_inter;
	double			a;
	double			b;

	v_lum = rt_get_vector_dist(inte, va);
	v_inter = rt_vsub(inte, vb);
	a = sqrt(pow(v_lum.x, 2) + pow(v_lum.y, 2) + pow(v_lum.z, 2));
	b = sqrt(pow(v_inter.x, 2) + pow(v_inter.y, 2) + pow(v_inter.z, 2));
	if (a < b)
		return (1);
	return (0);
}

static int			rt_get_way_to_light(t_env *env, int j, t_ray ray)
{
	static void		(*func[NBR_FORM])(t_ray, t_form, t_inter*) = {
		rt_sphere, rt_plan, rt_cylindre, rt_cone};
	int				i;
	t_ray			ray_tmp;

	i = -1;
	while (++i < env->nbr_form)
	{
		ray_tmp = ray;
		rt_set_ref(&ray_tmp, env->form[i]);
		func[env->form[i].ftype](ray_tmp, env->form[i], &env->inter[i]);
		if (!env->inter[j].out && !rt_compare_dist(ray_tmp.o, env->lum[j].pos,
				env->inter[j].pos))
			break ;
	}
	return (i);
}
*/
t_vector				rt_light_manager(t_env *env, t_inter inter)
{
/*	int				i;
	int				j;
	double			angle;
	t_ray			ray;
	t_vector		color;*/

	(void)env;
	return (inter.norm);
	/*rt_shadow_acne(&env->inter[index]);
	ft_bzero(&color, sizeof(t_vector));
	i = -1;
	while (++i < env->nbr_lum)
	{
		ray.o = env->inter[index].pos;
		ray.dir = rt_get_vector(ray.o, env->lum[i].pos);
		if ((j = rt_get_way_to_light(env, i, ray)) == env->nbr_form)
		{
			angle = rt_dot_product(env->inter[index].norm, ray.dir);
			color = rt_vadd(rt_get_color(env, i, index, angle), color);
		}
	}
	return (color);*/
}
