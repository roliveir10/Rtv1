/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_keyhandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:03:35 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/23 10:05:42 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"

static void			rt_escap(t_env *env, int keycode)
{
	(void)keycode;
	rt_delenv(env);
}

int					rt_keypress(int keycode, void *param)
{
	static int		tkey[NBR_KEY] = {KESCAP, KLEFT, KRIGHT, KUP, KDOWN,
		KRXUP, KRXDOWN, KRYRIGHT, KRYLEFT, KRZRIGHT, KRZLEFT};
	static void		(*lst_function[NBR_KEY])(t_env *, int) = {
			rt_escap, rt_movecam_pos, rt_movecam_pos, rt_movecam_pos,
			rt_movecam_pos, rt_movecam_rot, rt_movecam_rot, rt_movecam_rot,
			rt_movecam_rot, rt_movecam_rot, rt_movecam_rot};
	int				i;

	i = -1;
	while (++i < NBR_KEY)
		if (tkey[i] == keycode)
			lst_function[i]((t_env*)param, keycode);
	return (0);
}

int					rt_mousepress(int keycode, int x, int y, void *param)
{
	static int		mkey[NBR_MKEY] = {MDOWN, MUP};
	static void		(*lst_function[NBR_MKEY])(t_env*, int) = {
		rt_mmovecam_pos, rt_mmovecam_pos};
	int				i;

	i = -1;
	(void)x;
	(void)y;
	while (++i < NBR_MKEY)
		if (mkey[i] == keycode)
			lst_function[i]((t_env*)param, keycode);
	return (0);
}

int					rt_close(void *param)
{
	rt_delenv((t_env*)param);
	return (1);
}
