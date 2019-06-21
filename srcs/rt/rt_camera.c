/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 04:16:17 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/20 09:45:50 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			rt_update_campos(t_cam *cam)
{
	t_vector	vx;
	t_vector	vy;
	t_vector	vz;

	vz = rt_vmul(cam->vec_dir[2], cam->vp_dist);
	vy = rt_vmul(cam->vec_dir[1], cam->vp_height / 2.0);
	vx = rt_vmul(cam->vec_dir[0], cam->vp_width / 2.0);
	cam->vp_upleft.x = cam->pos.x + vz.x + vy.x - vx.x;
	cam->vp_upleft.y = cam->pos.y + vz.y + vy.y - vx.y;
	cam->vp_upleft.z = cam->pos.z + vz.z + vy.z - vx.z;
}

void			rt_update_camrot(t_cam *cam, double mat[3][3][3])
{
	int			i;

	i = -1;
	while (++i < 3)
	{
		rt_vect_rotation(&cam->vec_dir[0], mat[i]);
		rt_vect_rotation(&cam->vec_dir[1], mat[i]);
		rt_vect_rotation(&cam->vec_dir[2], mat[i]);
	}
	rt_update_campos(cam);
}
