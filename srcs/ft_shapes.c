/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shapes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:28:28 by alesspal          #+#    #+#             */
/*   Updated: 2023/08/25 15:21:55 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_shapes.h"
#include <math.h>

t_sphere create_sphere(t_vec origin, int radius, int color)
{
	t_sphere sphere;

	sphere.origin = origin;
	sphere.radius = radius;
	sphere.color = color;

	return (sphere);
}

t_cylinder create_cylinder(t_vec origin, t_vec dir, int radius,
int height, int color)
{
	t_cylinder cylinder;

	cylinder.origin = origin;
	cylinder.dir = dir;
	cylinder.radius = radius;
	cylinder.height = height;
	cylinder.color = color;

	return (cylinder);
}

t_plan create_plan(t_vec origin, t_vec dir, int color)
{
	t_plan plan;

	plan.origin = origin;
	plan.dir = dir;
	plan.color = color;

	return (plan);
}

void	draw_filled_sphere(t_data *data, t_sphere sphere)	// remplacer par structure sphere
{
	int				i;
	int				y1;
	double			x2;

	for(i = -sphere.radius; i <= sphere.radius; i++)  // Parcourir la hauteur du cercle.
	{
		y1 = sphere.origin.y + i;
		// Pour un y donné, trouver la distance horizontale x2 du centre du cercle au bord du cercle.
		x2 = sqrt(sphere.radius * sphere.radius - i*i);  // Selon l'équation du cercle
		for (int j = sphere.origin.x - x2; j <= sphere.origin.x + x2; j++)  // dessiner une ligne horizontale
		{
			ft_img_pix_put(data, j, y1, sphere.color);
		}
	}
}
