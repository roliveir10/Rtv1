/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_inter_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:28:08 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/19 10:05:06 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vector		rt_no_inter(void)
{
	t_vector		color_black;

	ft_bzero(&color_black, sizeof(t_vector));
	return (color_black);
}

double				rt_getinter(t_ftype ftype, t_ray *ray, t_form form)
{
	static double	(*func[NBR_FORM])(t_ray, t_form) = {
		rt_sphere, rt_plan, rt_cylindre, rt_cone};

	rt_set_ref(ray, form);
	return (func[ftype](*ray, form));
}

static void			rt_getinter_data(t_env *env, t_inter *inter, t_vector vdir)
{
	int				i;

	i = 3;
	inter->color = env->form[inter->id].color;
	inter->norm = rt_get_normal(inter->pos, env->form[inter->id]);
	inter->pos = rt_vadd(rt_vmul(inter->norm, 1e-4), inter->pos);
	rt_reset_point(env->form[inter->id], &inter->pos);
	while (--i + 1)
		rt_vect_rotation(&inter->norm, env->form[inter->id].mati[i]);
	inter->viewdir = vdir;
}

t_vector			rt_viewdir_inter(t_env *env, t_ray ray_orig)
{
	int				i;
	t_ray			ray;
	t_inter			inter;
	double			dist;
	double			min;

	i = -1;
	min = -1.0;
	ft_bzero(&inter, sizeof(t_inter));
	while (++i < env->nbr_form)
	{
		ray = ray_orig;
		dist = rt_getinter(env->form[i].ftype, &ray, env->form[i]);
		if (dist > 0 && (dist < min || min == -1.0))
		{
			min = dist;
			inter.id = i;
			inter.pos = rt_get_posinter(ray, min);
		}
	}
	if (min < 0)
		return (rt_no_inter());
	rt_getinter_data(env, &inter, ray_orig.dir);
	return (rt_light_manager(env, inter));
}
