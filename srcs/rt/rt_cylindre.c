/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_cylindre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 05:06:10 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/12 21:20:16 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

void			rt_cylindre(t_pos o, t_pos pix, t_form form, t_inter *inter)
{
	double		a;
	double		b;
	double		c;
	double		y;

	a = pow(pix.x, 2) + pow(pix.z, 2);
	b = 2 * (pix.x * (o.x - form.center.x) + pix.z * (o.z - form.center.z));
	c = pow(o.x - form.center.x, 2) + pow(o.z - form.center.z, 2)
		- pow(form.r, 2);
	inter->out = 0;
	inter->t = rt_get_t(a, b, c, &inter->out);
	if (inter->out)
		return ;
	y = o.y + pix.y * inter->t - form.center.y;
	if (y < -form.h / 2 || y > form.h / 2)
	{
		inter->out = 1;
		return ;
	}
	inter->color = form.color;
	rt_get_posinter(o, pix, inter);
}
