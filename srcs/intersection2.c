/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:47:15 by alesspal          #+#    #+#             */
/*   Updated: 2023/10/19 10:32:04 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"
#include <math.h>

void	compute_sp_equation(t_ray ray, t_sphere sp, t_eq *eq);
void	compute_cy_equation(t_ray ray, t_cylinder cy, t_eq *eq);

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
	ray.dir = normalize(dir);
	co = vec_sub(ray.pos, shape->shape.sphere.pos);
	eq.a = 1;
	eq.b = 2.0 * dot(co, ray.dir);
	eq.c = dot(co, co) - pow(shape->shape.sphere.radius, 2);
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
	ray.dir = normalize(dir);
	shape->shape.plane.normal = normalize(shape->shape.plane.normal);
	ray_n_dot_product = dot(ray.dir, shape->shape.plane.normal);
	if (ray_n_dot_product == 0)
		return (false);
	t = dot(vec_sub(shape->shape.plane.pos, ray.pos),
			shape->shape.plane.normal) / ray_n_dot_product;
	if (t > 0 && t < vec_size(dir))
		return (true);
	return (false);
}

// Return whether or not there is an intersection with a cylinder
// between two points.
bool	cy_intersection_between_points(t_vec p1, t_vec p2, t_shapes *shape)
{
	t_ray		ray;
	t_vec		dir;
	float		len;
	t_cylinder	cy;
	t_eq		eq;

	cy = shape->shape.cylinder;
	cy.dir = normalize(cy.dir);
	dir = vec_sub(p2, p1);
	len = vec_size(dir);
	ray.pos = p1;
	ray.dir = normalize(dir);
	compute_cy_equation(ray, cy, &eq);
	if (eq.discriminant < 0)
		return (false);
	if ((eq.s1 > 0 && eq.s1 < len) || (eq.s2 > 0 && eq.s2 < len))
		return (true);
	return (false);
}

// Return whether or not there is an intersection with a shape
// between two points.
bool	is_intersection(t_vec p1, t_vec p2, t_shapes *shape, int id)
{
	while (shape)
	{
		if (shape->id == id || shape->display == false)
		{
			shape = shape->next;
			continue ;
		}
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
