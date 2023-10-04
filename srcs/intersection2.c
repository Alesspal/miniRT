#include "ft_mlx.h"
#include "ft_raytracing.h"
#include <math.h>

// Return whether or not there is an intersection with a shape
// between two points.
bool	check_intersection(t_vec p1, t_vec p2, t_shapes *shape)
{
	while (shape)
	{
		if (shape->type == SPHERE)
		{
			if (sp_intersection_between_points(p1, p2, shape))
				return (true);
		}

		// plane

		// cylinder

		shape = shape->next;
	}
	return (false);
}

// Return whether or not there is an intersection with a sphere
// between two points.
bool	sp_intersection_between_points(t_vec p1, t_vec p2, t_shapes *shape)
{
	t_ray	ray;
	t_vec	dir;
	t_vec	co;
	t_eq	eq;
	float	len;

	dir = vec_sub(p2, p1);
	len = vec_size(dir);
	ray.origin = p1;
	ray.dir = ft_normalize(dir);
	co = vec_sub(ray.origin, shape->shape.sphere.origin);
	eq.a = 1;
	eq.b = 2.0 * ft_dot(co, ray.dir);
	eq.c = ft_dot(co, co) - pow(shape->shape.sphere.radius, 2);
	eq.discriminant = pow(eq.b, 2) - (4 * eq.a * eq.c);
	if (eq.discriminant < 0)
		return (false);
	eq.s1 = (-eq.b - sqrt(eq.discriminant)) / (2 * eq.a);
	eq.s2 = (-eq.b + sqrt(eq.discriminant)) / (2 * eq.a);
	if ((eq.s1 > 0 && eq.s1 < len) || (eq.s2 > 0 && eq.s2 < len))
		return (true);
	return (false);
}
