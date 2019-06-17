/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:58:12 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/17 16:57:20 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RT_H
# define _RT_H

# include "libft.h"

# define SCREENX 2080
# define SCREENY 1170

# define NBR_FORM 4
# define RANDOM 0.5

typedef enum			e_event
{
	KEYPRESS = 2,
	REDBUTTON = 17
}						t_event;

typedef enum			e_key
{
	KESCAP = 53
}						t_key;

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
	double				x;
	double				y;
	double				z;
}						t_pos;

typedef struct			s_color
{
	double				r;
	double				g;
	double				b;
}						t_color;

typedef struct			s_inter
{
	double				x;
	double				y;
	double				z;
	double				t;
	t_color				color;
	t_pos				norm;
	char				out;
}						t_inter;

typedef struct			s_lum
{
	t_pos				pos;
	t_color				color;
}						t_lum;

typedef struct			s_solve
{
	double				ta;
	double				tb;
}						t_solve;

typedef struct			s_cam
{
	t_pos				pos;
	t_pos				vec_dir[3];
	t_pos				vp_upleft;
	double				vp_width;
	double				vp_height;
	double				vp_dist;
	double				rot_mat[3][3][3];
	int					fov;
}						t_cam;

typedef enum			e_ftype
{
	SPHERE,
	PLAN,
	CYLINDRE,
	CONE
}						t_ftype;

typedef struct			s_form
{
	t_ftype				ftype;
	t_pos				center;
	t_pos				point;
	double				r;
	double				h;
	double				angle;
	t_color				color;
	double				rotation[3];
	char				out;
}						t_form;

typedef struct			s_env
{
	t_mlx				mlx;
	t_cam				cam;
	int					nbr_form;
	int					nbr_lum;
	t_form				*form;
	t_lum				*lum;
	t_inter				*inter;
}						t_env;

int						rt_main(t_env *env);
int						rt_delenv(t_env *env);

/*
**	shape
*/

t_inter					rt_browse_form(t_env *env, t_form **form, t_pos pix);
void					rt_sphere(t_pos o, t_pos pix, t_form form,
		t_inter *inter);
void					rt_plan(t_pos o, t_pos pix, t_form form,
		t_inter *inter);
void					rt_cylindre(t_pos a, t_pos pix, t_form form,
		t_inter *inter);
void					rt_cone(t_pos a, t_pos pix, t_form form,
		t_inter *inter);

/*
**	print
*/

void					rt_print(t_env *env);
t_pos					rt_get_normal(t_inter inter, t_form form);

/*
**	light
*/

t_inter					rt_light_manager(t_env *env, int index);

/*
** color
*/

void					rt_attribute_color(int color, t_color *s_color);

/*
**	calc
*/

t_pos					rt_vmul(t_pos pos, double f);
t_pos					rt_vadd(t_pos pos_a, t_pos pos_b);
t_pos					rt_vsub(t_pos pos_a, t_pos pos_b);
t_pos					rt_get_pospix(t_cam cam, int x, int y);
void					rt_get_posinter(t_pos o, t_pos pix, t_inter *inter);
t_pos					rt_get_vector(t_pos pos, t_pos inter);
t_pos					rt_get_normal(t_inter inter, t_form form);
t_pos					rt_normalize(t_pos vector);
double					rt_dot_product(t_pos va, t_pos vb);
double					rt_get_t(double a, double b, double c, char *out);

/*
**	key_handler
*/

int						rt_keypress(int keycode, void *param);
int						rt_close(void *param);

/*
**	rotation
*/

void					rt_vect_rotation(t_pos *vec, double mat[3][3]);
void					rt_set_ref(t_pos *o, t_pos *dir, t_form form);
void					rt_reset_point(t_form form, t_pos *inte);

/*
**	debug
*/

void					debug_print_pos(t_pos pos);
#endif
