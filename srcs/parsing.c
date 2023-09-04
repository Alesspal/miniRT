#include "libft.h"
#include "ft_shapes.h"
#include "ft_raytracing.h"
#include <stdlib.h>
#include <fcntl.h>

bool	name_is_incorrect(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (!ft_memcmp(name + (len - 3), ".rt\0", 4))
		return (false);
	return (true);
}

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

char	*skip_space(char *str)
{
	while (*str && ft_is_white_space(*str))
		str++;
	return (str);
}

// modifier car pas propre (faire un structure elem_info et mettre dans un boucle)
char	*find_element(char *description, t_element_type *el)
{
	if (!description)
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
	while ((line = get_next_line(fd)))
	{
		line = find_element(line, &el);
		printf("el = %i\n", el);
		printf("line = %s\n", line);
	}
	return (0);
} */

/* float	ft_atof(char *nb)
{

} */

bool	ft_isint(char *str)
{
	int		i;
	int		len;
	long	nb;

	if (!str)
		return (false);
	len = 0;
	i = -1;
	str = skip_space(str);
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[++i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (false);
		len++;
	}
	if (len == 0 || len > 10)
		return (false);
	return (true);
}

bool	is_flaot(char *str)
{
	int	digit_count;
	int	point_count;

	if (!str)
		return (false);
	digit_count = 0;
	point_count = 0;
	str = skip_space(str);
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str))
			digit_count++;
		else if (*str == '.')
		{
			point_count++;
			if (point_count > 1 || digit_count == 0)
				return (false);
		}
		else
			return (false);
		str++;
	}
	return (true);
}

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

int find_comma_or_white_space(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && !ft_is_white_space(str[i]) && str[i] != ',')
		i++;
	return (i);
}

char *go_next_value(char *description)
{
	if (!description || !*description)
		return (description);
	description = skip_space(description);
	while (*description && *description != ',' && !ft_is_white_space(*description))
		description++;
	if (*description == ',')
		description++;
	return (description);
}

int	get_float(char **description, float *ret)
{
	char	*val;

	if (!description || !*description || !**description)
		return (1);
	*description = skip_space(*description);
	val = ft_substr(*description, 0, find_comma_or_white_space(*description));
	printf("val = '%s'\n", val);
	if (!is_flaot(val))
		return (1);
	printf("description 2 : %s\n", *description);
	*ret = atof(val);
	free(val);
	*description = go_next_value(*description);
	return (0);
}

int	get_int(char **description, int *ret)
{
	char	*val;

	if (!description || !*description)
		return (1);
	*description = skip_space(*description);
	val = ft_substr(*description, 0, find_comma_or_white_space(*description));
	printf("val = '%s'\n", val);
	if (!ft_isint(val))
		return (1);
	printf("description 2 : '%s'\n", *description);
	*ret = atoi(val);
	free(val);
	*description = go_next_value(*description);
	return (0);
}

int	get_3_int(char **description, int *n1, int *n2, int *n3)
{
	if (!description|| !*description)
		return (1);
	if (get_int(description, n1))
		return (1);
	if (get_int(description, n2))
		return (1);
	if (get_int(description, n3))
		return (1);
	return (0);
}

int	get_3_float(char **description, float *n1, float *n2, float *n3)
{
	if (!description)
		return (1);
	if (get_float(description, n1))
		return (1);
	if (get_float(description, n2))
		return (1);
	if (get_float(description, n3))
		return (1);
	return (0);
}

bool is_end_of_line(char *line)
{
	line = skip_space(line);
	if (line && *line)
		return (false);
	return (true);
}

int	ambient_light_parsing(char *description, t_ambiant_light *ambiant_light)
{
	if (!description)
		return (1);
	if (get_float(&description, &ambiant_light->intensity))
		return (1);
	printf("description1 : '%s'\n", description);
	if (get_3_int(&description, &ambiant_light->color.r,
		&ambiant_light->color.g, &ambiant_light->color.b))
		return (1);
	if (!is_end_of_line(description))
		return (1);
	return (0);
}

int spot_light_parsing(char *description, t_spot_light *spot_light)
{
	if (!description)
		return (1);
	if (get_3_float(&description, &spot_light->pos.x,
		&spot_light->pos.y, &spot_light->pos.z))
		return (1);
	if (get_float(&description, &spot_light->intensity))
		return (1);
	if (get_3_int(&description, &spot_light->color.r,
		&spot_light->color.g, &spot_light->color.b))
		return (1);
	if (!is_end_of_line(description))
		return (1);
	return (0);
}

int	camera_parsing(char *description, t_camera *camera)
{
	if (!description)
		return (1);
	if (get_3_float(&description, &camera->pos.x,
		&camera->pos.y, &camera->pos.z))
		return (1);
	if (get_3_float(&description, &camera->dir.x,
		&camera->dir.y, &camera->dir.z))
		return (1);
	if (get_int(&description, &camera->fov))
		return (1);
	if (!is_end_of_line(description))
		return (1);
	return (0);
}

int sphere_parsing(char *description, t_sphere *sphere)
{
	if (!description)
		return (1);
	if (get_3_float(&description, &sphere->pos.x,
		&sphere->pos.y, &sphere->pos.z))
		return (1);
	if (get_float(&description, &sphere->diameter))
		return (1);
	if (get_3_int(&description, &sphere->color.r,
		&sphere->color.g, &sphere->color.b))
		return (1);
	if (!is_end_of_line(description))
		return (1);
	return (0);
}

int	plan_parsing(char *description, t_plan *plan)
{
	if (!description)
		return (1);
	if (get_3_float(&description, &plan->pos.x,
		&plan->pos.y, &plan->pos.z))
		return (1);
	if (get_3_float(&description, &plan->dir.x,
		&plan->dir.y, &plan->dir.z))
		return (1);
	if (get_3_int(&description, &plan->color.r,
		&plan->color.g, &plan->color.b))
		return (1);
	if (!is_end_of_line(description))
		return (1);
	return (0);
}

int	cylindre_parsing(char *description, t_cylinder *cylinder)
{
	if (!description)
		return (1);
	if (get_3_float(&description, &cylinder->pos.x,
		&cylinder->pos.y, &cylinder->pos.z))
		return (1);
	if (get_3_float(&description, &cylinder->dir.x,
		&cylinder->dir.y, &cylinder->dir.z))
		return (1);
	if (get_float(&description, &cylinder->diameter))
		return (1);
	if (get_float(&description, &cylinder->height))
		return (1);
	if (get_3_int(&description, &cylinder->color.r,
		&cylinder->color.g, &cylinder->color.b))
		return (1);
	if (!is_end_of_line(description))
		return (1);
	return (0);
}

int	shapes_pasing(char *description, t_shapes *shapes)
{

}

void	display_ambient_light(t_ambiant_light ambient_light)
{
	printf("-----AMBIENT LIGHT SAVE-----\n");
	printf("intensity : %f\n", ambient_light.intensity);
	printf("rgb = %d, %d, %d\n", ambient_light.color.r, ambient_light.color.g, ambient_light.color.b);
	printf("----------------------------\n");
}

void	display_spot_light(t_spot_light spot_light)
{
	printf("-----SPOT LIGHT SAVE-----\n");
	printf("pos : %f, %f, %f\n", spot_light.pos.x, spot_light.pos.y, spot_light.pos.z);
	printf("intensity : %f\n", spot_light.intensity);
	printf("rgb = %d, %d, %d\n", spot_light.color.r, spot_light.color.g, spot_light.color.b);
	printf("-------------------------\n");
}

void	display_camera_light(t_camera camera)
{
	printf("-----CAMERA SAVE-----\n");
	printf("pos : %f, %f, %f\n", camera.pos.x, camera.pos.y, camera.pos.z);
	printf("dir : %f, %f, %f\n", camera.dir.x, camera.dir.y, camera.dir.z);
	printf("fov : %d\n", camera.fov);
	printf("---------------------\n");
}

int	line_parsing(t_scene *scene, char *description)
{
	t_element_type el;

	if (!description)
		return (1);
	description = find_element(description, &el);
	if (!description)
		return (1);
	description = skip_space(description);
	if (el == AMBIANT_LIGHT)
	{
		if (ambient_light_parsing(description, &scene->ambient_light))
			return (1);
		display_ambient_light(scene->ambient_light);
	}
	else if (el == SPOT_LIGHT)
	{
		if (spot_light_parsing(description, &scene->spot_light))
			return (1);
		display_spot_light(scene->spot_light);
	}
	else if (el == CAMERA)
	{
		if (camera_parsing(description, &scene->camera))
			return (1);
		display_camera_light(scene->camera);
	}
	/* else if (el == SP)
		scene->shapes = shapes_pasing(&scene->shapes, description); */
	else
		return (1);
	return (0);
}

int main(int argc, char **argv)
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
			if (line_parsing(&scene, line))
			{
				printf("parsing error\n");
				return (1);
			}
		}
		free(line);
	}
	return (0);
}

/* t_scene file_parsing(char *name)
{
	int		fd;
	char	*line;
	t_scene	scene;

	if (!name || name_is_incorrect(name))
		ft_fatal_error("name of file is incorrect\n", 1);
	fd = open(name, O_RDONLY);
	if (fd < 0)
		ft_fatal_error("opening file failed\n", 1);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\0' && line[0] != '\n')
			line_parsing(&scene, line);
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) < 0)
		ft_fatal_error("closing file failed\n", 1);
	return (scene);
} */
