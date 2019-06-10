/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_plan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 14:23:22 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/10 13:47:52 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

void			rt_plan(t_pos o, t_pos pix, t_form form, t_inter *inter)
{
	double		x;
	double		y;
	double		z;

	inter->out = 0;
	x = o.x - form.point.x;
	y = o.y - form.point.y;
	z = o.z - form.point.z;
	inter->t = -(form.center.x * x + form.center.y * y + form.center.z * z)
		/ (form.center.x * pix.x + form.center.y * pix.y + form.center.z
			* pix.z);
	inter->color = form.color;
	if (inter->t <= 0)
		inter->out = 1;
	rt_get_posinter(o, pix, inter);
}
