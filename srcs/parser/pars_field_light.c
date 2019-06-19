/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_field_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 20:35:34 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/19 20:04:04 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"
#include "libft.h"

static int		pars_name_light(t_token **token)
{
	int			type;
	char		*word;

	type = 0;
	if (!(word = (*token)->word))
		return (0);
	if (!ft_strcmp(word, "\"spot\""))
		type = LSPOT;
	else if (!ft_strcmp(word, "\"cast\""))
		type = LCAST;
	else if (!ft_strcmp(word, "\"point\""))
		type = LPOINT;
	*token = (*token)->next;
	return (type);
}

static int		pars_select_field(t_token **token, t_lum *light)
{
	char		*word;

	ft_putstr("oane\n");
	word = (*token)->word;
	if (!word)
		return (1);
	if (!(*token = (*token)->next))
		return (1);
	if (!(*token = (*token)->next))
		return (1);
	if (!ft_strcmp(word, "\"origin\""))
	{
		light->pos = pars_vector(token);
		print_vector(light->color);
	}
	else if (!ft_strcmp(word, "\"color\""))
	{
		light->color = pars_vector_color(token);
		print_vector(light->color);
	}
	else if (!ft_strcmp(word, "\"direct\""))
		light->dir = pars_vector(token);
	else if (!ft_strcmp(word, "\"constant\""))
		light->constant = pars_double(token);
	else if (!ft_strcmp(word, "\"linear\""))
		light->linear = pars_double(token);
	else if (!ft_strcmp(word, "\"quadratic\""))
		light->quadratic = pars_double(token);
	else if (!ft_strcmp(word, "\"type\""))
		light->type = pars_name_light(token);
	else
	{
		ft_putstr_fd("rt: invalid field: ", 2);
		ft_putstr_fd(word, 2);
		ft_putstr_fd(" in type `light'\n", 2);
		return (1);
	}
	return (0);
}

int				pars_field_light(t_token **token, t_lum *light)
{
	if ((*token)->type != NAMES)
	{
		ft_putstr_fd("rt: wrong format for light definition\n", 2);
		return (1);
	}
	if (pars_select_field(token, light))
		return (1);
	return (0);
}
