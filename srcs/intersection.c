#include "ft_mlx.h"
#include "ft_raytracing.h"
#include <math.h>

// Checks if there are intersections with spheres and the casted prime ray.
// Fills the intersection struct with the closest sphere in front of the camera.
// Sets intersection.shape_type to NO_SHAPE if there is no intersection.
void	fill_intersection(t_ray ray, t_shapes *shape, t_intersection *inter)
{
	inter->shape_type = NO_SHAPE;
	inter->dist = -1;
	while (shape)
	{
		if (shape->type == SPHERE)
		{
			sp_intersection(ray, shape->shape.sphere, inter);
		}

		// plane
		if (shape->type == PLANE)
		{
			pl_intersection(ray, shape->shape.plane, inter);
		}

		// cylinder
		if (shape->type == CYLINDER)
		{
			cy_intersection(ray, shape->shape.cylinder, inter);
		}

		shape = shape->next;
	}
}

// Checks if there is an intersection between a ray and a sphere.
// Fills the intersection struct with the closest intersection point 
// if there is one.
void	sp_intersection(t_ray ray, t_sphere sp, t_intersection *intersection)
{
	t_eq	eq;

	eq.co = vec_sub(ray.pos, sp.pos);
	eq.b = 2.0 * ft_dot(eq.co, ray.dir);
	eq.c = ft_dot(eq.co, eq.co) - pow(sp.radius, 2);
	eq.discriminant = pow(eq.b, 2) - (4 * eq.c);
	if (eq.discriminant < 0)
		return ;
	eq.s1 = (-eq.b - sqrt(eq.discriminant)) / 2;
	eq.s2 = (-eq.b + sqrt(eq.discriminant)) / 2;
	if (eq.s1 > 0 && (eq.s2 < 0 || eq.s1 < eq.s2)
		&& (eq.s1 < intersection->dist || intersection->dist == -1))
	{
		intersection->shape.sphere = sp;
		intersection->shape_type = SPHERE;
		intersection->pos = vec_add(ray.pos, vec_mult(ray.dir, eq.s1));
		intersection->dist = eq.s1;
	}
	else if (eq.s2 > 0 && (eq.s1 < 0 || eq.s2 < eq.s1)
		&& (eq.s2 < intersection->dist || intersection->dist == -1))
	{
		intersection->shape_type = SPHERE;
		intersection->pos = vec_add(ray.pos, vec_mult(ray.dir, eq.s2));
		intersection->dist = eq.s2;
	}
}

// Checks if there is an intersection between a ray and a plane.
// Fills the intersection struct with the closest intersection point
// if there is one.
void	pl_intersection(t_ray ray, t_plane pl, t_intersection *intersection)
{
	float	t;
	float	ray_n_dot_product;

	pl.normal = ft_normalize(pl.normal);
	ray_n_dot_product = ft_dot(ray.dir, pl.normal);
	if (ray_n_dot_product == 0)
		return ;
	t = ft_dot(vec_sub(pl.pos, ray.pos), pl.normal) / ray_n_dot_product;
	if (t > 0 && (t < intersection->dist || intersection->dist == -1))
	{
		intersection->shape.plane = pl;
		intersection->shape_type = PLANE;
		intersection->pos = vec_add(ray.pos, vec_mult(ray.dir, t));
		intersection->dist = t;
	}
}

// example function to check for intersections between a ray and a cylinder
// bool intersectRayCylinder(const Ray* ray, const Cylinder* cylinder) {
//     t_vec oc = vecSubtract(&ray->origin, &cylinder->position);
//     double a = vecDot(&ray->direction, &ray->direction);
//     double b = 2 * vecDot(&oc, &ray->direction);
//     double c = vecDot(&oc, &oc) - cylinder->radius * cylinder->radius;

//     double discriminant = b * b - 4 * a * c;

//     if (discriminant < 0) {
//         // No intersection
//         return false;
//     }

//     // You might need to refine this based on your specific requirements
//     // For example, you might need to check if the intersection point is within
//     // the height of the cylinder.

//     // If you reach this point, the ray intersects the infinite cylinder
//     return true;
// }

// Checks if there is an intersection between a ray and a cylinder.
// Fills the intersection struct with the closest intersection point
// if there is one.
void cy_intersection(t_ray ray, t_cylinder cy, t_intersection *intersection)
{
	t_vec	oc;
	t_eq	eq;

	cy.dir = ft_normalize(cy.dir);
	oc = vec_sub(ray.pos, cy.pos);
	eq.a = ft_dot(ray.dir, ray.dir) - pow(ft_dot(ray.dir, cy.dir), 2);
	eq.b = 2 * (ft_dot(ray.dir, oc) - ft_dot(ray.dir, cy.dir) * ft_dot(oc, cy.dir));
	eq.c = ft_dot(oc, oc) - pow(ft_dot(oc, cy.dir), 2) - pow(cy.radius, 2);
	eq.discriminant = pow(eq.b, 2) - (4 * eq.a * eq.c);
	if (eq.discriminant < 0)
		return ;
	eq.s1 = (-eq.b - sqrt(eq.discriminant)) / (2 * eq.a);
	eq.s2 = (-eq.b + sqrt(eq.discriminant)) / (2 * eq.a);

	// check that the intersection is within the height of the cylinder (cy.height) by projecting the intersection point onto the cylinder's axis
	if (ft_dot(vec_sub(vec_add(ray.pos, vec_mult(ray.dir, eq.s1)), cy.pos), vec_mult(cy.dir, cy.height)) < 0 || ft_dot(vec_sub(vec_add(ray.pos, vec_mult(ray.dir, eq.s1)), cy.pos), vec_mult(cy.dir, cy.height)) > ft_dot(vec_mult(cy.dir, cy.height), vec_mult(cy.dir, cy.height)))
		eq.s1 = -1;
	if (ft_dot(vec_sub(vec_add(ray.pos, vec_mult(ray.dir, eq.s2)), cy.pos), vec_mult(cy.dir, cy.height)) < 0 || ft_dot(vec_sub(vec_add(ray.pos, vec_mult(ray.dir, eq.s2)), cy.pos), vec_mult(cy.dir, cy.height)) > ft_dot(vec_mult(cy.dir, cy.height), vec_mult(cy.dir, cy.height)))
		eq.s2 = -1;

	if (eq.s1 > 0 && (eq.s2 < 0 || eq.s1 < eq.s2) && (eq.s1 < intersection->dist || intersection->dist == -1))
	{
		intersection->shape.cylinder = cy;
		intersection->shape_type = CYLINDER;
		intersection->pos = vec_add(ray.pos, vec_mult(ray.dir, eq.s1));
		intersection->dist = eq.s1;
	}
	else if (eq.s2 > 0 && (eq.s1 < 0 || eq.s2 < eq.s1) && (eq.s2 < intersection->dist || intersection->dist == -1))
	{
		intersection->shape.cylinder = cy;
		intersection->shape_type = CYLINDER;
		intersection->pos = vec_add(ray.pos, vec_mult(ray.dir, eq.s2));
		intersection->dist = eq.s2;
	}
}
