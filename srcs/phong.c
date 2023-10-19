/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:42:19 by alesspal          #+#    #+#             */
/*   Updated: 2023/10/19 11:24:48 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"
#include "vector.h"
#include "color.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

t_color	i_diffuse(t_scene scene, t_intersection *p)
{
	t_color	i_diffuse;
	t_vec	n;
	t_vec	l;
	float	dot_nl;

	n = normalize(get_n(p));
	l = normalize(get_vec(p->pos, scene.spot_light.pos));
	dot_nl = dot(n, l);
	i_diffuse = change_intesity(scene.spot_light.mod_color, fmax(0, dot_nl));
	return (i_diffuse);
}

t_color	phong(t_scene scene, t_intersection *p)
{
	t_color	shape_color;
	t_color	final_color;

	final_color = addition_color(scene.ambient_light.mod_color,
			i_diffuse(scene, p));
	if (p->shape_type == SPHERE)
		shape_color = p->shape.sphere.color;
	else if (p->shape_type == CYLINDER)
		shape_color = p->shape.cylinder.color;
	else
		shape_color = p->shape.plane.color;
	final_color = multiplication_color(final_color, shape_color);
	return (final_color);
}

t_color	shade(t_scene scene, t_color color)
{
	if (fabs(0.0f - scene.spot_light.intensity) > 0.0001f)
	{
		color = change_intesity(color,
				1.0f - (scene.spot_light.intensity
					- scene.ambient_light.intensity));
	}
	return (color);
}
