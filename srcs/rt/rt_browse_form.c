/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_browse_form.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:28:08 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/13 08:39:36 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_inter		rt_no_inter(void)
{
	t_inter			inter;

	ft_bzero(&inter, sizeof(t_inter));
	return (inter);
}

t_inter				rt_browse_form(t_env *env, t_form **form, t_pos pix)
{
	int				i;
	static void		(*func[NBR_FORM])(t_pos, t_pos, t_form, t_inter*) = {
		rt_sphere, rt_plan, rt_cylindre, rt_cone};
	double			min;
	t_cam			cam_tmp;
	t_pos			pix_tmp;
	t_pos			inte;

	i = -1;
	min = 9000.0;
	ft_bzero(env->inter, sizeof(t_inter));
	while (++i < env->nbr_form)
	{
		cam_tmp = env->cam;
		pix_tmp = pix;
		rt_set_ref(&env->cam.pos, &pix, (*form)[i]);
		func[(*form)[i].ftype](env->cam.pos, pix, (*form)[i], &env->inter[i]);
		if (!env->inter[i].out && env->inter[i].t < min)
			min = env->inter[i].t;
		if (!env->inter[i].out)
		{
			env->inter[i].norm = rt_get_normal(env->inter[i], (*form)[i]);
			inte.x = env->inter[i].x;
			inte.y = env->inter[i].y;
			inte.z = env->inter[i].z;
			rt_reset_point((*form)[i], &inte);
			env->inter[i].x = inte.x;
			env->inter[i].y = inte.y;
			env->inter[i].z = inte.z;
		}
		env->cam = cam_tmp;
		pix = pix_tmp;
	}
	i = -1;
	while (++i < env->nbr_form)
		if (env->inter[i].t == min)
			return (rt_light_manager(env, i));
	return (rt_no_inter());
}
