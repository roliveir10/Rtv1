/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_field_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:20:16 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/19 15:24:55 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"
#include "libft.h"

static int		pars_select_field(t_token **token, t_env *env)
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
		env->cam.pos = pars_vector(token);
	else if (!ft_strcmp(word, "\"vect_n\""))
		env->cam.vec_dir[0] = pars_vector(token);
	else
	{
		ft_putstr_fd("rt: invalid field: ", 2);
		ft_putstr_fd(word, 2);
		ft_putstr_fd(" in type `camera'\n", 2);
		return (1);
	}
	return (0);
}

int				pars_field_camera(t_token **token, t_env *env)
{
	if ((*token)->type != NAMES)
	{
		ft_putstr_fd("rt: wrong format for camera definition\n", 2);
		return (1);
	}
	if (pars_select_field(token, env))
		return (1);
	return (0);
}
