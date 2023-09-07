#include "value_parsing.h"
#include "parsing_utils.h"
#include "libft.h"

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
