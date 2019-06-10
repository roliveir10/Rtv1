/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_browse_form.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:28:08 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/10 17:40:10 by roliveir         ###   ########.fr       */
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
		rt_sphere, rt_plan};
	double			min;

	i = -1;
	min = 9000.0;
	ft_bzero(env->inter, sizeof(t_inter));
	while (++i < env->nbr_form)
	{
		func[(*form)[i].ftype](env->cam.pos, pix, (*form)[i], &env->inter[i]);
		if (!env->inter[i].out && env->inter[i].t < min)
			min = env->inter[i].t;
	}
	i = -1;
	while (++i < env->nbr_form)
		if (env->inter[i].t == min)
			return (rt_light_manager(env, i));
	return (rt_no_inter());
}
