/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 21:28:25 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/10 09:41:32 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

void			rt_sphere(t_pos o, t_pos pix, t_form form, t_inter *inter)
{
	float		a;
	float		b;
	float		c;

	a = powf(pix.x, 2) + powf(pix.y, 2) + powf(pix.z, 2);
	b = 2 * (pix.x * (o.x - form.center.x)
			+ pix.y * (o.y - form.center.y)
			+ pix.z * (o.z - form.center.z));
	c = powf(o.x - form.center.x, 2)
		+ powf(o.y - form.center.y, 2)
		+ powf(o.z - form.center.z, 2)
		- powf(form.r, 2);
	inter->out = 0;
	inter->t = rt_resolv_nd_degre(a, b, c, &inter->out);
	rt_get_posinter(o, pix, inter);
	inter->color = form.color;
}
