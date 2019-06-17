/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 18:05:35 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/17 18:21:47 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"
#include "libft.h"

void		print_vector(t_vector vec)
{
	ft_putstr("vector: (");
	ft_putnbr(vec.x);
	ft_putstr(", ");
	ft_putnbr(vec.y);
	ft_putstr(", ");
	ft_putnbr(vec.z);
	ft_putstr(")\n");
}
