/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:05:07 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/13 08:39:38 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "rt.h"

double					rt_clamp(double value, double lo, double hi)
{
	if (value < lo)
		return (lo);
	else if (value > hi)
		return (hi);
	else
		return (value);
}

static void				rt_add_pixel(t_env *env, t_color color, int x, int y)
{
	int					sline;
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
	unsigned int		color_rgb;

	sline = env->mlx.size_line;
	r = (unsigned char)(rt_clamp(pow(color.r, .454545), 0, 1) * 255);
	g = (unsigned char)(rt_clamp(pow(color.g, .454545), 0, 1) * 255);
	b = (unsigned char)(rt_clamp(pow(color.b, .454545), 0, 1) * 255);
	color_rgb = (r << 16) | (g << 8) | b;
	env->mlx.mem_image[y * (sline / 4) + x] = color_rgb;
}

void					rt_print(t_env *env)
{
	t_inter				inter;
	int					i;
	int					j;
	t_pos				pix;

	i = -1;
	while (++i < SCREENY)
	{
		j = -1;
		while (++j < SCREENX)
		{
			pix = rt_get_pospix(env->cam, j, i);
			inter = rt_browse_form(env, &(env->form), pix);
			rt_add_pixel(env, inter.color, j, i);
		}
	}
	mlx_put_image_to_window(env->mlx.mlx, env->mlx.id, env->mlx.image, 0, 0);
	ft_putstr("done\n");
}
