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
	float		shininess;
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
	t_vec		n;
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
	bool			display;
	struct s_shapes	*next;
}	t_shapes;

#endif