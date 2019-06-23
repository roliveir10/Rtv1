/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 04:57:13 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/23 09:32:17 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

void		rt_set_ref(t_ray *ray, t_form form)
{
	int		i;

	i = -1;
	ray->o = ft_vsub(form.center, ray->o);
	while (++i < 3)
	{
		ray->dir = ft_vrotate(ray->dir, form.mat[i]);
		ray->o = ft_vrotate(ray->o, form.mat[i]);
	}
}

void		rt_reset_point(t_form form, t_vector *inte)
{
	int		i;

	i = 3;
	while (--i + 1)
		*inte = ft_vrotate(*inte, form.mati[i]);
	*inte = ft_vadd(*inte, form.center);
}

void		rt_initialize_rotation(t_form **form, int nbr_form)
{
	int		i;

	i = -1;
	while (++i < nbr_form)
	{
		ft_fmat(&(*form)[i].mat, (*form)[i].rotation, 1);
		ft_fmat(&(*form)[i].mati, (*form)[i].rotation, -1);
	}
}
