/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_forms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:31:40 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/19 20:04:05 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"
#include "printf.h"
#include <stdio.h>
#include "libft.h"

void		print_one_light(t_lum lum)
{
	ft_putstr("Color: ");
	print_vector(lum.color);
	ft_putstr("Center: ");
	print_vector(lum.pos);
	ft_putstr("Dir: ");
	print_vector(lum.dir);
	ft_putstr("Type: ");
	ft_putnbr(lum.type);
	ft_putstr("constant: ");
	printf("%lf\n", lum.constant);
	ft_putstr("linear: ");
	printf("%lf\n", lum.linear);
	ft_putstr("quadratic: ");
	printf("%lf\n", lum.quadratic);
}

void		print_light(t_env env)
{
	int		k;

	ft_putstr("Nombre de lights: ");
	ft_putnbr(env.nbr_lum);
	ft_putchar('\n');
	k = -1;
	ft_putstr("***__________lum____________***\n");
	while (++k < env.nbr_lum)
	{
		print_one_light(env.lum[k]);
		ft_putstr("***__________lum____________***\n");
	}
}
