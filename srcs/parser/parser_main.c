/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:32:59 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/22 01:18:44 by roliveir         ###   ########.fr       */
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
		//		ft_putstr_fd("rtv1: usge\n", 2);
		//		return (1);
	}
	ft_bzero(&env, sizeof(t_env));
	(void)argv;
	if (pars_file(argv[1], &env))
		return (1);
	pars_fill_cam(&env.cam);

	print_form(env);
	print_light(env);


//	env.nbr_form = 1;
//	env.nbr_lum = 3;
//	if (!(env.form = (t_form*)ft_memalloc(sizeof(t_form) * env.nbr_form)))
//		rt_delenv(&env);
/*	if (!(env.lum = (t_lum*)ft_memalloc(sizeof(t_lum) * env.nbr_lum)))
>>>>>>> lex_pars
		rt_delenv(&env);

	env.scene.ambient = 0.00;
	env.scene.spec = 0.5;

	env.lum[0].type = LCAST;
	env.lum[0].dir.y = 1;
	//should be normalize & negating
	rt_attribute_color(0xFFFFFF, &env.lum[0].color);

	env.lum[0].pos.x = 10;
	env.lum[0].pos.y = 0;
	env.lum[0].pos.z = 50;
	env.lum[0].type = LPOINT;
	env.lum[0].constant = 1;
	env.lum[0].linear = 0.09;
	env.lum[0].quadratic = 0.0032;
	rt_attribute_color(0xFFFFFF, &env.lum[0].color);

	env.lum[1].type = LCAST;
	env.lum[1].dir.y = 1;
	//should be normalize & negating
	rt_attribute_color(0xFFFFFF, &env.lum[1].color);

	env.lum[1].pos.x = -14.99;
	env.lum[1].pos.y = 0;
	env.lum[1].pos.z = 50;
	env.lum[1].type = LPOINT;
	env.lum[1].constant = 1;
	env.lum[1].linear = 0.35;
	env.lum[1].quadratic = 0.44;
	rt_attribute_color(0xFF0000, &env.lum[1].color);

	env.form[0].ftype = SPHERE;
	env.form[0].center.z = 50;
	env.form[0].center.x = 0;
	env.form[0].center.y = 1.0;
	env.form[0].r = 0.25;
	rt_attribute_color(0x555555, &env.form[0].color);
	rt_fill_matrot(&env.form[0].mat, env.form[0].rotation);
	rt_fill_matrot(&env.form[0].mati, env.form[0].rotation);
	env.form[0].material = rt_get_material(NOTHING, env.scene);

	env.form[1].ftype = SPHERE;
	env.form[1].center.z = 50;
	env.form[1].center.x = 2.0;
	env.form[1].center.y = 5.0;
	env.form[1].r = 0.25;
	rt_attribute_color(0x555555, &env.form[1].color);
	rt_fill_matrot(&env.form[1].mat, env.form[1].rotation);
	rt_fill_matrot(&env.form[1].mati, env.form[1].rotation);
	env.form[1].material = rt_get_material(NOTHING, env.scene);

	env.form[2].ftype = SPHERE;
	env.form[2].center.z = 50;
	env.form[2].center.x = -10;
	env.form[2].center.y = -5;
	env.form[2].r = 0.25;
	rt_attribute_color(0x555555, &env.form[2].color);
	rt_fill_matrot(&env.form[2].mat, env.form[2].rotation);
	rt_fill_matrot(&env.form[2].mati, env.form[2].rotation);
	env.form[2].material = rt_get_material(NOTHING, env.scene);

	env.form[3].ftype = SPHERE;
	env.form[3].center.z = 50;
	env.form[3].center.x = 8;
	env.form[3].center.y = -4;
	env.form[3].r = 0.25;
	rt_attribute_color(0x555555, &env.form[3].color);
	rt_fill_matrot(&env.form[3].mat, env.form[3].rotation);
	rt_fill_matrot(&env.form[3].mati, env.form[3].rotation);
	env.form[3].material = rt_get_material(NOTHING, env.scene);

	env.form[4].ftype = SPHERE;
	env.form[4].center.z = 50;
	env.form[4].center.x = -11;
	env.form[4].center.y = 7;
	env.form[4].r = 0.25;
	rt_attribute_color(0x555555, &env.form[4].color);
	rt_fill_matrot(&env.form[4].mat, env.form[4].rotation);
	rt_fill_matrot(&env.form[4].mati, env.form[4].rotation);
	env.form[4].material = rt_get_material(NOTHING, env.scene);


	env.form[6].ftype = SPHERE;
	env.form[6].center.z = 53;
	env.form[6].center.x = 13;
	env.form[6].center.y = 0;
	env.form[6].r = 0.5;
	rt_attribute_color(0xFF0000, &env.form[6].color);
	rt_fill_matrot(&env.form[6].mat, env.form[6].rotation);
	rt_fill_matrot(&env.form[6].mati, env.form[6].rotation);
	env.form[6].material = rt_get_material(NOTHING, env.scene);



	env.form[5].ftype = PLAN;
	env.form[5].center.x = 0;
	env.form[5].center.y = 0;
	env.form[5].center.z = 55;
	env.form[5].point.x = 0;
	env.form[5].point.y = 0;
	env.form[5].point.z = -1.0;
	//env.form[5].rotation.z = 10;
	rt_attribute_color(0xFFFFFF, &env.form[5].color);
	rt_fill_matrot(&env.form[5].mat, env.form[5].rotation);
	//env.form[5].rotation.z = -10;
	rt_fill_matrot(&env.form[5].mati, env.form[5].rotation);
	env.form[5].material = rt_get_material(NOTHING, env.scene);

	env.form[7].ftype = CONE;
	env.form[7].center.z = 50;
	env.form[7].center.x = -15;
	env.form[7].center.y = 0;
	env.form[7].h = 5.0;
	env.form[7].angle = 0.5;
//	env.form[7].rotation.z = 50;
	rt_attribute_color(0xffffff, &env.form[7].color);
	rt_fill_matrot(&env.form[7].mat, env.form[7].rotation);
//	env.form[7].rotation.z = -50;
	rt_fill_matrot(&env.form[7].mati, env.form[7].rotation);
	env.form[7].material = rt_get_material(NOTHING, env.scene);

	env.form[8].ftype = CYLINDRE;
	env.form[8].center.z = 50;
	env.form[8].center.x = -13;
	env.form[8].center.y = 0;
	env.form[8].r = 0.25;
	env.form[8].h = 20.0;
	env.form[8].rotation.z = 15;
	rt_attribute_color(0xff0000, &env.form[8].color);
	rt_fill_matrot(&env.form[8].mat, env.form[8].rotation);
	env.form[8].rotation.z = -15;
	rt_fill_matrot(&env.form[8].mati, env.form[8].rotation);
	env.form[8].material = rt_get_material(NOTHING, env.scene);
*/
	rt_main(&env);
	return (0);
}
