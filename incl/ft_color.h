/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:48:07 by alesspal          #+#    #+#             */
/*   Updated: 2023/10/17 14:49:00 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLOR_H
# define FT_COLOR_H

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

t_color	change_intesity(t_color color, float intesity);
t_color	addition_color(t_color color1, t_color color2);
t_color	multiplication_color(t_color color1, t_color color2);
int		color_to_int(t_color color);

#endif