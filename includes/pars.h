/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:15:46 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/16 10:01:50 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARS_H
# define PARS_H
# define FALSE 0
# define TRUTH 1
# include "rt.h"
# define BUFF 2048

typedef struct		s_token
{
	struct s_token	*next;
	char			*word;
	int				type;
	int				pile;
}					t_token;

/*
**	enum for types
**
**	START |	Starting point
**	NAMES |	Name of the object
**	TWPTS |	Separator name/argument
**	ARGMT |	Argument
**	WORDS |	Word in argument
**	ENDED |	End of argument
**	NOMBR |	Digit numbers
*/
# define NB_STATUS 8

typedef enum		e_status
{
	START = 0,
	NAMES,
	TWPTS,
	ARGMT,
	WORDS,
	ENDED,
	NOMBR,
	LSTOB,
	LSTCP,
	ERROR,
	PILDW///////////virtual END
	/*OBRAC,
	OCURL,
	CBRAC,
	CCURL*/
}					t_status;

/*
**	enum for char_types
**	
**	DBQT |	Double quote, in order to store word
**	TWPT |	Separator Name, Argument
**	NBRS |	Digit kind
**	CBRO |	Curly bracket open
**	CBRC |	Curly bracket closure
**	BRAO |	Bracket open
**	BRAC |	Bracket closure
**	CHAR |	all other chars
*/

# define NB_TYPE 10

typedef enum		e_types
{
	DBQT = 0,
	TWPT,
	CARM,
	CBRO,
	CBRC,
	BRAO,
	BRAC,
	NBRS,
	SPAC,
	CHAR
}					t_types;

typedef struct		s_pile
{
	int				type;
	struct s_pile	*next;
}					t_pile;

typedef struct		s_stat
{
	char			cha;
	char			*load;
	t_pile			*pile;
	int				type;
	int				status;
	int				old_status;
	int				val;
}					t_stat;

int					pars_build_line(t_token *token, char *str, t_stat *stat);
t_env				*pars_file(char *str);
t_env				*token_to_env(t_token *token);
int					get_type(char c);
int					get_next_state(int status, int type);
int					get_val(int status, int type);
void				lex_add_char(char buff[BUFF], char **load, char cha);
void				lex_add_token(char buff[BUFF], t_stat *stat, t_token *tok);
t_token				*lex_init_token(int type, char *str);
void				free_token(t_token *token);
void				free_struct(t_token *token);
void				print_token(t_token *token);
void				print_norm(t_token *token);
void				print_pile(t_pile *pile);
void				pile_up(t_stat *stat, int type);
int					pile_down(t_stat *stat, int type);
int					pile_last(t_stat *stat);

#endif
