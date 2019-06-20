/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vector_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:42:05 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/20 02:33:23 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
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
	return (rt_vadd(ray.o, rt_vmul(ray.dir, dist)));
}

t_vector		rt_get_vector(t_vector va, t_vector vb)
{
	return (rt_normalize(rt_vsub(vb, va)));
}

double			rt_dot(t_vector va, t_vector vb)
{
	return (va.x * vb.x + va.y * vb.y + va.z * vb.z);
}

double			rt_dist(t_vector va, t_vector vb)
{
	t_vector	vc;

	vc = rt_vsub(va, vb);
	return (sqrt(pow(vc.x, 2) + pow(vc.y, 2) + pow(vc.z, 2)));
}
