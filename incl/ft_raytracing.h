#ifndef FT_RAYTRACING_H
# define FT_RAYTRACING_H

# include "ft_shapes.h"
# include "ft_color.h"
# include "stdbool.h"

typedef struct s_ambiant_light
{
	t_color	color;
	float	intensity;
	t_color	mod_color;
}	t_ambiant_light;

typedef struct s_spot_light
{
	int			id;
	t_color		color;
	float		intensity;
	t_color		mod_color;
	t_vec		pos;
}	t_spot_light;

typedef struct s_virtual_screen
{
	float	width;
	float	height;
	t_vec	center;
	t_vec	top_left;
	float	d;
}	t_virtual_screen;

typedef struct s_camera
{
	int					fov;
	t_vec				pos;
	t_vec				dir;
	t_vec				up;
	t_vec				right;
	t_virtual_screen	v_scr;
}	t_camera;

typedef struct s_scene
{
	t_ambiant_light	ambient_light;
	t_spot_light	spot_light;
	t_camera		camera;
	t_shapes		*shapes;
}	t_scene;

typedef enum e_element_type
{
	NOT_IDENTIFIED = -1,
	AMBIANT_LIGHT,
	SPOT_LIGHT,
	CAMERA,
	SP,
	CY,
	PL
}	t_element_type;

typedef struct s_intersection
{
	t_vec					pos;
	t_point2D				pixel;
	t_vec					prime_ray;
	t_shape_type			shape_type;
	t_shape					shape;
	float					dist;
	int						id;
}	t_intersection;

typedef struct s_ray
{
	t_vec		pos;
	t_vec		dir;
}	t_ray;

// Struct for a quadratic equation
typedef struct s_eq
{
	t_vec	co;
	float	a;
	float	b;
	float	c;
	float	discriminant;
	float	s1;
	float	s2;
}	t_eq;

// bool	intersection(t_vec p1, t_vec p2);
t_vec	get_normalized_n(t_vec P, int id, t_scene scene);

t_vec	get_n(t_intersection *p);

// Raytracer functions
void	init_camera(t_camera *cam, float aspect_ratio);
void	init_scene(t_scene *scene);
void	draw_scene(t_data *data, t_scene scene);
t_color	get_pixel_color(t_intersection inter, t_scene scene);
void	set_prime_ray(t_ray *prime_ray, t_mlx_win win, t_camera cam, t_point2D p);
void	sp_intersection(t_ray ray, t_sphere sp, t_intersection *intersection, int id);
void	compute_sp_equation(t_ray ray, t_sphere sp, t_eq *eq);
void	pl_intersection(t_ray ray, t_plane pl, t_intersection *intersection, int id);
void	cy_intersection(t_ray ray, t_cylinder cy, t_intersection *intersection, int id);
void	compute_cy_equation(t_ray ray, t_cylinder cy, t_eq *eq);
void	set_intersection(t_ray ray, t_shapes *shape, t_intersection *intersection);
bool	check_intersection(t_vec p1, t_vec p2, t_shapes *shape, int id);
bool	sp_intersection_between_points(t_vec p1, t_vec p2, t_shapes *shape);
bool	pl_intersection_between_points(t_vec p1, t_vec p2, t_shapes *shape);
bool	cy_intersection_between_points(t_vec p1, t_vec p2, t_shapes *shape);
t_vec	get_n(t_intersection *p);
t_color	phong(t_scene scene, t_intersection *p);
t_color	shadow(void);

#endif