/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shapes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:36:33 by alesspal          #+#    #+#             */
/*   Updated: 2023/08/25 13:14:08 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHAPES_H
# define FT_SHAPES_H

# include "ft_mlx.h"
# include "ft_vector.h"

typedef struct s_sphere
{
	t_vec	origin;
	int		radius;
	int		color;
}	t_sphere;

typedef struct s_cylinder
{
	t_vec	origin;
	t_vec	orientation;
	int		radius;
	int		height;
	int		color;
}	t_cylinder;

typedef struct s_plan
{
	t_vec	origin;
	t_vec	orientation;
	int		color;
}	t_plan;

enum e_shapes
{
	SHPERE,
	CYLINDER,
	PLAN
};

typedef struct s_shapes
{
	int				id;
	enum e_shapes	type;
	void			*shape;
	struct s_shapes	*next;
}	t_shapes;

t_sphere	create_sphere(t_vec origin, int radius, int color); // changer le premier parametre en un s_point (coordonnées) ?
t_cylinder	create_cylinder(t_vec origin, t_vec orientation, int radius,
						int height, int color);
t_plan		create_plan(t_vec origin, t_vec orientation, int color);

void		draw_filled_sphere(t_data *data, t_sphere sphere);

#endif