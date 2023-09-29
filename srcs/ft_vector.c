#include "ft_vector.h"
#include <math.h>

t_vec	ft_create_vec(float x, float y, float z)
{
	return ((t_vec){x, y, z});
}

t_vec	ft_normalize(t_vec v)
{
	double	magnitude;

	magnitude = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	v.x /= magnitude;
	v.y /= magnitude;
	v.z /= magnitude;
	return (v);
}

float	ft_dot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec	vec_add(t_vec vec1, t_vec vec2)
{
	t_vec res_vec;

	res_vec.x = vec1.x + vec2.x;
	res_vec.y = vec1.y + vec2.y;
	res_vec.z = vec1.z + vec2.z;
	return (res_vec);
}

t_vec	vec_sub(t_vec vec1, t_vec vec2)
{
	t_vec res_vec;

	res_vec.x = vec1.x - vec2.x;
	res_vec.y = vec1.y - vec2.y;
	res_vec.z = vec1.z - vec2.z;
	return (res_vec);
}

t_vec	ft_get_vec(t_point3D p1, t_point3D p2)
{
	t_vec v;

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

// Get a 3D point from a vector
t_point3D	v_to_p(t_vec v)
{
	t_point3D	p;

	p.x = v.x;
	p.y = v.y;
	p.z = v.z;
	return (p);
}

// Get a vector from a 3D point
t_vec	p_to_v(t_point3D p)
{
	t_vec	v;

	v.x = p.x;
	v.y = p.y;
	v.z = p.z;
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