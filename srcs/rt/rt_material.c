/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_material.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 01:26:51 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/20 10:08:52 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void				rt_attr_material(t_vector *v, double a, double b,
		double c)
{
	v->x = a;
	v->y = b;
	v->z = c;
}

static t_material		rt_mat_nothing(t_scene scene)
{
	t_material			mat;

	rt_attr_material(&mat.ambient, scene.ambient, scene.ambient, scene.ambient);
	rt_attr_material(&mat.diffuse, 0.5, 0.5, 0.5);
	rt_attr_material(&mat.specular, scene.spec, scene.spec, scene.spec);
	mat.shininess = 1;
	return (mat);
}

t_material				rt_get_material(t_ematerial emat, t_scene scene)
{
	static int			mat_tab[NBR_MATERIAL] = {NOTHING};
	static t_material	(*func[NBR_MATERIAL])(t_scene) = {
		rt_mat_nothing};
	int					i;

	i = -1;
	while (++i < NBR_MATERIAL)
		if (emat == mat_tab[i])
			return (func[i](scene));
	return (func[0](scene));
}
