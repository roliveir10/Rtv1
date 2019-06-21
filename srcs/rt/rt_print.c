/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:05:07 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/22 00:58:16 by roliveir         ###   ########.fr       */
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
	unsigned char		rgb[3];
	unsigned int		color_rgb;
	int					size;

	size = -1;
	rgb[0] = (unsigned char)(rt_clamp(pow(color.x, .454545), 0, 1) * 255);
	rgb[1] = (unsigned char)(rt_clamp(pow(color.y, .454545), 0, 1) * 255);
	rgb[2] = (unsigned char)(rt_clamp(pow(color.z, .454545), 0, 1) * 255);
	color_rgb = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	pos -= env->offset;
	while (++size < env->offset)
	{
		env->mlx.mem_image[pos + size] = color_rgb;
		if (pos - size + SCREENX < SCREENX * SCREENY)
			env->mlx.mem_image[pos + size + SCREENX] = color_rgb;
	}
}

static void				*rt_print_line(void *env)
{
	int					line;
	t_ray				ray;
	int					pos;
	int					limit;
	t_vector			color;

	((t_env*)env)->line_id += ((t_env*)env)->offset;
	line = ((t_env*)env)->line_id - ((t_env*)env)->offset;
	limit = SCREENX * (line + ((t_env*)env)->offset);
	if (limit >= SCREENX * SCREENY)
		limit = SCREENX * SCREENY - 1;
	pos = line * SCREENX + ((t_env*)env)->offset;
	ray.o = ((t_env*)env)->cam.pos;
	while (pos < limit)
	{
		ray.dir = rt_get_vecdir(((t_env*)env)->cam, pos % SCREENX,
				pos / SCREENX);
		color = rt_viewdir_inter((t_env*)env, ray);
		rt_add_pixel((t_env*)env, color, pos);
		if (((t_env*)env)->offset == PIX)
			pos += PIX;
		else
			pos += ((t_env*)env)->offset * 2;
	}
	return (env);
}

int						rt_print(void *env)
{
	int					pos;
	pthread_t			id[NBR_THREAD];
	int					i;

	if (((t_env*)env)->offset)
	{
		pos = 0;
		while (pos < SCREENX * SCREENY)
		{
			i = -1;
			while (++i < NBR_THREAD)
				pthread_create(&id[i], NULL, rt_print_line, (void*)env);
			i = -1;
			while (++i < NBR_THREAD)
				pthread_join(id[i], NULL);
			pos += SCREENX * NBR_THREAD * ((t_env*)env)->offset;
		}
		((t_env*)env)->offset /= 2;
		mlx_put_image_to_window(((t_env*)env)->mlx.mlx, ((t_env*)env)->mlx.id,
				((t_env*)env)->mlx.image, 0, 0);
		((t_env*)env)->line_id = 0;
		return (1);
	}
	return (0);
}
