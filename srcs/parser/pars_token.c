/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 17:12:49 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/22 01:31:55 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

t_env		token_to_env(t_token *token)
{
	t_env	env;
	int		ret;

	ret = 1;
	ft_bzero(&env, sizeof(t_env));
	if (!token)
		return (env);
	if (token->type != CBRO)
	{
		ft_putstr_fd("rt: JSON file should start with `{'\n", 2);
		return (env);
	}
	token = token->next;
	while ((ret = pars_type(&token, &env)))
	{
		if (ret == -1)
			return (env);
		if (!token || token->type != ENDED)
			return (env);
		token = token->next;
	}
	return (env);
}
