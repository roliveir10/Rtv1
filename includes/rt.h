/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:58:12 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/17 05:19:39 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RT_H
# define _RT_H

# include "libft.h"

# define SCREENX 2080
# define SCREENY 1170

# define NBR_FORM 4
# define NBR_THREAD 1

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

typedef struct			s_vector
{
	double				x;
	double				y;
	double				z;
}						t_vector;

typedef struct			s_inter
{
	char				out;
	t_vector			pos;
	t_vector			color;
	t_vector			norm;
	double				t;
	int					index;
}						t_inter;

typedef struct			s_lum
{
	t_vector			pos;
	t_vector			color;
}						t_lum;

typedef	struct			s_ray
{
	t_vector			o;
	t_vector			dir;
	double				t;
}						t_ray;

typedef struct			s_solve
{
	double				ta;
	double				tb;
}						t_solve;

typedef struct			s_cam
{
	t_vector			pos;
	t_vector			vec_dir[3];
	t_vector			vp_upleft;
	double				vp_width;
	double				vp_height;
	double				vp_dist;
	double				rot_mat[3][3][3];
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
	t_vector			center;
	t_vector			point;
	double				r;
	double				h;
	double				angle;
	t_vector			color;
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
	t_vector			color;
}						t_env;

int						rt_main(t_env *env);
int						rt_delenv(t_env *env);

/*
**	shapes
*/

t_vector				rt_browse_form(t_env *env, t_ray ray);
double					rt_sphere(t_ray ray, t_form form);
double					rt_plan(t_ray ray, t_form form);
double					rt_cylindre(t_ray ray, t_form form);
double					rt_cone(t_ray ray, t_form form);

/*
**	print
*/

void					rt_print(t_env *env);

/*
**	light
*/

t_vector				rt_light_manager(t_env *env, t_inter inter);

/*
** color
*/

void					rt_attribute_color(int color, t_vector *s_color);
t_vector				rt_get_color(t_env *env, int i, int ind, double angle);

/*
**	calc
*/

t_vector				rt_vmul(t_vector pos, double f);
t_vector				rt_vadd(t_vector pos_a, t_vector pos_b);
t_vector				rt_vsub(t_vector pos_a, t_vector pos_b);
t_vector				rt_get_vecdir(t_cam cam, int x, int y);
t_vector				rt_get_posinter(t_ray ray, double dist);
t_vector				rt_get_vector(t_vector pos, t_vector inter);
t_vector				rt_get_vector_dist(t_vector pos, t_vector inter);
t_vector				rt_get_normal(t_vector inter, t_form form);
t_vector				rt_normalize(t_vector vector);
double					rt_dot_product(t_vector va, t_vector vb);
double					rt_resolv_nd_degre(double a, double b, double c);

/*
**	key_handler
*/

int						rt_keypress(int keycode, void *param);
int						rt_close(void *param);

/*
**	rotation
*/

void					rt_vect_rotation(t_vector *vec, double mat[3][3]);
void					rt_set_ref(t_ray *ray, t_form form);
void					rt_reset_point(t_form form, t_vector *inte);
t_ray					rt_update_base(t_env *env, int index, int forward);

/*
**	debug
*/

void					debug_print_pos(t_vector pos);
#endif
