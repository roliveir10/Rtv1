/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_build_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 21:16:29 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/16 11:37:59 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"
#include "libft.h"
#include <stdlib.h>

static int	lex_process(t_token *token, t_stat *stat, char buff[BUFF])
{
	int		st;
	int		type;

	st = stat->status;
	if (st == START && stat->type == CARM)
		if ((type = pile_last(stat)) == BRAO)
			stat->status = LSTOB;
	if (st == ERROR)
		return (1);
	if (stat->type != SPAC && (st == LSTCP || st == LSTOB))
		pile_up(stat, stat->type);
	if (stat->type != SPAC)
		lex_add_char(buff, &stat->load, stat->cha);
	if (st == PILDW)
		if (pile_down(stat, stat->type))
			return (1);
	if (stat->val)
		lex_add_token(buff, stat, token);
	if (st == LSTCP)
		stat->status = START;
	return (0);
}

static int	lex_error(t_token *token, t_stat *stat)//, char buff[BUFF])
{
	ft_strdel(&stat->load);
	ft_putnbr(stat->old_status);ft_putstr(" || old one vs ||");
	ft_putnbr(stat->type);ft_putstr(" _____ FINISH _____\n");
	//ft_strdel(&buff);
	free_token(token);
	ft_putstr_fd("error\n", 2);
	return (1);
}

int			pars_build_line(t_token *token, char *str, t_stat *stat)
{
	int		k;
	char	buff[BUFF];

	ft_bzero(&buff, BUFF);
	k = -1;
	while (str[++k])
	{
		stat->cha = str[k];
		stat->type = get_type(stat->cha);
		stat->old_status = stat->status;
		stat->status = get_next_state(stat->status, stat->type);
		stat->val = get_val(stat->old_status, stat->type);
		if (lex_process(token, stat, buff))
			return (lex_error(token, stat));//, buff));
	}
	//free(buff);
	return (0);
}
