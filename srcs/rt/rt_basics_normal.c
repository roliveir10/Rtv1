/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_basics_normal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 20:42:41 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/20 10:00:22 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

static t_vector			rt_norm_sphere(t_vector pos, t_form form)
{
	(void)form;
	return (rt_normalize(pos));
}

static t_vector			rt_norm_plan(t_vector pos, t_form form)
{
	(void)pos;
	return (rt_normalize(form.point));
}

static t_vector			rt_norm_cylindre(t_vector pos, t_form form)
{
	t_vector			norm;

	norm.x = form.r * (pos.x / (sqrt(pow(pos.x, 2) + pow(pos.z, 2))));
	norm.z = form.r * (pos.z / (sqrt(pow(pos.x, 2) + pow(pos.z, 2))));
	norm.y = 0.0;
	return (rt_normalize(norm));
}

static t_vector			rt_norm_cone(t_vector pos, t_form form)
{
	t_vector			norm;
	double				neg;

	neg = pos.y < 0 ? 1 : -1;
	norm.x = pos.x * cos(form.angle);
	norm.z = pos.z * cos(form.angle);
	norm.y = sin(form.angle) * neg;
	return (rt_normalize(norm));
}

t_vector				rt_get_normal(t_vector pos, t_form form)
{
	static t_vector		(*func[NBR_FORM])(t_vector, t_form) = {
		rt_norm_sphere, rt_norm_plan, rt_norm_cylindre, rt_norm_cone};

	return (func[form.ftype](pos, form));
}
