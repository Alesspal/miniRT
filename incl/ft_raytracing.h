/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raytracing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:51:32 by alesspal          #+#    #+#             */
/*   Updated: 2023/08/25 14:07:15 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RAYTRACING_H
# define FT_RAYTRACING_H

# include "ft_vector.h"
# include "ft_shapes.h"

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
	t_vec		coordinate;
}	t_spot_light;

typedef struct s_camera
{
	int			fov;
	t_vec		coordinate;
	t_vec		orientation;
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
	t_vec					coordinate;
	enum e_shapes			type;
	void					*shape;
	struct s_intersection	*next;
}	t_intersection;

// sphere N = P - C
// cylinder N = P - C - dot(cam, P - C) * cam
// plan N = orientation of plan
t_vec	get_normalized_n_sphere(t_intersection *p);
t_vec	get_normalized_n_cylinder(t_intersection *p);
t_vec	get_normalized_n_plan(t_intersection *p);

#endif