/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:58:12 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/22 01:30:51 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RT_H
# define _RT_H

# include "libft.h"

# define SCREENX 2080
# define SCREENY 1170

# define NBR_FORM 4
# define NBR_THREAD 4
# define NBR_MATERIAL 1
# define NBR_KEY 13
# define BLINN 0
# define PIX 32

/*
** ENUM
*/

typedef enum			e_event
{
	KEYPRESS = 2,
	REDBUTTON = 17
}						t_event;

typedef enum			e_key
{
	KESCAP = 53,
	KLEFT = 123,
	KRIGHT = 124,
	KFOR = 14,
	KBACK = 2,
	KUP = 126,
	KDOWN = 125,
	KRXUP = 115,
	KRXDOWN = 119,
	KRYRIGHT = 117,
	KRYLEFT = 121,
	KRZRIGHT = 264,
	KRZLEFT = 116
}						t_key;

typedef enum			e_ftype
{
	SPHERE,
	PLAN,
	CYLINDRE,
	CONE,
	NOTAFORM
}						t_ftype;

typedef enum			e_ltype
{
	LSPOT,
	LCAST,
	LPOINT
}						t_ltype;

typedef enum			e_ematerial
{
	NOTHING,
}						t_ematerial;

/*
**	STRUCT
*/

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
	t_vector			pos;
	t_vector			color;
	t_vector			norm;
	t_vector			viewdir;
	t_vector			lightdir;
	int					id;
}						t_inter;

typedef struct			s_material
{
	t_vector			ambient;
	t_vector			diffuse;
	t_vector			specular;
	float				shininess;
}						t_material; 

typedef struct			s_lum
{
	t_vector			pos;
	t_vector			dir;
	t_vector			color;
	t_ltype				type;
	double				constant;
	double				linear;
	double				quadratic;
}						t_lum;

typedef	struct			s_ray
{
	t_vector			o;
	t_vector			dir;
}						t_ray;

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

typedef struct			s_form
{
	t_ftype				ftype;
	t_vector			center;
	t_vector			point;
	t_vector			direct;
	double				r;
	double				h;
	double				angle;
	t_vector			color;
	t_vector			rotation;
	t_material			material;
	double				mat[3][3][3];
	double				mati[3][3][3];
}						t_form;

typedef struct			s_scene
{
	float				ambient;
	float				spec;
	t_material			material[NBR_MATERIAL];
}						t_scene;

typedef struct			s_env
{
	t_mlx				mlx;
	t_scene				scene;
	t_cam				cam;
	int					nbr_form;
	int					nbr_lum;
	t_form				*form;
	t_lum				*lum;
	t_vector			color;
	int					offset;
	int					line_id;
}						t_env;

int						rt_main(t_env *env);
void					rt_delenv(t_env *env);

/*
**	shapes
*/

t_vector				rt_viewdir_inter(t_env *env, t_ray ray);
double					rt_sphere(t_ray ray, t_form form);
double					rt_plan(t_ray ray, t_form form);
double					rt_cylindre(t_ray ray, t_form form);
double					rt_cone(t_ray ray, t_form form);

/*
**	print
*/

int						rt_print(void *param);

/*
**	light
*/

t_vector				rt_light_manager(t_env *env, t_inter inter);
t_vector				rt_spec(t_vector light, t_inter inter,
		t_material mat, double attenuation);
t_vector				rt_diffuse(t_vector light, double angle,
		t_material mat, double attenuation);
t_vector				rt_ambient(t_vector light, t_material mat,
		double attenuation);
double					rt_attenuation(t_lum lum, double dist);

/*
** color
*/

void					rt_attribute_color(int color, t_vector *s_color);
t_vector				rt_get_color(t_lum lum, t_inter inter,
		t_material mat);
t_vector				rt_ambient_only(t_lum lum, t_material mat,
		t_inter inter);

/*
**	calc
*/

t_vector				rt_get_vecdir(t_cam cam, int x, int y);
t_vector				rt_get_posinter(t_ray ray, double dist);
t_vector				rt_get_vector(t_vector va, t_vector vb);
t_vector				rt_get_normal(t_vector v, t_form form);
t_vector				rt_normalize(t_vector v);
double					rt_dot(t_vector va, t_vector vb);
double					rt_dist(t_vector va, t_vector vb);
double					rt_resolv_nd_degre(double a, double b, double c);
double					rt_inter(t_ftype ftype, t_ray *ray, t_form form);

/*
**	operations
*/

t_vector				rt_vmul(t_vector v, double f);
t_vector				rt_vadd(t_vector va, t_vector vb);
t_vector				rt_vsub(t_vector va, t_vector vb);
t_vector				rt_vvmul(t_vector va, t_vector vb);

/*
**	key_handler
*/

int						rt_keypress(int keycode, void *param);
int						rt_close(void *param);

/*
**	camera
*/

void					rt_update_campos(t_cam *cam);
void					rt_update_camrot(t_cam *cam, double mat[3][3][3]);

/*
**	rotation
*/

void					rt_initialize_rotation(t_form **form);
void					rt_set_ref(t_ray *ray, t_form form);
void					rt_reset_point(t_form form, t_vector *inte);
void					rt_vect_rotation(t_vector *vec, double mat[3][3]);
void					rt_fill_matrot(double (*mat)[3][3][3],
		t_vector rotation);

/*
**	materials
*/

t_material				rt_get_material(t_ematerial emat, t_scene scene);

/*
**	debug
*/

void					debug_print_pos(t_vector pos);
#endif
