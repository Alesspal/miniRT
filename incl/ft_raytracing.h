/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raytracing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:51:32 by alesspal          #+#    #+#             */
/*   Updated: 2023/08/28 12:39:20 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RAYTRACING_H
# define FT_RAYTRACING_H

# include "ft_shapes.h"
# include "stdbool.h"

typedef struct s_ambiant_light
{
	int		color;
	float	intensity;
}	t_ambiant_light;

typedef struct s_spot_light
{
	int			id;
	int			color;
	float		intensity;
	t_point3D	coordinate;
}	t_spot_light;

typedef struct s_camera
{
	int			fov;
	t_point3D	coordinate;
	t_vec		orientation;
}	t_camera;

typedef struct s_scene
{
	t_ambiant_light	ambient_light;
	t_spot_light	spot_light;
	t_camera		camera;
	t_shapes		*shapes;
}	t_scene;

typedef struct s_intersection
{
	t_point3D				coordinate;
	t_point2D				pixel_coordinate;
	t_vec					prime_ray;
	t_shape_type			shape_type;
	t_shape					shape;
	struct s_intersection	*next;
}	t_intersection;

bool	intersection(t_point3D p1, t_point3D p2);

t_vec	get_n(t_intersection *p);

#endif