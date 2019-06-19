/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_basics_shapes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 15:17:43 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/18 09:35:27 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

double		rt_plan(t_ray ray, t_form form)
{
	double	dist;

	dist = -(rt_dot(form.point, ray.o)) / rt_dot(form.point, ray.dir);
	return (dist <= 0 ? -1 : dist);
}

double		rt_sphere(t_ray ray, t_form form)
{
	double	a;
	double	b;
	double	c;

	a = pow(ray.dir.x, 2) + pow(ray.dir.y, 2) + pow(ray.dir.z, 2);
	b = 2 * (ray.dir.x * ray.o.x + ray.dir.y * ray.o.y + ray.dir.z * ray.o.z);
	c = pow(ray.o.x, 2) + pow(ray.o.y, 2) + pow(ray.o.z, 2) - pow(form.r, 2);
	return (rt_resolv_nd_degre(a, b, c));
}

double			rt_cylindre(t_ray ray, t_form form)
{
	double		a;
	double		b;
	double		c;
	double		y;
	double		dist;

	a = pow(ray.dir.x, 2) + pow(ray.dir.z, 2);
	b = 2 * (ray.dir.x * ray.o.x + ray.dir.z * ray.o.z);
	c = pow(ray.o.x, 2) + pow(ray.o.z, 2) - pow(form.r, 2);
	if ((dist = rt_resolv_nd_degre(a, b, c)) == -1)
		return (dist);
	y = ray.o.y + ray.dir.y * dist;
	if (y < -form.h / 2 || y > form.h / 2)
		return (-1);
	return (dist);
}

double				rt_cone(t_ray ray, t_form form)
{
	double			a;
	double			b;
	double			c;

	(void)form;
	a = pow(ray.dir.x, 2) + pow(ray.dir.z, 2) - pow(ray.dir.y * tan(form.angle), 2);
	b = 2 * (ray.dir.x * ray.o.x + ray.dir.z * ray.o.z
			- ray.dir.y *tan(form.angle) * ray.o.y * tan(form.angle));
	c = pow(ray.o.x, 2) + pow(ray.o.z, 2) - pow(ray.o.y * tan(form.angle), 2);
	return (rt_resolv_nd_degre(a, b, c));
}
