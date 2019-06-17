/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 18:58:22 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/17 20:10:28 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "libft.h"
#include "pars.h"

static int	token_up(int fd, t_token *token, char **str)
{
	int		ret;
	char	*line;
	int		pos;
	t_stat	stat;
	int		k;

	k = 0;
	ft_bzero(&stat, sizeof(t_stat));
	stat.status = START;
	pos = -1;
	line = NULL;
	while ((ret = get_line(fd, &line, str)) > 0)
	{
		if (pars_build_line(token, line, &stat, ++k))
			return (1);
		ft_strdel(&line);
	}
	if (ret == -1)
	{
		ft_putstr_fd("rt: read error\n", 2);
		return (1);
	}
	return (0);
}

t_env		*pars_file(char *str)
{
	int		fd;
	t_token	*token;
	char	*rest;

	if ((fd = open(str, O_RDONLY)) == -1)
	{
		ft_putstr_fd("rt: can not open: `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("' for reading\n", 2);
		return (NULL);
	}
	if (!(token = lex_init_token(0, NULL)))
		return (NULL);
	rest = NULL;
	if (token_up(fd, token, &rest))
		return (NULL);
	if (rest)
		free(rest);
	print_token(token->next);ft_putchar('\n');
	print_norm(token->next);
	return (token_to_env(token->next));
}
