# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    parser.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roliveir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/07 10:04:52 by roliveir          #+#    #+#              #
#    Updated: 2019/06/08 10:50:14 by roliveir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PARSER_PATH = ./srcs/parser/

PARSER = parser_main.c			\
			debug.c				\

PARSER_SRCS = $(addprefix $(PARSER_PATH),$(PARSER))
SRCS += $(PARSER_SRCS)
