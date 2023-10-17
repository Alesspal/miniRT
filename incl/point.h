/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:48:10 by alesspal          #+#    #+#             */
/*   Updated: 2023/10/17 15:25:19 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

typedef struct s_point2D
{
	int	x;
	int	y;
}	t_point2D;

typedef struct s_point3D
{
	float	x;
	float	y;
	float	z;
}	t_point3D;

#endif