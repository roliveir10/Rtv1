/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 22:48:56 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/23 02:55:27 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

int				size_lst(t_lstlum *tmp)
{
	int			k;

	k = 0;
	while (tmp)
	{
		tmp = tmp->next;
		k++;
	}
	return (k);
}

t_lum			*lstlum_to_lum(t_lstlum *lstlum, int size)
{
	t_lum		*lum;
	int			j;

	if (!(lum = (t_lum*)ft_memalloc(sizeof(t_lum) * size)))
	{
		free_lstlum(&lstlum);
		return (NULL);
	}
	j = -1;
	while (++j < size)
	{
		lum[j] = lstlum->lum;
		lstlum = lstlum->next;
	}
	free_lstlum(&lstlum);
	return (lum);
}

t_lstlum		*new_lum(t_lum light)
{
	t_lstlum	*new;

	if (!(new = (t_lstlum*)ft_memalloc(sizeof(t_lstlum))))
		return (NULL);
	new->lum = light;
	return (new);
}

void			add_light(t_lstlum **lstlum, t_lum light)
{
	t_lstlum	*tmp;

	if (!*lstlum)
		*lstlum = new_lum(light);
	else
	{
		tmp = *lstlum;
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = new_lum(light);
	}
}
