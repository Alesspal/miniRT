/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:41:43 by alesspal          #+#    #+#             */
/*   Updated: 2023/10/17 14:43:13 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_utils.h"
#include "libft.h"

char	*skip_space(char *str)
{
	while (*str && ft_is_white_space(*str))
		str++;
	return (str);
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
	return (sign * (integer_part + fraction_part / div));
}
