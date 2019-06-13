/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_calc_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 20:42:41 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/13 07:43:22 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

static t_pos			rt_norm_sphere(t_inter inter, t_form form)
{
	t_pos				norm;

	(void)form;
	norm.x = inter.x;
	norm.y = inter.y;
	norm.z = inter.z;
	return (rt_normalize(norm));
}

static t_pos			rt_norm_plan(t_inter inter, t_form form)
{
	t_pos				norm;

	(void)inter;
	norm.x = form.point.x;
	norm.y = form.point.y;
	norm.z = form.point.z;
	return (rt_normalize(norm));
}

static t_pos			rt_norm_cylindre(t_inter inter, t_form form)
{
	t_pos				norm;
	double				px;
	double				pz;

	px = inter.x - form.center.x;
	pz = inter.z - form.center.z;
	norm.x = form.r * (px / (sqrt(pow(px, 2) + pow(pz, 2))));
	norm.z = form.r * (pz / (sqrt(pow(px, 2) + pow(pz, 2))));
	norm.y = 0.0;
	return (rt_normalize(norm));
}

static t_pos			rt_norm_cone(t_inter inter, t_form form)
{
	t_pos				norm;
	double				px;
	double				pz;
	double				neg;

	px = inter.x - form.center.x;
	pz = inter.z - form.center.z;
	neg = (inter.y - form.center.y) < 0 ? -1 : 1;
	norm.x = px * cos(form.angle);
	norm.z = pz * cos(form.angle);
	norm.y = sin(form.angle) * (-neg);
	return (rt_normalize(norm));
}

t_pos					rt_normalize(t_pos vector)
{
	double				r;
	t_pos				pos;

	ft_bzero(&pos, sizeof(t_pos));
	r = sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
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
		rt_norm_sphere, rt_norm_plan, rt_norm_cylindre, rt_norm_cone};
	
	return (lst_function[form.ftype](inter, form));
}
