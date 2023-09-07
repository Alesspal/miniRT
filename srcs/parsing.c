#include "libft.h"
#include "ft_shapes.h"
#include "ft_raytracing.h"
#include <stdlib.h>
#include <math.h>

/* int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	if (name_is_incorrect(argv[1]))
		printf("name is incorrect\n");
	else
		printf("name is correct\n");
	return (0);
} */

/* int main (int argc, char **argv)
{
	if (argc != 2)
	{
		printf("put float nb\n");
		return (1);
	}
	if(is_flaot(argv[1]))
		printf("is float\n");
	else
		printf("is not\n");
	return (0);
} */

/* int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("put file\n");
		return (1);
	}
	int	fd = open(argv[1], O_RDONLY);
	t_element_type el;

	if (fd < 0)
		ft_fatal_error("opening file failed", 1);
	char	*line;
	char	*description;
	t_scene	scene;
	while ((line = get_next_line(fd)))
	{
		printf("description = %s\n", line);
		if (line[0] != '\0' && line[0] != '\n')
		{
			if (element_parsing(&scene, line, el))
			{
				printf("parsing error\n");
				return (1);
			}
		}
		free(line);
	}
	display_scene(scene);
	return (0);
} */
