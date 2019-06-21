/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:41:46 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/22 01:22:39 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"
#include "libft.h"

static int		token_next(t_token **token)
{
	if (!(*token = (*token)->next) || (*token)->type != NOMBR)
		return (1);
	return (0);
}

double			pars_double(t_token **token)
{
	double		res;

	if (!((*token)->word))
		return (0);
	res = ft_atod((*token)->word);
	return (res);
}

int				pars_name(t_token **token)
{
	char		*name;
	int			k;
	static char	*lst[NBR_FORM] = {"\"sphere\"", "\"plan\"",
		"\"cylindre\"", "\"cone\""};

	if (!(name = (*token)->word))
		return (NOTAFORM);
	k = -1;
	while (++k < NBR_FORM)
		if (!ft_strcmp(name, lst[k]))
		{
			*token = (*token)->next;
			return (k);
		}
	*token = (*token)->next;
	return (NOTAFORM);
}

t_vector		pars_vector(t_token **token)
{
	t_vector	vect;

	ft_bzero(&vect, sizeof(t_vector));
	if ((*token)->type != BRAO || !(*token = (*token)->next))
		return (vect);
	vect.x = ft_atod((*token)->word);
	if (token_next(token))
		return (vect);
	vect.y = ft_atod((*token)->word);
	if (token_next(token))
		return (vect);
	vect.z = ft_atod((*token)->word);
	if (!(*token = (*token)->next))
		return (vect);
	return (vect);
}

t_vector		pars_vector_color(t_token **token)
{
	t_vector	vect;

	vect = pars_vector(token);
	vect.x = vect.x / 255.0;
	if (vect.x > 1.0)
		vect.x = 1;
	vect.y = vect.y / 255.0;
	if (vect.y > 1.0)
		vect.y = 1;
	vect.z = vect.z / 255.0;
	if (vect.z > 1.0)
		vect.z = 1;
	return (vect);
}
