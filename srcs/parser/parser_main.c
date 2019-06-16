/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:32:59 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/16 11:45:39 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"
#include <math.h>
#include "rt.h"
/*
static void		pars_fill_cam(t_cam *cam)
{
	t_pos		vx;
	t_pos		vy;
	t_pos		vz;

	cam->vec_dir[0].x = 1.0;
	cam->vec_dir[1].y = 1.0;
	cam->vec_dir[2].z = 1.0;
	cam->vp_width = 0.64;
	cam->vp_height = 0.36;
	cam->vp_dist = 1.0;
	
	vz = rt_vmul(cam->vec_dir[2], cam->vp_dist);
	vy = rt_vmul(cam->vec_dir[1], cam->vp_height / 2.0);
	vx = rt_vmul(cam->vec_dir[0], cam->vp_width / 2.0);
	cam->vp_upleft.x = cam->pos.x + vz.x + vy.x - vx.x;
	cam->vp_upleft.y = cam->pos.y + vz.y + vy.y - vx.y;
	cam->vp_upleft.z = cam->pos.z + vz.z + vy.z - vx.z;
}*/

int				main(int argc, char **argv)
{
	t_env		*env;

	if (argc != 2)
	{
		ft_putstr_fd("rtv1: usge\n", 2);
		return (1);
	}
	env = pars_file(argv[1]);
	/*

	ft_bzero(&env, sizeof(t_env));
	pars_fill_cam(&env.cam);
	env.nbr_form = 3;
	env.nbr_lum = 3;
	if (!(env.form = (t_form*)ft_memalloc(sizeof(t_form) * env.nbr_form)))
		rt_delenv(&env);
	if (!(env.lum = (t_lum*)ft_memalloc(sizeof(t_lum) * env.nbr_lum)))
		rt_delenv(&env);

	env.lum[0].pos.x = 3.0;
	env.lum[0].pos.y = 0;
	env.lum[0].pos.z = 0;
	rt_attribute_color(0xFFFFFF, &env.lum[0].color);
<<<<<<< HEAD
	env.lum[1].pos.x = -3.0;
	env.lum[1].pos.y = 0;
=======

	env.lum[1].pos.x = 60.0;
	env.lum[1].pos.y = 10.0;
>>>>>>> fec0d48b87359a79ef27fbcea5ce322a35f23d1e
	env.lum[1].pos.z = 0;
	rt_attribute_color(0xFDA600, &env.lum[1].color);

	env.lum[2].pos.y = 5.0;
	env.lum[2].pos.z = 0.0;
	rt_attribute_color(0xcc5500, &env.lum[2].color);

	env.form[0].ftype = PLAN;
	env.form[0].center.x = 0;
	env.form[0].center.y = -5;
	env.form[0].center.z = 0;
	env.form[0].point.x = 0;
	env.form[0].point.y = 1.0;
	env.form[0].point.z = 0;
	rt_attribute_color(0xFFFFFF, &env.form[0].color);
	
	env.form[1].ftype = SPHERE;
	env.form[1].center.z = 40.0;
	env.form[1].center.x = 0;
	env.form[1].center.y = 1.0;
	env.form[1].r = 2.0;
	rt_attribute_color(0xE77D11, &env.form[1].color);

	env.form[2].ftype = SPHERE;
	env.form[2].center.z = 80.0;
	env.form[2].center.x = 7.0;
	env.form[2].center.y = -2.0;
	env.form[2].r = 5.0;
	rt_attribute_color(0xBDBDBD, &env.form[2].color);

	env.form[2].ftype = SPHERE;
	env.form[2].center.z = 200.0;
	env.form[2].center.x = -50.0;
	env.form[2].center.y = -5.0;
	env.form[2].r = 7.0;
	rt_attribute_color(0xC1440E, &env.form[2].color);

	env.form[3].ftype = SPHERE;
	env.form[3].center.z = 300;
	env.form[3].center.x = -75.0;
	env.form[3].center.y = 45.0;
	env.form[3].r = 1.0;
	rt_attribute_color(0xF0E7E7, &env.form[3].color);

	env.form[4].ftype = SPHERE;
	env.form[4].center.z = 200.0;
	env.form[4].center.x = 60.0;
	env.form[4].center.y = -3.0;
	env.form[4].r = 5.0;
	rt_attribute_color(0x451804, &env.form[4].color);

	env.form[6].ftype = CYLINDRE;
	env.form[6].center.z = 200.0;
	env.form[6].center.x = -20.0;
	env.form[6].r = 2.0;
	env.form[6].h = 13.0;
	env.form[6].rotation.z = 30.0;
	rt_attribute_color(0x451804, &env.form[6].color);

	env.form[7].ftype = CONE;
	env.form[7].center.z = 400.0;
	env.form[7].center.x = 100.0;
	env.form[7].center.y = 20.0;
	env.form[7].h = 100.0;
	env.form[7].angle = 180 / M_PI;
	rt_attribute_color(0xFF5555, &env.form[7].color);
*/
//	rt_main(&env);
	return (0);
}
