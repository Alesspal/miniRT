#include "libft.h"
#include "ft_shapes.h"
#include "ft_raytracing.h"
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>

char	*skip_space(char *str)
{
	while (*str && ft_is_white_space(*str))
		str++;
	return (str);
}

#pragma region DISPLAY

void	display_ambient_light(t_ambiant_light ambient_light)
{
	printf("-----AMBIENT LIGHT-----\n");
	printf("intensity : %f\n", ambient_light.intensity);
	printf("rgb : %d, %d, %d\n", ambient_light.color.r, ambient_light.color.g, ambient_light.color.b);
	printf("-----------------------\n");
}

void	display_spot_light(t_spot_light spot_light)
{
	printf("-----SPOT LIGHT-----\n");
	printf("pos : %f, %f, %f\n", spot_light.pos.x, spot_light.pos.y, spot_light.pos.z);
	printf("intensity : %f\n", spot_light.intensity);
	printf("rgb : %d, %d, %d\n", spot_light.color.r, spot_light.color.g, spot_light.color.b);
	printf("--------------------\n");
}

void	display_camera(t_camera camera)
{
	printf("-----CAMERA-----\n");
	printf("pos : %f, %f, %f\n", camera.pos.x, camera.pos.y, camera.pos.z);
	printf("dir : %f, %f, %f\n", camera.dir.x, camera.dir.y, camera.dir.z);
	printf("fov : %d\n", camera.fov);
	printf("----------------\n");
}

void	display_sphere(t_sphere sphere)
{
	printf("-----SPHERE-----\n");
	printf("pos : %f, %f, %f\n", sphere.pos.x, sphere.pos.y, sphere.pos.z);
	printf("diameter : %f\n", sphere.diameter);
	printf("rgb : %d, %d, %d\n", sphere.color.r, sphere.color.g, sphere.color.b);
	printf("----------------\n");
}

void	display_cylinder(t_cylinder cylinder)
{
	printf("-----CYLINDER-----\n");
	printf("pos : %f, %f, %f\n", cylinder.pos.x, cylinder.pos.y, cylinder.pos.z);
	printf("dir : %f, %f, %f\n", cylinder.dir.x, cylinder.dir.y, cylinder.dir.z);
	printf("diameter : %f\n", cylinder.diameter);
	printf("height : %f\n", cylinder.height);
	printf("rgb : %d, %d, %d\n", cylinder.color.r, cylinder.color.g, cylinder.color.b);
	printf("------------------\n");
}

void	display_plan(t_plan plan)
{
	printf("-----PLAN-----\n");
	printf("pos : %f, %f, %f\n", plan.pos.x, plan.pos.y, plan.pos.z);
	printf("dir : %f, %f, %f\n", plan.dir.x, plan.dir.y, plan.dir.z);
	printf("rgb : %d, %d, %d\n", plan.color.r, plan.color.g, plan.color.b);
	printf("--------------\n");
}

void	display_shapes(t_shapes *shapes)
{
	while (shapes)
	{
		printf("ID = %d\n", shapes->id);
		if (shapes->type == SHPERE)
			display_sphere(shapes->shape.sphere);
		else if (shapes->type == CYLINDER)
			display_cylinder(shapes->shape.cylinder);
		else if (shapes->type == PLAN)
			display_plan(shapes->shape.plan);
		shapes = shapes->next;
	}
}

void	display_scene(t_scene scene)
{
	printf("-----PARSING DISPLAY-----\n");
	display_ambient_light(scene.ambient_light);
	display_spot_light(scene.spot_light);
	display_camera(scene.camera);
	display_shapes(scene.shapes);
}

#pragma endregion

#pragma region Checker

bool	is_int(char *str)
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

bool	name_is_incorrect(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (!ft_memcmp(name + (len - 3), ".rt\0", 4))
		return (false);
	return (true);
}

bool	is_in_int_range(int val, int range_min, int range_max)
{
	return (val >= range_min && val <= range_max);
}

bool	is_in_float_range(float val, float range_min, float range_max)
{
	float	precision;

	precision = 0.00001f;
	return (val + precision >= range_min && val - precision <= range_max);
}

bool	is_end_of_line(char *line)
{
	line = skip_space(line);
	if (line && *line)
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

#pragma endregion

int	check_sign(char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	return (sign);
}

float	ft_atof(char *nb)
{
	int		sign;
	int		div;
	double	integer_part;
	double	fraction_part;

	nb = skip_space(nb);
	if (!nb)
		return (0.0f);
	div = 1;
	integer_part = 0.0f;
	fraction_part = 0.0f;
	sign = check_sign(&nb);
	while (ft_isdigit(*nb))
		integer_part = integer_part * 10 + (*nb++ - '0');
	if (*nb == '.')
		nb++;
	while (ft_isdigit(*nb))
	{
		fraction_part = fraction_part * 10 + (*nb++ - '0');
		div *= 10;
	}
	return (integer_part + fraction_part / div);
}

int	find_comma_or_white_space(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && !ft_is_white_space(str[i]) && str[i] != ',')
		i++;
	return (i);
}

char	*go_next_value(char *descr)
{
	if (!descr || !*descr)
		return (descr);
	descr = skip_space(descr);
	while (*descr && *descr != ',' && !ft_is_white_space(*descr))
		descr++;
	if (*descr == ',')
		descr++;
	return (descr);
}

#pragma region Get

char	*get_element(char *description, t_element_type *el)
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

int	get_float(char **description, float *ret)
{
	char	*val;

	if (!description || !*description || !**description)
		return (1);
	*description = skip_space(*description);
	val = ft_substr(*description, 0, find_comma_or_white_space(*description));
	/* printf("val = '%s'\n", val); */
	if (!is_flaot(val))
		return (1);
	/* printf("description 2 : %s\n", *description); */
	*ret = ft_atof(val);
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
	/* printf("val = '%s'\n", val); */
	if (!is_int(val))
		return (1);
	/* printf("description 2 : '%s'\n", *description); */
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

int	get_pos(char **description, t_point3D *pos)
{
	if (!description || !*description)
		return (1);
	if (get_float(description, &pos->x))
		return (1);
	if (get_float(description, &pos->y))
		return (1);
	if (get_float(description, &pos->z))
		return (1);
	return (0);
}

int	get_dir(char **description, t_vec *dir)
{
	if (!description || !*description)
		return (1);
	if (get_float(description, &dir->x))
		return (1);
	if (!is_in_float_range(dir->x, -1.0, 1.0))
		return (1);
	if (get_float(description, &dir->y))
		return (1);
	if (!is_in_float_range(dir->y, -1.0, 1.0))
		return (1);
	if (get_float(description, &dir->z))
		return (1);
	if (!is_in_float_range(dir->z, -1.0, 1.0))
		return (1);
	return (0);
}

int	get_rgb(char **description, t_color *color)
{
	if (!description || !*description)
		return (1);
	if (get_int(description, &color->r))
		return (1);
	if (!is_in_int_range(color->r, 0, 255))
		return (1);
	if (get_int(description, &color->g))
		return (1);
	if (!is_in_int_range(color->g, 0, 255))
		return (1);
	if (get_int(description, &color->b))
		return (1);
	if (!is_in_int_range(color->b, 0, 255))
		return (1);
	return (0);
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

#pragma endregion

#pragma region Parsing

int	ambient_light_parsing(char *description, t_ambiant_light *ambiant_light)
{
	if (!description)
		return (1);
	if (get_intensity(&description, &ambiant_light->intensity))
		return (1);
	if (get_rgb(&description, &ambiant_light->color))
		return (1);
	if (!is_end_of_line(description))
		return (1);
	display_ambient_light(*ambiant_light);
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
	if (!is_end_of_line(description))
		return (1);
	display_spot_light(*spot_light);
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
	display_camera(*camera);
	return (0);
}

int	sphere_parsing(char *description, t_sphere *sphere)
{
	if (!description)
		return (1);
	if (get_pos(&description, &sphere->pos))
		return (1);
	if (get_float(&description, &sphere->diameter))
		return (1);
	if (get_rgb(&description, &sphere->color))
		return (1);
	if (!is_end_of_line(description))
		return (1);
	display_sphere(*sphere);
	return (0);
}

int	cylindre_parsing(char *description, t_cylinder *cylinder)
{
	if (!description)
		return (1);
	if (get_pos(&description, &cylinder->pos))
		return (1);
	if (get_dir(&description, &cylinder->dir))
		return (1);
	if (get_float(&description, &cylinder->diameter))
		return (1);
	if (get_float(&description, &cylinder->height))
		return (1);
	if (get_rgb(&description, &cylinder->color))
		return (1);
	if (!is_end_of_line(description))
		return (1);
	display_cylinder(*cylinder);
	return (0);
}

int	plan_parsing(char *description, t_plan *plan)
{
	if (!description)
		return (1);
	if (get_pos(&description, &plan->pos))
		return (1);
	if (get_dir(&description, &plan->dir))
		return (1);
	if (get_rgb(&description, &plan->color))
		return (1);
	if (!is_end_of_line(description))
		return (1);
	display_plan(*plan);
	return (0);
}

int	shapes_len(t_shapes *shapes)
{
	int			len;
	t_shapes	*temp;

	if (!shapes)
		return (0);
	len = 0;
	temp = shapes;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

t_shapes	*create_new_node(int id)
{
	t_shapes	*new_node;

	new_node = malloc(sizeof(t_shapes));
	if (!new_node)
		return (NULL);
	new_node->id = id;
	new_node->next = NULL;
	return (new_node);
}

int	append_to_list(t_shapes **shapes, t_shapes *new_node)
{
	t_shapes	*tail;

	if (!shapes)
		return (1);
	tail = *shapes;
	while (tail && tail->next)
		tail = tail->next;
	if (tail)
		tail->next = new_node;
	else
		*shapes = new_node;
	return (0);
}

int	shapes_parsing(char *description, t_shapes **shapes, t_element_type el)
{
	t_shapes	*new_node;

	if (!shapes)
		return (1);
	new_node = create_new_node(shapes_len(*shapes));
	if (!new_node)
		return (printf("shape creation for list of shapes failed\n"), 1);
	if (append_to_list(shapes, new_node))
		return (printf("new shape could not be added to the list\n"), 1);
	if (el == SP)
		return (new_node->type = SHPERE,
			sphere_parsing(description, &new_node->shape.sphere));
	if (el == CY)
		return (new_node->type = CYLINDER,
			cylindre_parsing(description, &new_node->shape.cylinder));
	if (el == PL)
		return (new_node->type = PLAN,
			plan_parsing(description, &new_node->shape.plan));
	return (1);
}

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

int	main(int argc, char **argv)
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
	/* while (1); */
	return (0);
}

#pragma endregion
