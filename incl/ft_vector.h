#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include "ft_point.h"

typedef struct s_vec
{
	float x;
	float y;
	float z;
}	t_vec;

t_vec	ft_create_vec(float x, float y, float z);
t_vec	ft_get_vec(t_point3D p1, t_point3D p2);
t_vec	ft_normalize(t_vec v);
float	ft_dot(t_vec v1, t_vec v2);

#endif