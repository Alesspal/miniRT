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

int	scene_parsing(int fd, t_scene *scene)
{
	char			*line;
	char			*description;
	t_element_type	el;
	t_element_type	*el_tab;

	el_tab = init_el_tab();
	if (!el_tab)
		return (printf("el_tab initialisation failed\n"), 1);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\0' && line[0] != '\n')
		{
			description = get_element(line, &el);
			if (check_el_is_already_set_and_update(el_tab, el))
				return (printf("duplication of elements detected\n"), 1);
			if (element_parsing(scene, description, el))
				return (printf("description error : %s\n", line), 1);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (check_missing_elements(el_tab))
		return (printf("missing scene element in file\n"), 1);
	return (0);
}
