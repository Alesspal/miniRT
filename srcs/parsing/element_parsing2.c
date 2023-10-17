#include "element_parsing.h"
#include "parsing_utils.h"
#include "value_parsing.h"

int	sphere_parsing(char *description, t_sphere *sphere)
{
	if (!description)
		return (1);
	if (get_pos(&description, &sphere->pos))
		return (1);
	if (get_float(&description, &sphere->radius))
		return (1);
	if (get_rgb(&description, &sphere->color))
		return (1);
	if (!is_end_of_line(description))
		return (1);
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
	if (get_float(&description, &cylinder->radius))
		return (1);
	if (get_float(&description, &cylinder->height))
		return (1);
	if (get_rgb(&description, &cylinder->color))
		return (1);
	if (!is_end_of_line(description))
		return (1);
	return (0);
}

int	plane_parsing(char *description, t_plane *plane)
{
	if (!description)
		return (1);
	if (get_pos(&description, &plane->pos))
		return (1);
	if (get_dir(&description, &plane->n))
		return (1);
	if (get_rgb(&description, &plane->color))
		return (1);
	if (!is_end_of_line(description))
		return (1);
	return (0);
}
