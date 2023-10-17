/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:37:26 by alesspal          #+#    #+#             */
/*   Updated: 2023/10/17 15:43:46 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "shapes.h"
# include "color.h"
# include "my_mlx.h"

typedef struct s_ambiant_light
{
	t_color	color;
	float	intensity;
	t_color	mod_color;
}	t_ambiant_light;

typedef struct s_spot_light
{
	int			id;
	t_color		color;
	float		intensity;
	t_color		mod_color;
	t_vec		pos;
}	t_spot_light;

typedef struct s_virtual_screen
{
	float	width;
	float	height;
	t_vec	center;
	t_vec	top_left;
	float	d;
}	t_virtual_screen;

typedef struct s_camera
{
	int					fov;
	t_vec				pos;
	t_vec				dir;
	t_vec				up;
	t_vec				right;
	t_virtual_screen	v_scr;
}	t_camera;

typedef struct s_scene
{
	t_ambiant_light	ambient_light;
	t_spot_light	spot_light;
	t_camera		camera;
	t_shapes		*shapes;
}	t_scene;

typedef enum e_element_type
{
	NOT_IDENTIFIED = -1,
	AMBIANT_LIGHT,
	SPOT_LIGHT,
	CAMERA,
	SP,
	CY,
	PL
}	t_element_type;

void	init_camera(t_camera *cam, float aspect_ratio);
void	init_scene(t_scene *scene);
void	draw_scene(t_data *data, t_scene scene);

#endif