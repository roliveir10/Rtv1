/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 21:28:25 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/13 03:27:09 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

#include <stdio.h>

void			rt_sphere(t_pos o, t_pos pix, t_form form, t_inter *inter)
{
	double		a;
	double		b;
	double		c;
	
	a = pow(pix.x, 2) + pow(pix.y, 2) + pow(pix.z, 2);
	b = 2 * (pix.x * o.x + pix.y * o.y + pix.z * o.z);
	c = pow(o.x, 2) + pow(o.y, 2) + pow(o.z, 2) - pow(form.r, 2);
	inter->out = 0;
	if (!(inter->t = rt_get_t(a, b, c, &inter->out)))
		return ;
	inter->color = form.color;
	rt_get_posinter(o, pix, inter);
}
