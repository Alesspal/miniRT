#ifndef FT_SHAPES_H
# define FT_SHAPES_H

# include "ft_mlx.h"
# include "ft_vector.h"
# include "ft_point.h"
# include "ft_color.h"

typedef struct s_sphere
{
	t_point3D	origin;
	float		radius;
	t_color		color;
}	t_sphere;

typedef struct s_cylinder
{
	t_point3D	origin;
	t_vec		orientation;
	float		radius;
	float		height;
	t_color		color;
}	t_cylinder;

typedef struct s_plan
{
	t_point3D	origin;
	t_vec		orientation;
	t_color		color;
}	t_plan;

typedef enum e_shape_type
{
	SHPERE,
	CYLINDER,
	PLAN
}	t_shape_type;

typedef union s_shape
{
	t_sphere	sphere;
	t_cylinder	cylinder;
	t_plan		plan;
}	t_shape;

typedef struct s_shapes
{
	int				id;
	t_shape_type	shape_type;
	t_shape			shape;
	struct s_shapes	*next;
}	t_shapes;

t_sphere	create_sphere(t_point3D origin, int radius, t_color color);
t_cylinder	create_cylinder(t_point3D origin, t_vec orientation, int radius,
						int height, t_color color);
t_plan		create_plan(t_point3D origin, t_vec orientation, t_color color);

void		draw_filled_sphere(t_data *data, t_sphere sphere);

#endif