/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raytracing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:51:32 by alesspal          #+#    #+#             */
/*   Updated: 2023/08/25 15:24:28 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RAYTRACING_H
# define FT_RAYTRACING_H

# include "ft_vector.h"
# include "ft_shapes.h"
# include "libft.h"

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
	t_vec		pos;
	t_vec		dir;
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
	t_vec					p;
	void					*shape;
	struct s_intersection	*next;
}	t_intersection;

// sphere N = P - C
// cylinder N = P - C - dot(cam, P - C) * cam
// plan N = orientation of plan
t_vec	get_normalized_n(t_vec P, int id, t_scene scene);

// Raytracer functions
void	rayshooter(t_data *data, t_camera cam);

#endif