/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:32:59 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/07 13:40:44 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

#include <stdio.h>

static void		pars_fill_cam(t_cam *cam)
{
	cam->vec_dir.x = 1.0;
	cam->vp_width = 0.35;
	cam->vp_height = 0.5;
	cam->vp_dist = 1.0;
	cam->vp_upleft.x = cam->pos.x + cam->vec_dir.x * cam->vp_dist;
	cam->vp_upleft.y = cam->pos.y + cam->vec_dir.y * cam->vp_height / 2.0;
	cam->vp_upleft.z = cam->pos.z + cam->vec_dir.z * cam->vp_width / 2.0;
	debug_print_pos(cam->vp_upleft);
}

int				main(void)
{
	t_env		env;

	ft_bzero(&env, sizeof(t_env));
	pars_fill_cam(&env.cam);
	rt_main(&env);
	return (0);
}
