/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalumbi <apalumbi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:41:32 by alesspal          #+#    #+#             */
/*   Updated: 2023/10/18 15:25:17 by apalumbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "value_parsing.h"
#include "parsing_utils.h"
#include "libft.h"

char	*get_element(char *description, t_element_type *el)
{
	if (!description || *description == '\n')
		return (*el = NOT_IDENTIFIED, NULL);
	description = skip_space(description);
	if (!ft_strncmp(description, "A ", 2))
		*el = AMBIANT_LIGHT;
	else if (!ft_strncmp(description, "L ", 2))
		*el = SPOT_LIGHT;
	else if (!ft_strncmp(description, "C ", 2))
		*el = CAMERA;
	else if (!ft_strncmp(description, "sp ", 3))
		*el = SP;
	else if (!ft_strncmp(description, "cy ", 3))
		*el = CY;
	else if (!ft_strncmp(description, "pl ", 3))
		*el = PL;
	else
		return (*el = NOT_IDENTIFIED, NULL);
	if (*el <= 2)
		return (description + 2);
	else
		return (description + 3);
}

int	get_float(char **description, float *ret)
{
	char	*val;

	if (!description || !*description
		|| !**description || **description == '\n')
		return (1);
	*description = skip_space(*description);
	val = ft_substr(*description, 0, find_comma_or_white_space(*description));
	if (!is_flaot(val))
		return (free(val), 1);
	*ret = ft_atof(val);
	free(val);
	*description = go_next_value(*description);
	return (0);
}

int	get_int(char **description, int *ret)
{
	char	*val;

	if (!description || !*description
		|| !**description || **description == '\n')
		return (1);
	*description = skip_space(*description);
	val = ft_substr(*description, 0, find_comma_or_white_space(*description));
	if (!is_int(val))
		return (free(val), 1);
	*ret = atoi(val);
	free(val);
	*description = go_next_value(*description);
	return (0);
}

int	get_intensity(char **description, float *intensity)
{
	if (get_float(description, intensity))
		return (1);
	return (!is_in_float_range(*intensity, 0.0f, 1.0f));
}

int	get_fov(char **description, int *fov)
{
	if (get_int(description, fov))
		return (1);
	return (!is_in_int_range(*fov, 0, 180));
}
