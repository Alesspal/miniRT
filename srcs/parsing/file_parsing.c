/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:41:29 by alesspal          #+#    #+#             */
/*   Updated: 2023/10/18 13:04:33 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_scene_parsing.h"
#include <stdbool.h>
#include <fcntl.h>
#include "libft.h"
#include "element_parsing.h"

bool	name_is_incorrect(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (!ft_memcmp(name + (len - 3), ".rt\0", 4))
		return (false);
	return (true);
}

void	free_shapes(t_shapes *shapes)
{
	t_shapes	*next;

	while (shapes)
	{
		next = shapes->next;
		free(shapes);
		shapes = next;
	}
}

int	file_parsing(char *name, t_scene *scene)
{
	int				fd;

	if (!name || name_is_incorrect(name))
		return (printf("name of file is incorrect\n"), 1);
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (printf("opening file failed\n"), 1);
	if (scene_parsing(fd, scene))
	{
		printf("scene parsing interrupted\n");
		free_shapes(scene->shapes);
		scene->shapes = NULL;
		return (1);
	}
	if (close(fd) < 0)
		return (printf("closing file failed\n"), 1);
	return (0);
}
