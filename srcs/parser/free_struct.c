/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:13:35 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/12 00:00:24 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"
#include <stdlib.h>

void		free_token(t_token *token)
{
	if (!token)
		return ;
	free_token(token->next);
	ft_strdel(&(token->word));
	free(token);
}
