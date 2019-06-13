/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_cone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 01:56:50 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/12 04:09:13 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

void			rt_cone(t_pos o, t_pos pix, t_form form, t_inter *inter)
{
	double		a;
	double		b;
	double		c;
	double		y;

	a = pow(pix.x, 2) + pow(pix.z, 2) - pow(pix.y, 2);
	b = 2 * (pix.x * (o.x - form.center.x) + pix.z * (o.z - form.center.z)
			- pix.y * (o.y - form.center.y));
	c = pow(o.x - form.center.x, 2) + pow(o.z - form.center.z, 2)
		- pow(o.y - form.center.y, 2);
	inter->out = 0;
	inter->t = rt_get_t(a, b, c, &inter->out);
	if (inter->out)
		return ;
	y = o.y + pix.y * inter->t - form.center.y;
	if (y > 0)
	{
		inter->out = 1;
		return ;
	}
	inter->color = form.color;
	rt_get_posinter(o, pix, inter);
}
