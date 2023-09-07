#ifndef VALUE_PARSING_H
# define VALUE_PARSING_H

# include "ft_raytracing.h"

char	*get_element(char *description, t_element_type *el);
int		get_float(char **description, float *ret);
int		get_int(char **description, int *ret);
int		get_intensity(char **description, float *intensity);
int		get_fov(char **description, int *fov);
int		get_pos(char **description, t_point3D *pos);
int		get_dir(char **description, t_vec *dir);
int		get_rgb(char **description, t_color *color);

#endif