/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:25:51 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/16 11:41:05 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"
#include "libft.h"

int					get_type(char c)
{
	int				k;
	static char		*str = "\":,{}[]";

	k = -1;
	while (str[++k])
	{
		if (str[k] == c)
			return (k);
	}
	if (ft_isdigit(c))
		return (NOMBR);
	else if (ft_strchr(" \t", c))
		return (SPAC);
	return (CHAR);
}

int					get_next_state(int status, int type)
{
	static int		mat[NB_STATUS][NB_TYPE] = {
		{NAMES, ERROR, ERROR, LSTCP, ERROR, ERROR, ERROR, ERROR, START, ERROR},
		{TWPTS, NAMES, NAMES, NAMES, NAMES, NAMES, NAMES, NAMES, NAMES, NAMES},
		{ERROR, ARGMT, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, TWPTS, ERROR},
		{WORDS, ERROR, ERROR, LSTCP, ERROR, LSTOB, ERROR, ERROR, ARGMT, ERROR},
		{ENDED, WORDS, WORDS, WORDS, WORDS, WORDS, WORDS, WORDS, WORDS, WORDS},
		{ERROR, ERROR, START, ERROR, PILDW, ERROR, PILDW, ERROR, ENDED, ERROR}, 
		{ERROR, ERROR, START, ERROR, PILDW, ERROR, PILDW, NOMBR, ENDED, ERROR}, 
		{NAMES, ERROR, ERROR, LSTCP, ERROR, LSTOB, ERROR, NOMBR, LSTOB, ERROR}, 
	};

	if (status >= NB_STATUS || status < 0 || type >= NB_TYPE || type < 0)
		return (ERROR);
	return (mat[status][type]);
}

int					get_val(int status, int type)
{
	static int		mat[NB_STATUS][NB_TYPE] = {
		{FALSE, FALSE, FALSE, TRUTH, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE},
		{TRUTH, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE},
		{FALSE, TRUTH, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE},
		{FALSE, FALSE, FALSE, TRUTH, FALSE, TRUTH, FALSE, FALSE, FALSE, FALSE},
		{TRUTH, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE},
		{FALSE, FALSE, TRUTH, FALSE, TRUTH, FALSE, TRUTH, FALSE, FALSE, FALSE},
		{FALSE, FALSE, TRUTH, FALSE, TRUTH, FALSE, TRUTH, FALSE, FALSE, FALSE},
		{FALSE, FALSE, FALSE, TRUTH, FALSE, TRUTH, FALSE, FALSE, FALSE, FALSE},
	};

	if (status >= NB_STATUS || status < 0 || type >= NB_TYPE || type < 0)
		return (FALSE);
	return (mat[status][type]);
}
