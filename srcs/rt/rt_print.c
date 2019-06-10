/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:05:07 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/10 17:36:02 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "rt.h"

static void				rt_add_pixel(t_env *env, int x, int y, t_color color)
{
	int					sline;

	sline = env->mlx.size_line;
	env->mlx.mem_image[y * (sline / 4) + x] = color.r * 255 * 255 + color.g
		* 255 + color.b;
}

void					rt_print(t_env *env)
{
	int					i;
	int					j;
	t_pos				pix;
	t_inter				inter;

	i = -1;
	while (++i < SCREENY)
	{
		j = -1;
		while (++j < SCREENX)
		{
			pix = rt_get_pospix(env->cam, j, i);
			inter = rt_browse_form(env, &(env->form), pix);

			rt_add_pixel(env, j, i, inter.color);
		}
	}
	mlx_put_image_to_window(env->mlx.mlx, env->mlx.id, env->mlx.image, 0, 0);
}
