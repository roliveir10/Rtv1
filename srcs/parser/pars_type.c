/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 19:49:55 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/17 16:57:16 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"
#include "libft.h"

int		pars_camera(t_token *token, t_env *env)
{

	token = token->next;
	if (!(token = token->next))
		return (-1);
	if (token->type == BRAO)
	{
		ft_putstr_fd("rt: Only one camera expected, remove lst\n", 2);
		return (-1);
	}
	if (pars_field_camera(token, env))
		return (-1);
	return (0);
}

int		pars_object(t_token *token, t_env *env)
{
	(void)token;(void)env;
	return (0);
}

int		pars_light(t_token *token, t_env *env)
{
	(void)token;(void)env;
	return (0);
}

int		pars_type(t_token *token, t_env *env)
{
	int				k;
	static char		*types[NB_TYPES] = {"\"camera\"", "\"object\"",
		"\"light\""};
	static int		(*fct_pars[NB_TYPES])(t_token*, t_env*) = {
		pars_camera, pars_object, pars_light};

	k = -1;
	while (++k < NB_TYPES)
		if (!ft_strcmp(types[k], token->word))
			return ((fct_pars[k])(token, env));
	return (-1);
}
