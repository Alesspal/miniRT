/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:42:38 by alesspal          #+#    #+#             */
/*   Updated: 2023/10/17 15:58:55 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"
#include "raytracing.h"

t_vec	get_n_sphere(t_intersection *p)
{
	t_vec		n;
	t_sphere	sphere;

	sphere = (t_sphere)p->shape.sphere;
	n = get_vec(sphere.pos, p->pos);
	return (n);
}

t_vec	get_n_cylinder(t_intersection *p)
{
	t_vec		n;
	t_cylinder	cylinder;
	t_vec		pc;
	t_vec		v;
	float		dot_v_pc;

	cylinder = (t_cylinder)p->shape.cylinder;
	pc = get_vec(cylinder.pos, p->pos);
	v = cylinder.dir;
	dot_v_pc = dot(v, pc);
	v = vec_mult(v, dot_v_pc);
	n = get_vec(v, pc);
	return (n);
}

t_vec	get_n(t_intersection *p)
{
	if (p->shape_type == SPHERE)
		return (get_n_sphere(p));
	else if (p->shape_type == CYLINDER)
		return (get_n_cylinder(p));
	else
		return (p->shape.plane.n);
}
