# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    rt.mk                                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roliveir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/07 10:06:25 by roliveir          #+#    #+#              #
#    Updated: 2019/06/19 01:32:46 by roliveir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RT_PATH = ./srcs/rt/

RT = rt_main.c					\
	 rt_vector_calc.c			\
	 rt_resolve_equation.c		\
	 rt_print.c					\
	 rt_basics_shapes.c			\
	 rt_keyhandler.c			\
	 rt_delenv.c				\
	 rt_inter_manager.c			\
	 rt_vector_normal.c			\
	 rt_vector_operation.c		\
	 rt_light_manager.c			\
	 rt_color_manager.c			\
	 rt_rotation.c				\
	 rt_material.c

RT_SRCS = $(addprefix $(RT_PATH),$(RT))
SRCS += $(RT_SRCS)
