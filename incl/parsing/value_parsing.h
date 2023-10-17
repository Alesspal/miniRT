/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:48:50 by alesspal          #+#    #+#             */
/*   Updated: 2023/10/17 15:49:55 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALUE_PARSING_H
# define VALUE_PARSING_H

# include "scene.h"

char	*get_element(char *description, t_element_type *el);
int		get_float(char **description, float *ret);
int		get_int(char **description, int *ret);
int		get_intensity(char **description, float *intensity);
int		get_fov(char **description, int *fov);
int		get_pos(char **description, t_vec *pos);
int		get_dir(char **description, t_vec *dir);
int		get_rgb(char **description, t_color *color);

#endif