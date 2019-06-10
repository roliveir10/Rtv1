# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    rt.mk                                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roliveir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/07 10:06:25 by roliveir          #+#    #+#              #
#    Updated: 2019/06/10 17:29:47 by roliveir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RT_PATH = ./srcs/rt/

RT = rt_main.c					\
	 rt_calc_vector.c			\
	 rt_calc_nd_degre.c			\
	 rt_print.c					\
	 rt_sphere.c				\
	 rt_plan.c					\
	 rt_keyhandler.c			\
	 rt_delenv.c				\
	 rt_browse_form.c			\
	 rt_calc_norm.c				\
	 rt_add_mul_sub_vector.c	\
	 rt_light_manager.c			\
	 rt_color_manager.c

RT_SRCS = $(addprefix $(RT_PATH),$(RT))
SRCS += $(RT_SRCS)
