/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalumbi <apalumbi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:48:14 by alesspal          #+#    #+#             */
/*   Updated: 2023/10/18 14:49:37 by apalumbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "vector.h"
# include "color.h"
# include "stdbool.h"

typedef struct s_sphere
{
	t_vec		pos;
	float		radius;
	t_color		color;
}	t_sphere;

typedef struct s_cylinder
{
	t_vec		pos;
	t_vec		dir;
	float		radius;
	float		height;
	t_color		color;
}	t_cylinder;

typedef struct s_plane
{
	t_vec		pos;
	t_vec		normal;
	t_color		color;
}	t_plane;

typedef enum e_shape_type
{
	SPHERE,
	CYLINDER,
	PLANE,
	NO_SHAPE
}	t_shape_type;

typedef union s_shape
{
	t_sphere	sphere;
	t_cylinder	cylinder;
	t_plane		plane;
}	t_shape;

typedef struct s_shapes
{
	int				id;
	t_shape_type	type;
	t_shape			shape;
	bool			display;
	struct s_shapes	*next;
}	t_shapes;

#endif
