#include "ft_vector.h"
#include <math.h>

t_vec	ft_get_vec(t_vec p1, t_vec p2)
{
	t_vec	v;

	v.x = p2.x - p1.x;
	v.y = p2.y - p1.y;
	v.z = p2.z - p1.z;
	return (v);
}

t_vec	vec_mult(t_vec v, float scalar)
{
	v.x *= scalar;
	v.y *= scalar;
	v.z *= scalar;
	return (v);
}

// Get the cross product of two vectors
t_vec	cross_product(t_vec v1, t_vec v2)
{
	t_vec	res_vec;

	res_vec.x = v1.y * v2.z - v1.z * v2.y;
	res_vec.y = v1.z * v2.x - v1.x * v2.z;
	res_vec.z = v1.x * v2.y - v1.y * v2.x;
	return (res_vec);
}

// Get the size of a vector
float	vec_size(t_vec v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}
