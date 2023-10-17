/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_parsing.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:48:46 by alesspal          #+#    #+#             */
/*   Updated: 2023/10/17 14:48:51 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_PARSING_H
# define ELEMENT_PARSING_H

# include "ft_raytracing.h"

int	element_parsing(t_scene *scene, char *description, t_element_type el);
int	ambient_light_parsing(char *description, t_ambiant_light *ambiant_light);
int	spot_light_parsing(char *description, t_spot_light *spot_light);
int	camera_parsing(char *description, t_camera *camera);
int	sphere_parsing(char *description, t_sphere *sphere);
int	cylindre_parsing(char *description, t_cylinder *cylinder);
int	plane_parsing(char *description, t_plane *plan);
int	shapes_parsing(char *description, t_shapes **shapes, t_element_type el);
int	scene_parsing(int fd, t_scene *scene);

#endif