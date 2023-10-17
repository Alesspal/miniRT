/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:41:09 by alesspal          #+#    #+#             */
/*   Updated: 2023/10/17 14:43:13 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element_parsing.h"
#include "parsing_utils.h"
#include "value_parsing.h"

int	element_parsing(t_scene *scene, char *description, t_element_type el)
{
	if (!description)
		return (1);
	description = skip_space(description);
	if (el == AMBIANT_LIGHT)
		return (ambient_light_parsing(description, &scene->ambient_light));
	if (el == SPOT_LIGHT)
		return (spot_light_parsing(description, &scene->spot_light));
	if (el == CAMERA)
		return (camera_parsing(description, &scene->camera));
	if (el == SP || el == CY || el == PL)
		return (shapes_parsing(description, &scene->shapes, el));
	return (1);
}

int	ambient_light_parsing(char *description, t_ambiant_light *ambiant_light)
{
	if (!description)
		return (1);
	if (get_intensity(&description, &ambiant_light->intensity))
		return (1);
	if (get_rgb(&description, &ambiant_light->color))
		return (1);
	ambiant_light->mod_color = change_intesity(ambiant_light->color,
			ambiant_light->intensity);
	if (!is_end_of_line(description))
		return (1);
	return (0);
}

int	spot_light_parsing(char *description, t_spot_light *spot_light)
{
	if (!description)
		return (1);
	if (get_pos(&description, &spot_light->pos))
		return (1);
	if (get_intensity(&description, &spot_light->intensity))
		return (1);
	if (get_rgb(&description, &spot_light->color))
		return (1);
	spot_light->mod_color = change_intesity(spot_light->color,
			spot_light->intensity);
	if (!is_end_of_line(description))
		return (1);
	return (0);
}

int	camera_parsing(char *description, t_camera *camera)
{
	if (!description)
		return (1);
	if (get_pos(&description, &camera->pos))
		return (1);
	if (get_dir(&description, &camera->dir))
		return (1);
	if (get_fov(&description, &camera->fov))
		return (1);
	if (!is_end_of_line(description))
		return (1);
	return (0);
}
