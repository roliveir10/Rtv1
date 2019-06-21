/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_material.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:55:27 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/19 18:48:27 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

static int		pars_select_mat(t_token **token, t_material *mat)
{
	char		*word;

	if (!(word = (*token)->word))
		return (1);
	if (!(*token = (*token)->next))
		return (1);
	if (!(*token = (*token)->next))
		return (1);
	if (!ft_strcmp("\"specular\"", word))
		mat->specular = pars_vector(token);
	if (!ft_strcmp("\"ambient\"", word))
		mat->ambient = pars_vector(token);
	if (!ft_strcmp("\"diffuse\"", word))
		mat->diffuse = pars_vector(token);
	if (!ft_strcmp("\"shininess\"", word))
		mat->shininess = pars_double(token);
	return (0);
}

int				pars_field_mat(t_token **token, t_material *mat)
{
	if ((*token)->type != NAMES)
	{
		ft_putstr_fd("rt: wrong format for material definition\n", 2);
		return (-1);
	}
	if (pars_select_mat(token, mat))
	{
		ft_putstr_fd("rt: invalid field for material\n", 2);
		return (-1);
	}
	return (0);
}

t_material		pars_material(t_token **token)
{
	t_material	mat;
	char		*word;
	
	ft_bzero(&mat, sizeof(t_material));
	if (!(word = (*token)->word))
		return (mat);
	ft_putstr("setting matterials for: ");
	ft_putstr(word);
	ft_putstr("\n");
	/*
	while (pars_field_mat(token, &mat) != -1)
	{
		if (!(*token) || (*token)->type != ENDED)
			break;
		*token = (*token)->next;
	}
	*/
	if (*token)
		*token = (*token)->next;
	return (mat);
}
