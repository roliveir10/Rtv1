/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:17:08 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/11 00:30:51 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

#include <stdio.h>

void				rt_attribute_color(int color, t_color *s_color)
{
	s_color->r = (double)(color >> 16 & 0xFF) / 255;
	s_color->g = (double)(color >> 8 & 0xFF) / 255;
	s_color->b = (double)(color & 0xFF) / 255;
}
