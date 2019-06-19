/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_keyhandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:03:35 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/19 08:38:42 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"

static void			rt_key_escap(t_env *env, int keycode)
{
	(void)keycode;
	rt_delenv(env);
}

int					rt_keypress(int keycode, void *param)
{
	static int		tkey[NBR_KEY] = {KESCAP};
	static void		(*lst_function[NBR_KEY])(t_env *, int) = {
			rt_key_escap};
	int				i;

	i = -1;
	while (++i < NBR_KEY)
		if (tkey[i] == keycode)
			lst_function[i]((t_env*)param, keycode);
	return (0);
}

int					rt_close(void *param)
{
	rt_delenv((t_env*)param);
	return (1);
}
