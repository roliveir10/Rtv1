/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:57:56 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/19 08:48:42 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"
#include "mlx.h"

void				rt_delenv(t_env *env)
{
	mlx_destroy_image(env->mlx.mlx, env->mlx.image);
	if (env->form)
		ft_memdel((void**)&env->form);
	if (env->lum)
		ft_memdel((void**)&env->lum);
	exit(1);
}

static void			rt_initmlx(t_env *env)
{
	env->mlx.mlx = mlx_init();
	env->mlx.image = mlx_new_image(env->mlx.mlx, SCREENX, SCREENY);
	env->mlx.id = mlx_new_window(env->mlx.mlx, SCREENX, SCREENY, "rt");
	env->mlx.mem_image = (unsigned int*)mlx_get_data_addr(env->mlx.image,
			&env->mlx.pix, &env->mlx.size_line, &env->mlx.endian);
}

int					rt_main(t_env *env)
{
	rt_initmlx(env);
	rt_print(env);
	mlx_hook(env->mlx.id, KEYPRESS, 0, rt_keypress, (void*)env);
	mlx_hook(env->mlx.id, REDBUTTON, 0, rt_close, (void*)env);
	mlx_loop(env->mlx.mlx);
	return (1);
}
