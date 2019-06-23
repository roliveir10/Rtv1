/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_anti_aliasing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:00:00 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/23 14:03:06 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <mlx.h>
#include "rt.h"

#include <stdio.h>
static void			*rt_print_line_aa(void *param)
{
	t_env			*env;
	t_ray			ray[4];
	int				pos;
	int				limit;
	t_vector		color[4];
	t_vector		final;
	int				i;
	static double	vx[4] = {0, 0.5, 0, 0.5};
	static double	vy[4] = {0, 0, 0.5, 0.5};

	env = (t_env*)param;
	limit = SCREENX * (env->line_id + 1);
	if (limit >= SCREEN)
		limit = SCREEN - 1;
	pos = env->line_id * SCREENX;
	env->line_id++;
	i = -1;
	while (++i < 4)
		ray[i].o = env->cam.pos;
	while (pos < limit)
	{
		i = -1;
		while (++i < 4)
		{
			ray[i].dir = rt_get_vecdir(env->cam, (double)(pos % SCREENX) + vx[i],
					(double)(pos / SCREENX) + vy[i]);
			color[i] = rt_viewdir_inter(env, ray[i]);
		}
	//	printf("%f %f %f %f\n", color[0].y, color[1].y, color[2].y, color[3].y);
		final.x = (color[0].x + color[1].x + color[2].x + color[3].x) / 4;
		final.y = (color[0].y + color[1].y + color[2].y + color[3].y) / 4;
		final.z = (color[0].z + color[1].z + color[2].z + color[3].z) / 4;
		rt_add_pixel(env, final, pos);
		pos++;
	}
	return (env);
}

static void			rt_thread_aa(void *env)
{
	pthread_t		id[NBR_THREAD];
	int				i;

	i = -1;
	while (++i < NBR_THREAD)
		pthread_create(&id[i], NULL, rt_print_line_aa, env);
	i = -1;
	while (++i < NBR_THREAD)
		pthread_join(id[i], NULL);
}

void				rt_antialiasing(t_env *env)
{
	static char		aliasing = 0;
	int				pos;

	if (env->offset)
		aliasing = 0;
	if (ANTI_A && !aliasing && !env->offset)
	{
		pos = 0;
		while (pos < SCREEN)
		{
			rt_thread_aa((void*)env);
			pos += SCREENX * NBR_THREAD;
		}
		mlx_put_image_to_window(env->mlx.mlx, env->mlx.id,
				env->mlx.image, 0, 0);
		aliasing = 1;
		env->line_id = 0;
		return ;
	}
}
