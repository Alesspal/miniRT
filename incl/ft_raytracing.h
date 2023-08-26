/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raytracing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:51:32 by alesspal          #+#    #+#             */
/*   Updated: 2023/08/26 17:02:39 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RAYTRACING_H
# define FT_RAYTRACING_H

# include "ft_vector.h"
# include "ft_shapes.h"
# include "stdbool.h"
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
	t_vec					coordinate;
	t_shape_type			shape_type;
	t_shape					shape;
	struct s_intersection	*next;
}	t_intersection;

bool	intersection(t_vec v1, t_vec v2);

t_vec	get_n(t_intersection *p);

// Raytracer functions
void	rayshooter(t_data *data, t_camera cam);

#endif