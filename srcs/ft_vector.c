#include "ft_vector.h"
#include <math.h>
#include <stdio.h>

t_vec	ft_create_vec(float x, float y, float z)
{
	return ((t_vec){x, y, z});
}

t_vec	ft_get_vec(t_point3D p1, t_point3D p2)
{
	t_vec v;

	v.x = p2.x - p1.x;
	v.y = p2.y - p1.y;
	v.z = p2.z - p1.z;
	printf("vec x = %f, y = %f, z = %f\n", v.x, v.y, v.z);
	return (v);
}

t_vec	ft_normalize(t_vec v)
{
	double	magnitude;

	magnitude = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	printf("magntiude = %f\n", magnitude);
	v.x /= magnitude;
	v.y /= magnitude;
	v.z /= magnitude;
	return (v);
}

float	ft_dot(t_vec v1, t_vec v2)
{
	printf("x1 = %f, x2 = %f, y1 = %f, y2 = %f, z1 = %f, z2 = %f\n", v1.x, v2.x, v1.y, v2.y, v1.z, v2.z);
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
