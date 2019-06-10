/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:32:59 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/10 17:36:39 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
}

int				main(void)
{
	t_env		env;

	ft_bzero(&env, sizeof(t_env));
	pars_fill_cam(&env.cam);
	env.nbr_form = 1;
	env.nbr_lum = 1;
	if (!(env.form = (t_form*)ft_memalloc(sizeof(t_form) * env.nbr_form)))
		rt_delenv(&env);
	if (!(env.lum = (t_lum*)ft_memalloc(sizeof(t_lum) * env.nbr_lum)))
		rt_delenv(&env);
	env.form[0].ftype = SPHERE;
	env.form[0].center.z = 20;
	env.form[0].center.x = 0;
	env.form[0].center.y = 1.0;
	env.form[0].r = 2.0;
	rt_attribute_color(0xBDBDBD, &env.form[0].color);
	env.lum[0].pos.x = 3.0;
	env.lum[0].pos.y = 0;
	env.lum[0].pos.z = 0;
	rt_attribute_color(0xFFFFFF, &env.lum[0].color);
	/*env.lum[1].pos.x = -3.0;
	env.lum[1].pos.y = 0;
	env.lum[1].pos.z = 0;
	rt_attribute_color(0x0000FF, &env.lum[1].color);
*/
	/*env.form[1].ftype = PLAN;
	env.form[1].center.x = 0;
	env.form[1].center.y = 1.0;
	env.form[1].center.z = 0;
	rt_attribute_color(0xBDBDBD, &env.form[1].color);
	env.form[1].point.x = 0;
	env.form[1].point.y = -5;
	env.form[1].point.z = 0;*/
	/*env.form[1].ftype = SPHERE;
	env.form[1].center.z = 40.0;
	env.form[1].center.x = -7.0;
	env.form[1].center.y = -2.0;
	env.form[1].r = 10.0;
	rt_attribute_color(0xBDBDBD, &env.form[1].color);
	env.form[2].ftype = SPHERE;
	env.form[2].center.z = 31.0;
	env.form[2].center.x = 2.0;
	env.form[2].r = 3.0;
	rt_attribute_color(0x00005F, &env.form[2].color);
	env.form[3].ftype = SPHERE;
	env.form[3].center.z = 30.5;
	env.form[3].center.x = 1.0;
	env.form[3].center.y = 2.0;
	env.form[3].r = 1.0;
	rt_attribute_color(0x8F0000, &env.form[3].color);
*/
	rt_main(&env);
	return (0);
}
