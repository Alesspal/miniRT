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
