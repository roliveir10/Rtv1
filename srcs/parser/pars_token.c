/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 17:12:49 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/17 16:25:50 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

void		*null_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (NULL);
}

t_env		*token_to_env(t_token *token)
{
	t_env	*env;

	if (!token)
		return (NULL);
	if (!(env = (t_env*)ft_memalloc(sizeof(t_env))))
		return (NULL);
	if (token->type != CBRO)
		return (null_error("rt: JSON file should start with `{'\n"));
	if (pars_type(token->next, env) == -1)
		return (NULL);
	return (NULL);
}
