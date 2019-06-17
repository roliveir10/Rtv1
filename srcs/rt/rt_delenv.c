/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_delenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:29:53 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/17 05:13:49 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "rt.h"

int					rt_delenv(t_env *env)
{
	mlx_destroy_image(env->mlx.mlx, env->mlx.image);
	if (env->form)
		ft_memdel((void**)&env->form);
	if (env->form)
		ft_memdel((void**)&env->lum);
	exit(1);
	return (0);
}
