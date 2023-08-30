#ifndef FT_RAYTRACING_H
# define FT_RAYTRACING_H

# include "ft_shapes.h"
# include <stdbool.h>

typedef struct s_ambiant_light
{
	int		color;
	float	intensity;
}	t_ambiant_light;

typedef struct s_spot_light
{
	int			id;
	int			color;
	float		intensity;
	t_point3D	pos;
}	t_spot_light;

typedef struct s_camera
{
	int			fov;
	t_point3D	pos;
	t_vec		dir;
}	t_camera;

typedef struct s_scene
{
	t_ambiant_light	ambient_light;
	t_spot_light	spot_light;
	t_camera		camera;
	t_shapes		*shapes;
}	t_scene;

typedef struct s_intersection
{
	t_point3D				pos;
	t_point2D				pixel;
	t_vec					prime_ray;
	t_shape_type			shape_type;
	t_shape					shape;
	struct s_intersection	*next;
}	t_intersection;

typedef struct s_ray
{
	t_point3D	origin;
	t_vec		dir;
}	t_ray;

// Struct for a quadratic equation
typedef struct s_eq
{
	float 	a;
	float 	b;
	float 	c;
	float 	discriminant;
	float	s1;
	float	s2;
}	t_eq;

// bool	intersection(t_point3D p1, t_point3D p2);
t_vec	get_normalized_n(t_vec P, int id, t_scene scene);

t_vec	get_n(t_intersection *p);

// Raytracer functions
void	draw_scene(t_data *data, t_scene scene);
void	fill_prime_ray(t_ray *prime_ray, t_mlx_win win, t_camera cam, t_point2D p);
void	sp_intersection(t_ray ray, t_sphere sp, t_intersection *intersection);
void	fill_intersection(t_ray ray, t_shapes *shape, t_intersection *intersection);

#endif