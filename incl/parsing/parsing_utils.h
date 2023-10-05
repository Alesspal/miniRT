#ifndef PARSING_UTILS_H
# define PARSING_UTILS_H

# include "stdbool.h"

char	*skip_space(char *str);
char	*go_next_value(char *descr);
int		find_comma_or_white_space(char *str);
float	ft_atof(char *nb);
bool	is_int(char *str);
bool	is_flaot(char *str);
bool	is_in_int_range(int val, int range_min, int range_max);
bool	is_in_float_range(float val, float range_min, float range_max);
bool	is_end_of_line(char *line);

#endif