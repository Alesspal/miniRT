#include "ft_vector.h"
#include <math.h>

t_vec	ft_create_vec(float x, float y, float z)
{
	return ((t_vec){x, y, z});
}

t_vec	ft_normalize(t_vec v)
{
	float	magnitude;

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
	t_vec	res_vec;

	res_vec.x = vec1.x + vec2.x;
	res_vec.y = vec1.y + vec2.y;
	res_vec.z = vec1.z + vec2.z;
	return (res_vec);
}

t_vec	vec_sub(t_vec vec1, t_vec vec2)
{
	t_vec	res_vec;

	res_vec.x = vec1.x - vec2.x;
	res_vec.y = vec1.y - vec2.y;
	res_vec.z = vec1.z - vec2.z;
	return (res_vec);
}
