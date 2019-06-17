/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vector_normal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 20:42:41 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/15 21:03:42 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

static t_vector			rt_norm_sphere(t_vector pos, t_form form)
{
	t_vector				norm;

	(void)form;
	norm.x = pos.x;
	norm.y = pos.y;
	norm.z = pos.z;
	return (rt_normalize(norm));
}

static t_vector			rt_norm_plan(t_vector pos, t_form form)
{
	t_vector				norm;

	(void)pos;
	norm.x = form.point.x;
	norm.y = form.point.y;
	norm.z = form.point.z;
	return (rt_normalize(norm));
}

static t_vector			rt_norm_cylindre(t_vector pos, t_form form)
{
	t_vector				norm;
	double				px;
	double				pz;

	px = pos.x;
	pz = pos.z;
	norm.x = form.r * (px / (sqrt(pow(px, 2) + pow(pz, 2))));
	norm.z = form.r * (pz / (sqrt(pow(px, 2) + pow(pz, 2))));
	norm.y = 0.0;
	return (rt_normalize(norm));
}

static t_vector			rt_norm_cone(t_vector pos, t_form form)
{
	t_vector				norm;
	double				px;
	double				pz;
	double				neg;

	px = pos.x;
	pz = pos.z;
	neg = pos.y < 0 ? -1 : 1;
	norm.x = px * cos(form.angle);
	norm.z = pz * cos(form.angle);
	norm.y = sin(form.angle) * (-neg);
	return (rt_normalize(norm));
}

t_vector					rt_normalize(t_vector vector)
{
	double				r;
	t_vector				pos;

	ft_bzero(&pos, sizeof(t_vector));
	r = sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
	if (!r)
		return (pos);
	pos.x = vector.x / r;
	pos.y = vector.y / r;
	pos.z = vector.z / r;
	return (pos);
}

t_vector					rt_get_normal(t_vector pos, t_form form)
{
	static t_vector		(*func[NBR_FORM])(t_vector, t_form) = {
		rt_norm_sphere, rt_norm_plan, rt_norm_cylindre, rt_norm_cone};
	
	return (func[form.ftype](pos, form));
}
