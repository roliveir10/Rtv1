/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_add_mul_sub_vector.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 21:08:20 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/10 13:13:56 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_pos			rt_vmul(t_pos pos, double f)
{
	t_pos		result;

	result.x = pos.x * f;
	result.y = pos.y * f;
	result.z = pos.z * f;
	return (result);
}

t_pos			rt_vadd(t_pos pos_a, t_pos pos_b)
{
	t_pos		result;

	result.x = pos_a.x + pos_b.x;
	result.y = pos_a.y + pos_b.y;
	result.z = pos_a.z + pos_b.z;
	return (result);
}

t_pos			rt_vsub(t_pos pos_a, t_pos pos_b)
{
	t_pos		result;

	result.x = pos_a.x - pos_b.x;
	result.y = pos_a.y - pos_b.y;
	result.z = pos_a.z - pos_b.z;
	return (result);
}
