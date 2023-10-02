#include "ft_mlx.h"
#include "ft_raytracing.h"
#include <math.h>

// Fill prime ray considering the position and 
// direction of the camera and the pixel position.
void	fill_prime_ray(t_ray *pr, t_mlx_win win, t_camera cam, t_point2D p)
{
	double	u;
	double	v;
	t_vec	pixel_pos;

	u = (double)p.x / win.win_w;
	v = (double)p.y / win.win_h;
	pixel_pos = vec_add(cam.v_screen.top_left,
			vec_sub(vec_mult(cam.right, u * cam.v_screen.width),
				vec_mult(cam.up, v * cam.v_screen.height)));
	pr->dir = ft_normalize(vec_sub(pixel_pos, cam.pos));
}

// Checks if there is an intersection between a ray and a sphere.
// Fills the intersection struct with the closest intersection point if there is one.
void sp_intersection(t_ray ray, t_sphere sp, t_intersection *intersection)
{
    t_vec co;
    t_eq eq;

    co = vec_sub(ray.origin, sp.origin);
    eq.a = 1;
    eq.b = 2.0 * ft_dot(co, ray.dir);
    eq.c = ft_dot(co, co) - pow(sp.radius, 2);
    eq.discriminant = pow(eq.b, 2) - (4 * eq.a * eq.c);

    if (eq.discriminant < 0)
        return;

    eq.s1 = (-eq.b - sqrt(eq.discriminant)) / (2 * eq.a);
    eq.s2 = (-eq.b + sqrt(eq.discriminant)) / (2 * eq.a);

    // Determine the closest intersection that's in front of the ray's origin
    if (eq.s1 > 0 && (eq.s2 < 0 || eq.s1 < eq.s2))
    {
		if (eq.s1 < intersection->dist || intersection->dist == -1)
		{
			intersection->shape.sphere = sp;
        	intersection->shape_type = SPHERE;
        	intersection->pos = vec_add(ray.origin, vec_mult(ray.dir, eq.s1));
			intersection->dist = eq.s1;
		}
        return;
    }
    else if (eq.s2 > 0 && (eq.s1 < 0 || eq.s2 < eq.s1))
    {
		if (eq.s2 < intersection->dist || intersection->dist == -1)
		{
			intersection->shape_type = SPHERE;
			intersection->pos = vec_add(ray.origin, vec_mult(ray.dir, eq.s2));
			intersection->dist = eq.s2;
		}
        return;
    }

    // intersection->shape_type = NO_SHAPE;
}

// Checks if there are intersections with spheres and the casted prime ray.
// Fills the intersection struct with the closest sphere in front of the camera.
// Sets intersection.shape_type to NO_SHAPE if there is no intersection.
void	fill_intersection(t_ray ray, t_shapes *shape, t_intersection *intersection)
{
	intersection->shape_type = NO_SHAPE;
	intersection->dist = -1;
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

// Return whether or not there is an intersection with a shape between two points.
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

// Return whether or not there is an intersection with a sphere between two points.
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
	// Check if the intersection is between the two points
	if ((eq.s1 > 0 && eq.s1 < len) || (eq.s2 > 0 && eq.s2 < len))
		return (true);
	return (false);
}
