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
			if (sp_intersection_between_points(p1, p2, shape))
				return (true);
		if (shape->type == PLANE)
			if (pl_intersection_between_points(p1, p2, shape))
				return (true);
		if (shape->type == CYLINDER)
			if (cy_intersection_between_points(p1, p2, shape))
				return (true);
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
	ray.pos = p1;
	ray.dir = ft_normalize(dir);
	co = vec_sub(ray.pos, shape->shape.sphere.pos);
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

// Return whether or not there is an intersection with a plane
// between two points.
bool	pl_intersection_between_points(t_vec p1, t_vec p2, t_shapes *shape)
{
	t_ray	ray;
	t_vec	dir;
	float	t;
	float	ray_n_dot_product;

	dir = vec_sub(p2, p1);
	ray.pos = p1;
	ray.dir = ft_normalize(dir);
	shape->shape.plane.normal = ft_normalize(shape->shape.plane.normal);
	ray_n_dot_product = ft_dot(ray.dir, shape->shape.plane.normal);
	if (ray_n_dot_product == 0)
		return (false);
	t = ft_dot(vec_sub(shape->shape.plane.pos, ray.pos),
		shape->shape.plane.normal) / ray_n_dot_product;
	if (t > 0 && t < vec_size(dir))
		return (true);
	return (false);
}

// Return whether or not there is an intersection with a cylinder
// between two points.
bool	cy_intersection_between_points(t_vec p1, t_vec p2, t_shapes *shape)
{
	t_ray	ray;
	t_vec	dir;
	t_vec	co;
	t_eq	eq;
	float	len;
	t_cylinder	cy;

	cy = shape->shape.cylinder;
	dir = vec_sub(p2, p1);
	len = vec_size(dir);
	ray.pos = p1;
	ray.dir = ft_normalize(dir);
	co = vec_sub(ray.pos, cy.pos);
	eq.a = pow(ray.dir.x, 2) + pow(ray.dir.z, 2);
	eq.b = 2 * (ray.dir.x * co.x + ray.dir.z * co.z);
	eq.c = pow(co.x, 2) + pow(co.z, 2) - pow(cy.radius, 2);
	eq.discriminant = pow(eq.b, 2) - (4 * eq.a * eq.c);
	if (eq.discriminant < 0)
		return (false);
	eq.s1 = (-eq.b - sqrt(eq.discriminant)) / (2 * eq.a);
	eq.s2 = (-eq.b + sqrt(eq.discriminant)) / (2 * eq.a);

	// check that the intersection is within the height of the cylinder (cy.height) by projecting the intersection point onto the cylinder's axis
	if (ft_dot(vec_sub(vec_add(ray.pos, vec_mult(ray.dir, eq.s1)), cy.pos), vec_mult(cy.dir, cy.height)) < 0 || ft_dot(vec_sub(vec_add(ray.pos, vec_mult(ray.dir, eq.s1)), cy.pos), vec_mult(cy.dir, cy.height)) > ft_dot(vec_mult(cy.dir, cy.height), vec_mult(cy.dir, cy.height)))
		eq.s1 = -1;
	if (ft_dot(vec_sub(vec_add(ray.pos, vec_mult(ray.dir, eq.s2)), cy.pos), vec_mult(cy.dir, cy.height)) < 0 || ft_dot(vec_sub(vec_add(ray.pos, vec_mult(ray.dir, eq.s2)), cy.pos), vec_mult(cy.dir, cy.height)) > ft_dot(vec_mult(cy.dir, cy.height), vec_mult(cy.dir, cy.height)))
		eq.s2 = -1;

	if ((eq.s1 > 0 && eq.s1 < len) || (eq.s2 > 0 && eq.s2 < len))
		return (true);
	return (false);
}
