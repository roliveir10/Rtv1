/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:05:07 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/17 05:13:56 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <pthread.h>
#include "rt.h"

static double			rt_clamp(double value, double lo, double hi)
{
	if (value < lo)
		return (lo);
	else if (value > hi)
		return (hi);
	else
		return (value);
}

static void				rt_add_pixel(t_env *env, t_vector color, int pos)
{
	int					sline;
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
	unsigned int		color_rgb;

	sline = env->mlx.size_line;
	r = (unsigned char)(rt_clamp(pow(color.x, .454545), 0, 1) * 255);
	g = (unsigned char)(rt_clamp(pow(color.y, .454545), 0, 1) * 255);
	b = (unsigned char)(rt_clamp(pow(color.z, .454545), 0, 1) * 255);
	color_rgb = (r << 16) | (g << 8) | b;
	env->mlx.mem_image[pos] = color_rgb;
}

static void					*rt_print_line(void *env)
{
	static int				line = 0;
	t_ray					ray;
	int						pos;
	int						limit;
	t_vector				color;

	limit = line * SCREENX + SCREENX;
	pos = line * SCREENX;
	line++;
	ray.o = ((t_env*)env)->cam.pos;
	while (pos < limit)
	{
		ray.dir = rt_get_vecdir(((t_env*)env)->cam, pos % SCREENX, pos / SCREENX);
		color = rt_browse_form((t_env*)env, ray);
		rt_add_pixel((t_env*)env, color, pos);
		pos++;
	}
	return (env);
}

void						rt_print(t_env *env)
{
	int						pos;
	pthread_t				id[NBR_THREAD];
	int						i;

	pos = 0;
	while (pos < SCREENX * SCREENY)
	{
		i = -1;
		while (++i < NBR_THREAD)
			pthread_create(&id[i], NULL, rt_print_line, (void*)env);
		i = -1;
		while (++i < NBR_THREAD)
			pthread_join(id[i], NULL);
		pos += SCREENX * NBR_THREAD;
	}
	mlx_put_image_to_window(env->mlx.mlx, env->mlx.id, env->mlx.image, 0, 0);
}
