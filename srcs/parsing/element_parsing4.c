/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_parsing4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalumbi <apalumbi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:41:24 by alesspal          #+#    #+#             */
/*   Updated: 2023/10/18 15:29:28 by apalumbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element_parsing.h"
#include <stdlib.h>
#include "libft.h"
#include "value_parsing.h"

t_element_type	*init_el_tab(void)
{
	int				i;
	t_element_type	*el_tab;

	el_tab = malloc(sizeof(t_element_type) * 3);
	if (!el_tab)
		return (NULL);
	i = -1;
	while (++i < 3)
		el_tab[i] = 0;
	return (el_tab);
}

bool	check_missing_elements(t_element_type *el_tab)
{
	return (el_tab[AMBIANT_LIGHT] != 1
		|| el_tab[SPOT_LIGHT] != 1
		|| el_tab[CAMERA] != 1);
}

int	check_el_is_already_set_and_update(t_element_type *tab, t_element_type el)
{
	if (el == AMBIANT_LIGHT || el == SPOT_LIGHT || el == CAMERA)
	{
		if (tab[el] == 1)
			return (1);
		tab[el] = 1;
	}
	return (0);
}

int	handle_line_processing(char *line, t_element_type *el_tab, t_scene *scene)
{
	char			*description;
	t_element_type	el;

	if (line[0] == '\0' || line[0] == '\n')
		return (0);
	description = get_element(line, &el);
	if (check_el_is_already_set_and_update(el_tab, el))
	{
		printf("duplication of elements detected\n");
		return (1);
	}
	if (element_parsing(scene, description, el))
	{
		printf("description error : %s\n", line);
		return (1);
	}
	return (0);
}

int	scene_parsing(int fd, t_scene *scene)
{
	char			*line;
	t_element_type	*el_tab;

	el_tab = init_el_tab();
	if (!el_tab)
		return (printf("el_tab initialisation failed\n"), 1);
	line = get_next_line(fd);
	while (line)
	{
		if (handle_line_processing(line, el_tab, scene))
		{
			free(line);
			free(el_tab);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (check_missing_elements(el_tab))
	{
		free(el_tab);
		printf("missing scene element in file\n");
		return (1);
	}
	return (free(el_tab), 0);
}
