/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vector_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:42:05 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/19 07:08:09 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector		rt_get_vecdir(t_cam cam, int x, int y)
{
	t_vector	dir;
	double		xindent;
	double		yindent;

	xindent = cam.vp_width / (double)SCREENX;
	yindent = cam.vp_height / (double)SCREENY;
	dir = rt_vsub(rt_vadd(cam.vp_upleft, rt_vmul(cam.vec_dir[0], xindent
				* (double)x)), rt_vmul(cam.vec_dir[1], yindent * (double)y));
	return (rt_normalize(dir));
}

t_vector		rt_get_posinter(t_ray ray, double dist)
{
	t_vector	inter;

	inter.x = ray.o.x + ray.dir.x * dist;
	inter.y = ray.o.y + ray.dir.y * dist;
	inter.z = ray.o.z + ray.dir.z * dist;
	return (inter);
}

t_vector		rt_get_vector(t_vector pos, t_vector inter)
{
	t_vector	vector;

	vector.x = inter.x - pos.x;
	vector.y = inter.y - pos.y;
	vector.z = inter.z - pos.z;
	return (rt_normalize(vector));
}

double			rt_dot(t_vector va, t_vector vb)
{
	double		dp;

	dp = va.x * vb.x + va.y * vb.y + va.z * vb.z;
	return (dp);
}
