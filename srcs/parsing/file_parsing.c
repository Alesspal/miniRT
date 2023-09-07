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

int	file_parsing(char *name, t_scene *scene)
{
	int				fd;

	if (!name || name_is_incorrect(name))
		return (printf("name of file is incorrect\n"), 1);
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (printf("opening file failed\n"), 1);
	if (scene_parsing(fd, scene))
		return (printf("scene parsing interrupted\n"), 1);
	if (close(fd) < 0)
		return (printf("closing file failed\n"), 1);
	return (0);
}

/* int	main(int argc, char **argv)
{
	t_scene	scene = {0};

	if (argc != 2)
		return (printf("put file\n"), 1);
	if (file_parsing(argv[1], &scene))
	{
		printf("parsing failed\n");
		return (1);
	}
	display_scene(scene);
	// while (1);
	return (0);
} */
