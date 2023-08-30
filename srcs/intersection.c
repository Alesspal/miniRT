#include "ft_mlx.h"
#include "ft_raytracing.h"
#include <math.h>

// Fills the prime vector with its approriate components.
// p is the current pixel in which the ray is pointing towards.
void	fill_prime_ray(t_ray *prime_ray, t_mlx_win win, t_camera cam, t_point2D p)
{
	prime_ray->dir.x = -(win.win_w / 2) + p.x;
	prime_ray->dir.y = -(win.win_h / 2) + p.y;
	prime_ray->dir.z = (win.win_w / 2) / tan(cam.fov / 2);

	prime_ray->dir = ft_normalize(prime_ray->dir);
	prime_ray->origin = cam.pos;
}

// Checks if there is an intersection between a ray and a sphere.
// Fills the intersection struct with the closest intersection point if there is one.
void	sp_intersection(t_ray ray, t_sphere sp, t_intersection *intersection)
{
	t_vec		co;
	t_eq		eq;

	co = ft_get_vec(sp.origin, ray.origin);
	eq.a = 1;
	eq.b = 2.0 * ft_dot(co, ray.dir);
	eq.c = ft_dot(co, co) - pow(sp.radius, 2);
	eq.discriminant = pow(eq.b, 2) - (4 * eq.c);

	if (eq.discriminant < 0)
	{
		intersection->shape_type = NO_SHAPE;
		return ;
	}

	eq.s1 = (-eq.b - sqrt(eq.discriminant)) / 2;
	eq.s2 = (-eq.b + sqrt(eq.discriminant)) / 2;

	if (eq.s1 > 0 && eq.s1 < eq.s2)
	{
		intersection->shape_type = SPHERE;
		intersection->pos = v_to_p(vec_add(p_to_v(ray.origin), vec_mult(ray.dir, eq.s1)));
		return ;
	}
	if (eq.s2 > 0 && eq.s2 < eq.s1)
	{
		intersection->shape_type = SPHERE;
		intersection->pos = v_to_p(vec_add(p_to_v(ray.origin), vec_mult(ray.dir, eq.s2)));
		return ;
	}
}

// Checks if there are intersections with spheres and the casted prime ray.
// Fills the intersection struct with the closest sphere in front of the camera.
// Sets intersection.shape_type to NO_SHAPE if there is no intersection.
void	fill_intersection(t_ray ray, t_shapes *shape, t_intersection *intersection)
{
	intersection->shape_type = NO_SHAPE;
	// Go through the shapes list
	while (shape)
	{
		// sphere
		if (shape->type == SPHERE)
		{
			sp_intersection(ray, shape->shape.sphere, intersection);
		}

		// plane

		// cylinder

		shape = shape->next;
	}
}