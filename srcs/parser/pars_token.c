/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 17:12:49 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/23 22:33:28 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

t_env		token_to_env(t_token **token)
{
	t_env	env;
	int		ret;

	ret = 1;
	ft_bzero(&env, sizeof(t_env));
	env.scene.spec = 0.5;
	env.scene.ambient = 0.1;
	if (!token || !(*token))
		return (env);
	if ((*token)->type != CBRO)
	{
		ft_putstr_fd("rt: JSON file should start with `{'\n", 2);
		return (env);
	}
	free_move(token);
	while ((ret = pars_type(token, &env)))
	{

		if (ret == -1)
		{
			ft_putstr_fd("rtv1: an error occur near token: `", 2);
			ft_putstr_fd((*token)->word, 2);
			ft_putstr_fd("'\n", 2);
			return (env);
		}
		if (!(*token) || (*token)->type != ENDED)
			return (env);
		free_move(token);
	}
	return (env);
}
