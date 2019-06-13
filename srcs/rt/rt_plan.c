/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_plan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 14:23:22 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/13 07:45:24 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

void			rt_plan(t_pos o, t_pos pix, t_form form, t_inter *inter)
{
	t_pos		vec;

	inter->out = 0;
	vec = rt_get_vector(form.center, o);
	inter->t = -((form.point.x * vec.x + form.point.y
				* vec.y + form.point.z * vec.z)
		/ (form.point.x * pix.x + form.point.y * pix.y + form.point.z
			* pix.z));
	if (inter->t <= 0)
	{
		inter->out = 1;
		return ;
	}
	inter->color = form.color;
	rt_get_posinter(o, pix, inter);
}
