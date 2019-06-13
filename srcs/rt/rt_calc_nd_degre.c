/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_calc_nd_degre.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 12:58:43 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/12 07:17:38 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"


static t_solve		rt_resolv_nd_degre(double a, double b, double c, char *out)
{
	double			delta;
	t_solve			solve;

	ft_bzero(&solve, sizeof(t_solve));
	if ((delta = pow(b, 2) - 4 * a * c) < 0)
	{
		*out = 1;
		return (solve);
	}
	solve.ta = (-b + sqrt(delta)) / (2.0 * a);
	if (!delta)
	{
		solve.tb = solve.ta;
		return (solve);
	}
	solve.tb = (-b - sqrt(delta)) / (2.0 * a);
	return (solve);
}

double				rt_get_t(double a, double b, double c, char *out)
{
	t_solve			solve;
	double			t;

	solve = rt_resolv_nd_degre(a, b, c, out);
	if (*out)
		return (0);
	if (solve.ta < 0 && solve.tb < 0)
	{
		*out = 1;
		return (0);
	}
	else if (solve.ta < 0 && solve.tb > 0)
		t = solve.tb;
	else if (solve.tb < 0 && solve.ta > 0)
		t = solve.ta;
	else
		t = solve.ta > solve.tb ? solve.tb : solve.ta;
	return (t);
}

