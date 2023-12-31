/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_scene_parsing.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:48:48 by alesspal          #+#    #+#             */
/*   Updated: 2023/10/18 09:29:14 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_SCENE_PARSING_H
# define FILE_SCENE_PARSING_H

# include "scene.h"

int		file_parsing(char *name, t_scene *scene);
void	free_shapes(t_shapes *shapes);

#endif