/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:32:59 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/23 00:27:18 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "pars.h"
#include "rt.h"

void			rt_fill_matrot(double (*mat)[3][3][3], t_vector rotation)
{
	double		mcos;
	double		msin;
	double		teta;

	teta = rotation.x * M_PI / 180.0;
	mcos = cos(teta);
	msin = sin(teta);
	ft_bzero(mat, sizeof(double) * 27);
	(*mat)[0][0][0] = 1.0;
	(*mat)[0][1][1] = mcos;
	(*mat)[0][1][2] = -msin;
	(*mat)[0][2][1] = msin;
	(*mat)[0][2][2] = mcos;

	teta = rotation.y * M_PI / 180.0;
	mcos = cos(teta);
	msin = sin(teta);
	(*mat)[1][0][0] = mcos;
	(*mat)[1][0][2] = msin;
	(*mat)[1][1][1] = 1.0;
	(*mat)[1][2][0] = -msin;
	(*mat)[1][2][2] = mcos;

	teta = rotation.z * M_PI / 180.0;
	mcos = cos(teta);
	msin = sin(teta);
	(*mat)[2][0][0] = mcos;
	(*mat)[2][0][1] = -msin;
	(*mat)[2][1][0] = msin;
	(*mat)[2][1][1] = mcos;
	(*mat)[2][2][2] = 1.0;
}

static void		pars_fill_cam(t_cam *cam)
{
	cam->vec_dir[0].x = 1.0;
	cam->vec_dir[1].y = 1.0;
	cam->vec_dir[2].z = 1.0;
	cam->vp_width = SCREENX;
	cam->vp_height = SCREENY;
	cam->vp_dist = 1000;

	cam->pos.x = 0.0;
	cam->pos.y = 0.0;	
	cam->pos.z = 0.0;	
}

int				main(int argc, char **argv)
{
	t_env		env;

	(void)argv;
	if (argc != 2)
	{
		ft_putstr_fd("rtv1: file.json\n", 2);
		return (1);
	}
	ft_bzero(&env, sizeof(t_env));
	(void)argv;
	env.scene.spec = 0.1;
	if (pars_file(argv[1], &env))
		return (1);
	ft_bzero(&env.cam, sizeof(t_cam));
	pars_fill_cam(&env.cam);
	rt_main(&env);
	return (0);
}
