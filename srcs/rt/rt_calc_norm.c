/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_calc_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 20:42:41 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/10 18:34:44 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

static t_pos			rt_norm_sphere(t_inter inter, t_form form)
{
	t_pos				norm;

	norm.x = inter.x - form.center.x;
	norm.y = inter.y - form.center.y;
	norm.z = inter.z - form.center.z;
	return (rt_normalize(norm));
}

static t_pos			rt_norm_plan(t_inter inter, t_form form)
{
	t_pos				norm;

	(void)inter;
	norm.x = form.center.x;
	norm.y = form.center.y;
	norm.z = form.center.z;
	return (rt_normalize(norm));
}

t_pos					rt_normalize(t_pos vector)
{
	double				r;
	t_pos				pos;

	ft_bzero(&pos, sizeof(t_pos));
	r = sqrt(powf(vector.x, 2) + powf(vector.y, 2) + powf(vector.z, 2));
	if (!r)
		return (pos);
	pos.x = vector.x / r;
	pos.y = vector.y / r;
	pos.z = vector.z / r;
	return (pos);
}

t_pos					rt_get_normal(t_inter inter, t_form form)
{
	static t_pos		(*lst_function[NBR_FORM])(t_inter, t_form) = {
		rt_norm_sphere, rt_norm_plan};
	
	return (lst_function[form.ftype](inter, form));
}
