/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_forms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:31:40 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/19 20:04:06 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"
#include "printf.h"
#include <stdio.h>
#include "libft.h"

void		print_material(t_material material)
{
	ft_putstr("-- Material --\n");
	ft_putstr("Specular: ");
	print_vector(material.specular);
	ft_putstr("Ambient: ");
	print_vector(material.ambient);
	ft_putstr("Diffuse: ");
	print_vector(material.diffuse);
	ft_putstr("Shininess: ");
	printf("%f\n", material.shininess);
}

void		print_one_form(t_form form)
{
	ft_putstr("Color: ");
	print_vector(form.color);
	ft_putstr("Center: ");
	print_vector(form.center);
	ft_putstr("Point: ");
	print_vector(form.point);
	ft_putstr("Direct: ");
	print_vector(form.direct);
	ft_putstr("Rayon: ");
	printf("%lf\n", form.r);
	ft_putstr("height: ");
	printf("%lf\n", form.h);
	ft_putstr("angle: ");
	printf("%lf\n", form.angle);
	print_material(form.material);
}

void		print_form(t_env env)
{
	int		k;

	ft_putstr("Nombre de formes: ");
	ft_putnbr(env.nbr_form);
	ft_putstr("\nNombre de lights: ");
	ft_putnbr(env.nbr_lum);
	ft_putchar('\n');
	k = -1;
	ft_putstr("+++__________form___________+++\n");
	while (++k < env.nbr_form)
	{
		print_one_form(env.form[k]);
		ft_putstr("+++_________form____________+++\n");
	}
}
