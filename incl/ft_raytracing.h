/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raytracing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:51:32 by alesspal          #+#    #+#             */
/*   Updated: 2023/08/24 15:56:31 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RAYTRACING_H
#define FT_RAYTRACING_H

#include "ft_vector.h"
#include "ft_shapes.h"
#include "../libft/libft.h"

// tout les processus du raytraing vont aller dans ce fichier

typedef struct s_ambiant_light
{
	int	color;
	int	intensity;
}	t_ambiant_light;

typedef struct s_spot_light
{
	int			id;
	int			color;
	int			intensity;
	t_vector	coordinate;
}	t_spot_light;

typedef struct s_camera
{
	int			fov;
	t_vector	coordinate;
	t_vector	orientation;
}	t_camera;

typedef struct s_scene
{
	t_ambiant_light	ambient_light;
	t_spot_light	*spot_light;
	t_camera		camera;
	t_shapes		*shapes;
}	t_scene;

typedef struct s_intersection
{
	t_vector				p;
	void					*shape;
	struct s_intersection	*next;
}	t_intersection;

// sphere N = P - C
// cylinder N = P - C - dot(cam, P - C) * cam
// plan N = orientation of plan
t_vector	get_normalized_n(t_vector P, int id, t_scene scene);

#endif