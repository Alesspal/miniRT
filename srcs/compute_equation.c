/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_equation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:41:52 by alesspal          #+#    #+#             */
/*   Updated: 2023/10/17 14:43:13 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_raytracing.h"
#include <math.h>

void	compute_sp_equation(t_ray ray, t_sphere sp, t_eq *eq)
{
	eq->co = vec_sub(ray.pos, sp.pos);
	eq->b = 2.0 * ft_dot(eq->co, ray.dir);
	eq->c = ft_dot(eq->co, eq->co) - pow(sp.radius, 2);
	eq->discriminant = pow(eq->b, 2) - (4 * eq->c);
	eq->s1 = (-eq->b - sqrt(eq->discriminant)) / 2;
	eq->s2 = (-eq->b + sqrt(eq->discriminant)) / 2;
}

void	compute_cy_equation(t_ray ray, t_cylinder cy, t_eq *eq)
{
	float	dot_product;

	cy.dir = ft_normalize(cy.dir);
	eq->co = vec_sub(ray.pos, cy.pos);
	eq->a = ft_dot(ray.dir, ray.dir) - pow(ft_dot(ray.dir, cy.dir), 2);
	eq->b = 2 * (ft_dot(ray.dir, eq->co) - ft_dot(ray.dir,
				cy.dir) * ft_dot(eq->co, cy.dir));
	eq->c = ft_dot(eq->co, eq->co) - pow(ft_dot(eq->co,
				cy.dir), 2) - pow(cy.radius, 2);
	eq->discriminant = pow(eq->b, 2) - (4 * eq->a * eq->c);
	if (eq->discriminant < 0)
		return ;
	eq->s1 = (-eq->b - sqrt(eq->discriminant)) / (2 * eq->a);
	eq->s2 = (-eq->b + sqrt(eq->discriminant)) / (2 * eq->a);
	dot_product = ft_dot(vec_sub(vec_add(ray.pos, vec_mult(ray.dir,
						eq->s1)), cy.pos), vec_mult(cy.dir, cy.height));
	if (dot_product < 0 || dot_product > ft_dot(vec_mult(cy.dir,
				cy.height), vec_mult(cy.dir, cy.height)))
		eq->s1 = -1;
	dot_product = ft_dot(vec_sub(vec_add(ray.pos, vec_mult(ray.dir,
						eq->s2)), cy.pos), vec_mult(cy.dir, cy.height));
	if (dot_product < 0 || dot_product > ft_dot(vec_mult(cy.dir,
				cy.height), vec_mult(cy.dir, cy.height)))
		eq->s2 = -1;
}
