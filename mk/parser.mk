# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    parser.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roliveir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/07 10:04:52 by roliveir          #+#    #+#              #
#    Updated: 2019/06/22 19:02:42 by oboutrol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PARSER_PATH = ./srcs/parser/

PARSER =	parser_main.c		\
			pars_file.c			\
			free_struct.c		\
			pars_build_line.c	\
			lex_pile.c			\
			lex_get.c			\
			pars_token.c		\
			pars_material.c		\
			pars_type.c			\
			pars_lst.c			\
			pars_lst_form.c		\
			pars_field_camera.c	\
			ft_atod.c			\
			pars_field_light.c	\
			pars_field_form.c	\
			pars_vector.c		\
			pars_init.c			\
			lex_add_char.c

PARSER_SRCS = $(addprefix $(PARSER_PATH),$(PARSER))
SRCS += $(PARSER_SRCS)
