/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_inter_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:28:08 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/17 05:13:59 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vector		rt_no_inter(void)
{
	t_vector		color_black;

	ft_bzero(&color_black, sizeof(t_vector));
	return (color_black);
}

t_vector			rt_browse_form(t_env *env, t_ray ray_tmp)
{
	int				i;
	t_ray			ray;
	t_inter			inter;
	static double	(*func[NBR_FORM])(t_ray, t_form) = {
		rt_sphere, rt_plan, rt_cylindre, rt_cone};
	double			dist;

	i = -1;
	ft_bzero(&inter, sizeof(t_inter));
	inter.t = -1.0;
	while (++i < env->nbr_form)
	{
		ray = ray_tmp;
		rt_set_ref(&ray, env->form[i]);
		dist = func[env->form[i].ftype](ray, env->form[i]);
		if (dist != -1.0 && (dist < inter.t || inter.t == -1.0))
		{
			inter.t = dist;
			inter.index = i;
		}
	}
	if (inter.t == -1.0)
		return (rt_no_inter());
	inter.color = env->form[inter.index].color;
	inter.pos = rt_get_posinter(ray, inter.t);
	inter.norm = rt_get_normal(inter.pos, env->form[inter.index]);
	rt_reset_point(env->form[inter.index], &inter.pos);
	return (rt_light_manager(env, inter));
}
