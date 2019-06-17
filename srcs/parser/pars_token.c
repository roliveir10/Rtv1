/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 17:12:49 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/17 20:10:26 by oboutrol         ###   ########.fr       */
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
	int		ret;

	ret = 1;
	if (!token)
		return (NULL);
	if (!(env = (t_env*)ft_memalloc(sizeof(t_env))))
		return (NULL);
	if (token->type != CBRO)
		return (null_error("rt: JSON file should start with `{'\n"));
	token = token->next;
	while ((ret = pars_type(&token, env)))
	{
		if (ret == -1)
			return (NULL);
		if (!token || token->type != ENDED)
			return (NULL);
		token = token->next;
	}
	return (NULL);
}
