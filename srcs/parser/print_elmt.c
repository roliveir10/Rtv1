/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 18:05:35 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/19 15:11:38 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"
#include "libft.h"
#include <stdio.h>

void		print_vector(t_vector vec)
{
	printf("vector: (%f, %f, %f)\n", vec.x, vec.y, vec.z);
}
