/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 23:09:07 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/16 17:24:52 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"
#include "libft.h"

void		print_x(int nbr, char c)
{
	while (nbr > 0)
	{
		ft_putchar(c);
		nbr--;
	}
}

void		print_one_token(t_token *token, int prev)
{
	if (!token)
		return ;
	if (token->word)
	{
		if (prev < token->pile)
			print_x(prev, '\t');
		else
			print_x(token->pile, '\t');
		if (prev != 0)
			ft_putstr(" ");
		ft_putstr(token->word);
	}
	if (token->type == 1 || token->type == 2 || (token->next
				&& (!ft_strcmp(token->next->word, ",")
					|| token->next->type == NOMBR)))
		print_one_token(token->next, 0);
	else
	{
		ft_putstr("\n");
		print_one_token(token->next, token->pile);
	}
}

void		print_norm(t_token *token)
{
	print_one_token(token, 0);
}

void		print_token(t_token *token)
{
	if (!token)
		return ;
	ft_putstr("{");
	ft_putnbr(token->type);
	ft_putstr(", ");
	if (token->word)
		ft_putstr(token->word);
	ft_putstr("}  ");
	print_token(token->next);
}

void		print_pile(t_pile *pile)
{
	if (!pile)
		return ;
	ft_putnbr(pile->type);ft_putstr("  ");
	print_pile(pile->next);
}
