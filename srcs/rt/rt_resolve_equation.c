/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_resolve_equation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 12:58:43 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/18 00:19:12 by roliveir         ###   ########.fr       */
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
	if (t1 < 0 && t2 < 0)
		return (-1);
	return (t1 > t2 ? t2 : t1);
}
