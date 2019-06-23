/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 03:48:17 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/23 04:11:19 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"
#include <stdlib.h>

int				free_move(t_token **token)
{
	t_token		*tmp;

	if (!token || !(*token))
		return (1);
	tmp = *token;
	if (!(*token = (*token)->next))
		return (1);
	free_token(&tmp);
	return (0);
}

int				free_double_move(t_token **token)
{
	if (free_move(token) || free_move(token))
		return (1);
	return (0);
}
