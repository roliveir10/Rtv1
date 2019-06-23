/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 02:11:36 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/23 16:03:35 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"
#include "libft.h"

int					pars_camera(t_token **token, t_env *env)
{
	free_move(token);
	if (free_move(token))
		return (-1);
	if ((*token)->type == BRAO)
	{
		ft_putstr_fd("rt: Only one camera expected, remove lst\n", 2);
		return (-1);
	}
	free_move(token);
	while (pars_field_camera(token, env) != -1)
	{
		if (!(*token) || (*token)->type != ENDED)
			break ;
		free_move(token);
	}
	free_move(token);
	return (1);
}
