/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:58:12 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/07 13:34:43 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RT_H
# define _RT_H

# include "libft.h"

# define SCREENX 2000
# define SCREENY 1200

typedef struct			s_mlx
{
	void				*mlx;
	void				*image;
	void				*id;
	unsigned int		*mem_image;
	int					pix;
	int					size_line;
	int					endian;
}						t_mlx;

typedef struct			s_pos
{
	float				x;
	float				y;
	float				z;
}						t_pos;

typedef struct			s_ray
{
	t_pos				start;
	t_pos				dir;
	float				t;
}						t_ray;

typedef struct			s_cam
{
	t_pos				pos;
	t_pos				vec_dir;
	t_pos				vp_upleft;
	float				vp_width;
	float				vp_height;
	float				vp_dist;
}						t_cam;

typedef struct			s_env
{
	t_mlx				mlx;
	t_cam				cam;
}						t_env;

int						rt_main(t_env *env);

/*
**	debug
*/

void					debug_print_pos(t_pos pos);
#endif
