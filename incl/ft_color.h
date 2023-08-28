/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:49:53 by alesspal          #+#    #+#             */
/*   Updated: 2023/08/28 11:50:17 by alesspal         ###   ########.fr       */
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
t_color	add_color(t_color color1, t_color color2);
t_color	mult_color(t_color color1, t_color color2);
int		color_to_int(t_color color);


#endif