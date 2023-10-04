#ifndef FT_SHAPES_H
# define FT_SHAPES_H

# include "ft_mlx.h"
# include "ft_vector.h"
# include "ft_point.h"
# include "ft_color.h"

typedef struct s_sphere
{
	t_vec		pos;
	float		radius;
	t_color		color;
}	t_sphere;

typedef struct s_cylinder
{
	t_vec		pos;
	t_vec		dir;
	float		radius;
	float		height;
	t_color		color;
}	t_cylinder;

typedef struct s_plane
{
	t_vec		pos;
	t_vec		normal;
	t_color		color;
}	t_plane;

typedef enum e_shape_type
{
	SPHERE,
	CYLINDER,
	PLANE,
	NO_SHAPE
}	t_shape_type;

typedef struct s_shape
{
	t_sphere	sphere;
	t_cylinder	cylinder;
	t_plane		plane;
}	t_shape;

typedef struct s_shapes
{
	int				id;
	t_shape_type	type;
	t_shape			shape;
	struct s_shapes	*next;
}	t_shapes;

t_sphere	create_sphere(t_vec pos, float diameter, t_color color);
t_cylinder	create_cylinder(t_vec pos, t_vec dir, float diameter,
						float height, t_color color);
t_plane		create_plan(t_vec pos, t_vec dir, t_color color);

void		draw_filled_sphere(t_data *data, t_sphere sphere);

#endif