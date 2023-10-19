/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:48:11 by alesspal          #+#    #+#             */
/*   Updated: 2023/10/19 11:11:51 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H

# include "scene.h"
# include "point.h"
# include "stdbool.h"

typedef struct s_intersection
{
	t_vec					pos;
	t_point2D				pixel;
	t_vec					prime_ray;
	t_shape_type			shape_type;
	t_shape					shape;
	float					dist;
	int						id;
}	t_intersection;

typedef struct s_ray
{
	t_vec		pos;
	t_vec		dir;
}	t_ray;

// Struct for a quadratic equation
typedef struct s_eq
{
	t_vec	co;
	float	a;
	float	b;
	float	c;
	float	discriminant;
	float	s1;
	float	s2;
}	t_eq;

// Raytracer functions
void	set_prime_ray(t_ray *pr, t_mlx_win win, t_camera cam, t_point2D p);
void	set_intersection(t_ray ray, t_shapes *shape, t_intersection *inter);
bool	is_intersection(t_vec p1, t_vec p2, t_shapes *shape, int id);
t_vec	get_n(t_intersection *p);
t_color	phong(t_scene scene, t_intersection *p);
t_color	shade(t_scene scene, t_color color);
void	remove_overlapping_objects(t_shapes *shapes);

#endif