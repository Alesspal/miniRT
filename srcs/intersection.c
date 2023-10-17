/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:43:15 by alesspal          #+#    #+#             */
/*   Updated: 2023/10/17 14:47:11 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"
#include "ft_raytracing.h"
#include <math.h>

void	compute_sp_equation(t_ray ray, t_sphere sp, t_eq *eq);
void	compute_cy_equation(t_ray ray, t_cylinder cy, t_eq *eq);

// Checks if there is an intersection between a ray and a sphere.
// Fills the intersection struct with the closest intersection point 
void	sp_intersection(t_ray ray, t_sphere sp, t_intersection *inter, int id)
{
	t_eq	eq;

	compute_sp_equation(ray, sp, &eq);
	if (eq.discriminant < 0)
		return ;
	if (eq.s1 > 0 && (eq.s2 < 0 || eq.s1 < eq.s2)
		&& (eq.s1 < inter->dist || inter->dist == -1))
	{
		inter->id = id;
		inter->shape.sphere = sp;
		inter->shape_type = SPHERE;
		inter->pos = vec_add(ray.pos, vec_mult(ray.dir, eq.s1));
		inter->dist = eq.s1;
	}
	else if (eq.s2 > 0 && (eq.s1 < 0 || eq.s2 < eq.s1)
		&& (eq.s2 < inter->dist || inter->dist == -1))
	{
		inter->id = id;
		inter->shape.sphere = sp;
		inter->shape_type = SPHERE;
		inter->pos = vec_add(ray.pos, vec_mult(ray.dir, eq.s2));
		inter->dist = eq.s2;
	}
}

// Checks if there is an intersection between a ray and a plane.
// Fills the intersection struct with the closest intersection point
void	pl_intersection(t_ray ray, t_plane pl, t_intersection *inter, int id)
{
	float	t;
	float	ray_n_dot_product;

	pl.n = ft_normalize(pl.n);
	ray_n_dot_product = ft_dot(ray.dir, pl.n);
	if (ray_n_dot_product == 0)
		return ;
	t = ft_dot(vec_sub(pl.pos, ray.pos), pl.n) / ray_n_dot_product;
	if (t > 0 && (t < inter->dist || inter->dist == -1))
	{
		inter->id = id;
		inter->shape.plane = pl;
		inter->shape_type = PLANE;
		inter->pos = vec_add(ray.pos, vec_mult(ray.dir, t));
		inter->dist = t;
	}
}

// Checks if there is an intersection between a ray and a cylinder.
// Fills the intersection struct with the closest intersection point
void	cy_intersection(t_ray ray, t_cylinder cy, t_intersection *inter, int id)
{
	t_eq	eq;

	cy.dir = ft_normalize(cy.dir);
	compute_cy_equation(ray, cy, &eq);
	if (eq.discriminant < 0)
		return ;
	if (eq.s1 > 0 && (eq.s2 < 0 || eq.s1 < eq.s2)
		&& (eq.s1 < inter->dist || inter->dist == -1))
	{
		inter->id = id;
		inter->shape.cylinder = cy;
		inter->shape_type = CYLINDER;
		inter->pos = vec_add(ray.pos, vec_mult(ray.dir, eq.s1));
		inter->dist = eq.s1;
	}
	else if (eq.s2 > 0 && (eq.s1 < 0 || eq.s2 < eq.s1)
		&& (eq.s2 < inter->dist || inter->dist == -1))
	{
		inter->id = id;
		inter->shape.cylinder = cy;
		inter->shape_type = CYLINDER;
		inter->pos = vec_add(ray.pos, vec_mult(ray.dir, eq.s2));
		inter->dist = eq.s2;
	}
}

// Checks if there are intersections with spheres and the casted prime ray.
// Fills the intersection struct with the closest sphere in front of the camera.
// Sets intersection.shape_type to NO_SHAPE if there is no intersection.
void	set_intersection(t_ray ray, t_shapes *shape, t_intersection *inter)
{
	inter->shape_type = NO_SHAPE;
	inter->dist = -1;
	inter->id = -1;
	while (shape)
	{
		if (shape->display == false)
		{
			shape = shape->next;
			continue ;
		}
		if (shape->type == SPHERE)
			sp_intersection(ray, shape->shape.sphere, inter, shape->id);
		if (shape->type == PLANE)
			pl_intersection(ray, shape->shape.plane, inter, shape->id);
		if (shape->type == CYLINDER)
			cy_intersection(ray, shape->shape.cylinder, inter, shape->id);
		shape = shape->next;
	}
}
