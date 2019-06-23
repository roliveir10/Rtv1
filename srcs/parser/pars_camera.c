/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 02:11:36 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/23 02:13:25 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"
#include "libft.h"

int					pars_camera(t_token **token, t_env *env)
{
	*token = (*token)->next;
	if (!(*token = (*token)->next))
		return (-1);
	if ((*token)->type == BRAO)
	{
		ft_putstr_fd("rt: Only one camera expected, remove lst\n", 2);
		return (-1);
	}
	*token = (*token)->next;
	while (pars_field_camera(token, env) != -1)
	{
		if (!(*token) || (*token)->type != ENDED)
			break ;
		*token = (*token)->next;
	}
	if (*token)
		*token = (*token)->next;
	return (1);
}
