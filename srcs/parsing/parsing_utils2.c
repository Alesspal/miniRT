#include "parsing_utils.h"
#include "libft.h"

bool	is_int(char *str)
{
	int		i;
	int		len;

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
