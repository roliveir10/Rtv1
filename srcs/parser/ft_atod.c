/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:14:23 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/19 15:33:37 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_atod(char *value)
{
	double	div;
	double	res;
	int		k;
	int		sign;

	div = 1.0;
	res = 0;
	sign = value[0] == '-' ? -1 : 1;
	if (value[0] == '-' || value[0] == '+')
		res++;
	k = -1;
	while (ft_isdigit(value[++k]))
		res = res * 10 + value[k] - '0';
	if (value[k] == '.')
		while (ft_isdigit(value[++k]))
		{
			div = div / 10.0;
			res += div * (value[k] - '0');
		}
	return (res * sign);
}
