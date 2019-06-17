/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:41:46 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/18 01:02:15 by oboutrol         ###   ########.fr       */
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
	int			k;
	double		res;
	char		*value;
	int			sign;
	double		div;

	div = 1.0;
	if (!(value = (*token)->word))
		return (0);
	res = 0;
	sign = value[0] == '-' ? -1 : 1;
	if (value[0] == '-' || value[0] == '+')
		res++;
	k = -1;
	while (ft_isdigit(value[++k]))
		res = res * 10 + value[k] - '0';
	if (value[k] == '.')
		while (ft_isdigit(value[++k]))
		{
			div = div / 10.0;
			res += div * (value[k] - '0');
		}
	ft_putendl(value);
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
	ft_putendl(name);
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
	vect.x = ft_atoi((*token)->word);
	if (token_next(token))
		return (vect);
	vect.y = ft_atoi((*token)->word);
	if (token_next(token))
		return (vect);
	vect.z = ft_atoi((*token)->word);
	if (!(*token = (*token)->next))
		return (vect);
	print_vector(vect);
	return (vect);
}
