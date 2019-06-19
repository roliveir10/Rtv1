/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_basics_shapes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 15:17:43 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/19 08:36:21 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

double			rt_resolv_nd_degre(double a, double b, double c)
{
	double		t1;
	double		t2;
	double		delta;

	if ((delta = pow(b, 2) - 4 * a * c) < 0)
		return (-1);
	t1 = (-b + sqrt(delta)) / (2.0 * a);
	if (!delta)
	{
		return (t1 > 0 ? t1 : -1);
	}
	t2 = (-b - sqrt(delta)) / (2.0 * a);
	if (t1 <= 0 && t2 > 0)
		return (t2);
	if (t1 > 0 && t2 <= 0)
		return (t1);
	return (t1 > t2 ? t2 : t1);
}

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

	a = rt_dot(ray.dir, ray.dir);
	b = 2 * rt_dot(ray.dir, ray.o);
	c = rt_dot(ray.o, ray.o) - pow(form.r, 2);
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
	if ((dist = rt_resolv_nd_degre(a, b, c)) < 0)
		return (-1);
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
	a = pow(ray.dir.x, 2) + pow(ray.dir.z, 2)
		- pow(ray.dir.y * tan(form.angle), 2);
	b = 2 * (ray.dir.x * ray.o.x + ray.dir.z * ray.o.z
			- ray.dir.y * tan(form.angle) * ray.o.y * tan(form.angle));
	c = pow(ray.o.x, 2) + pow(ray.o.z, 2) - pow(ray.o.y * tan(form.angle), 2);
	return (rt_resolv_nd_degre(a, b, c));
}
