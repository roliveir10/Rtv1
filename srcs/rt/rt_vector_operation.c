/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vector_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 15:23:14 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/20 10:37:47 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

t_vector			rt_vmul(t_vector pos, double f)
{
	t_vector		result;

	result.x = pos.x * f;
	result.y = pos.y * f;
	result.z = pos.z * f;
	return (result);
}

t_vector			rt_vadd(t_vector pos_a, t_vector pos_b)
{
	t_vector		result;

	result.x = pos_a.x + pos_b.x;
	result.y = pos_a.y + pos_b.y;
	result.z = pos_a.z + pos_b.z;
	return (result);
}

t_vector			rt_vsub(t_vector pos_a, t_vector pos_b)
{
	t_vector		result;

	result.x = pos_a.x - pos_b.x;
	result.y = pos_a.y - pos_b.y;
	result.z = pos_a.z - pos_b.z;
	return (result);
}

t_vector			rt_vvmul(t_vector va, t_vector vb)
{
	t_vector		result;

	result.x = va.x * vb.x;
	result.y = va.y * vb.y;
	result.z = va.z * vb.z;
	return (result);
}

double				rt_dist(t_vector va, t_vector vb)
{
	t_vector		vc;

	vc = rt_vsub(va, vb);
	return (sqrt(pow(vc.x, 2) + pow(vc.y, 2) + pow(vc.z, 2)));
}
