/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_calc_nd_degre.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 12:58:43 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/10 18:37:57 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

double				rt_resolv_nd_degre(double a, double b, double c, char *out)
{
	double			delta;
	double			ra;
	double			rb;

	if ((delta = powf(b, 2) - 4 * a * c) < 0)
	{
		*out = 1;
		return (0);
	}
	ra = (-b + sqrt(delta) / (2 * a));
	rb = (-b - sqrt(delta) / (2 * a));
	return (ra < rb ? ra : rb);
}
