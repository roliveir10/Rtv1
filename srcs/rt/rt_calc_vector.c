/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_calc_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:42:05 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/10 13:32:20 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_pos			rt_get_pospix(t_cam cam, int x, int y)
{
	t_pos		pos;
	double		xindent;
	double		yindent;

	xindent = cam.vp_width / (double)SCREENX;
	yindent = cam.vp_height / (double)SCREENY;
	pos = rt_vsub(rt_vadd(cam.vp_upleft, rt_vmul(cam.vec_dir[0], xindent
				* (double)x)), rt_vmul(cam.vec_dir[1], yindent * (double)y));
	return (pos);
}

void			rt_get_posinter(t_pos o, t_pos pix, t_inter *inter)
{
	inter->x = o.x + pix.x * inter->t;
	inter->y = o.y + pix.y * inter->t;
	inter->z = o.z + pix.z * inter->t;
}

t_pos			rt_get_vector(t_pos inter, t_pos pos)
{
	t_pos		vector;

	vector.x = pos.x - inter.x;
	vector.y = pos.y - inter.y;
	vector.z = pos.z - inter.z;
	return (rt_normalize(vector));
}

double			rt_dot_product(t_pos va, t_pos vb)
{
	double		dp;

	dp = va.x * vb.x + va.y * vb.y + va.z * vb.z;
	return (dp);
}
