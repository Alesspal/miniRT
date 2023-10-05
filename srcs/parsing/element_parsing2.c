#include "element_parsing.h"
#include "parsing_utils.h"
#include "value_parsing.h"
#include "display.h"

int	sphere_parsing(char *description, t_sphere *sphere)
{
	// printf("here4\n");
	if (!description)
		return (1);
	if (get_pos(&description, &sphere->pos))
		return (1);
	if (get_float(&description, &sphere->radius))
		return (1);
	if (get_rgb(&description, &sphere->color))
		return (1);
	printf("desc1 = '%s'\n", description);
	if (get_float(&description, &sphere->shininess))
		return (1);
	printf("desc2 = '%s'\n", description);
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
	if (get_float(&description, &cylinder->radius))
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

int	plan_parsing(char *description, t_plane *plan)
{
	if (!description)
		return (1);
	if (get_pos(&description, &plan->pos))
		return (1);
	if (get_dir(&description, &plan->normal))
		return (1);
	if (get_rgb(&description, &plan->color))
		return (1);
	if (!is_end_of_line(description))
		return (1);
	display_plan(*plan);
	return (0);
}
