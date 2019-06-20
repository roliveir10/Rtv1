/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_keyhandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:03:35 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/20 09:45:48 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"

static void			rt_escap(t_env *env, int keycode)
{
	(void)keycode;
	rt_delenv(env);
}

static void			rt_movecam_pos(t_env *env, int keycode)
{
	if (keycode == KFOR)
		env->cam.pos.z += 1;
	else if (keycode == KBACK)
		env->cam.pos.z -= 1;
	else if (keycode == KLEFT)
		env->cam.pos.x -= 1;
	else if (keycode == KRIGHT)
		env->cam.pos.x += 1;
	else if (keycode == KUP)
		env->cam.pos.y += 1;
	else if (keycode == KDOWN)
		env->cam.pos.y -= 1;
	rt_update_campos(&env->cam);
	env->offset = 32;
}

static void			rt_movecam_rot(t_env *env, int keycode)
{
	double			mat[3][3][3];
	t_vector		rotation;
	double			neg;

	neg = 1;
	ft_bzero(&rotation, sizeof(t_vector));
	if (keycode == KRXUP || keycode == KRYRIGHT || keycode == KRZRIGHT)
		neg = -1;
	if (keycode == KRXUP || keycode == KRXDOWN)
		rotation.x = 1.0 * neg;
	else if (keycode == KRYRIGHT || keycode == KRYLEFT)
		rotation.y = 1.0 * neg;
	else if (keycode == KRZRIGHT || keycode == KRZLEFT)
		rotation.z = 1.0 * neg;
	rt_fill_matrot(&mat, rotation);
	rt_update_camrot(&env->cam, mat);
	env->offset = 32;
}

int					rt_keypress(int keycode, void *param)
{
	static int		tkey[NBR_KEY] = {KESCAP, KFOR, KBACK, KLEFT, KRIGHT,
		KUP, KDOWN, KRXUP, KRXDOWN, KRYRIGHT, KRYLEFT, KRZRIGHT, KRZLEFT};
	static void		(*lst_function[NBR_KEY])(t_env *, int) = {
			rt_escap, rt_movecam_pos, rt_movecam_pos, rt_movecam_pos,
			rt_movecam_pos, rt_movecam_pos, rt_movecam_pos, rt_movecam_rot,
			rt_movecam_rot, rt_movecam_rot, rt_movecam_rot, rt_movecam_rot,
			rt_movecam_rot};
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
