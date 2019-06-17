/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_field_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 20:35:34 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/18 00:46:41 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"
#include "libft.h"

static int		pars_select_field(t_token **token, t_lum *light)
{
	char		*word;

	word = (*token)->word;
	if (!word)
		return (1);
	if (!(*token = (*token)->next))
		return (1);
	if (!(*token = (*token)->next))
		return (1);
	if (!ft_strcmp(word, "\"origin\""))
		light->pos = pars_vector(token);
	else if (!ft_strcmp(word, "\"color\""))
		light->color = pars_vector(token);
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
	ft_putstr((*token)->word);ft_putstr(": found this: ");
	if (pars_select_field(token, light))
		return (1);
	return (0);
}
