/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_field_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:20:16 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/17 16:57:17 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"
#include "libft.h"
/*
static int		pars_select_field(t_token *token, t_env *env)
{
	static char	*field[NB_C_FIELDS] = {"\"origin\"", "\"fov\"",
		"\"vector_n\""};
	static int	(*fct_store[NB_C_FIELDS])(t_token*, t_env*, int field) = {

}*/	

int				pars_field_camera(t_token *token, t_env *env)
{
	(void)env;
	if (!(token = token->next) || token->type != NAMES)
	{
		ft_putstr_fd("rt: wrong format for camera definition\n", 2);
		return (1);
	}
	ft_putstr(token->word);ft_putstr(": found this for first arg\n");
//	if (pars_select_field(token, env))
//		return (1);
	return (0);
}
