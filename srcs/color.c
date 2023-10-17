/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:42:07 by alesspal          #+#    #+#             */
/*   Updated: 2023/10/17 15:27:11 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <stdio.h>

t_color	change_intesity(t_color color, float intensity)
{
	t_color	new_color;

	if (intensity > 1)
		intensity = 1;
	else if (intensity < 0)
		intensity = 0;
	new_color.r = color.r * intensity;
	new_color.g = color.g * intensity;
	new_color.b = color.b * intensity;
	return (new_color);
}

t_color	addition_color(t_color color1, t_color color2)
{
	t_color	new_color;

	new_color.r = color1.r + color2.r;
	if (new_color.r > 255)
		new_color.r = 255;
	new_color.g = color1.g + color2.g;
	if (new_color.g > 255)
		new_color.g = 255;
	new_color.b = color1.b + color2.b;
	if (new_color.b > 255)
		new_color.b = 255;
	return (new_color);
}

t_color	multiplication_color(t_color color1, t_color color2)
{
	t_color	new_color;

	new_color.r = color1.r * color2.r / 255;
	new_color.g = color1.g * color2.g / 255;
	new_color.b = color1.b * color2.b / 255;
	return (new_color);
}

int	color_to_int(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}
