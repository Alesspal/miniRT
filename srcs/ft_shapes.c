#include "ft_shapes.h"
#include <math.h>

t_sphere create_sphere(t_point3D origin, int radius, t_color color)
{
	t_sphere sphere;

	sphere.pos = origin;
	sphere.diameter = radius;
	sphere.color = color;
	return (sphere);
}

t_cylinder create_cylinder(t_point3D origin, t_vec orientation, int radius,
int height, t_color color)
{
	t_cylinder cylinder;

	cylinder.pos = origin;
	cylinder.dir = orientation;
	cylinder.diameter = radius;
	cylinder.height = height;
	cylinder.color = color;
	return (cylinder);
}

t_plan create_plan(t_point3D origin, t_vec orientation, t_color color)
{
	t_plan plan;

	plan.pos = origin;
	plan.dir = orientation;
	plan.color = color;
	return (plan);
}

void	draw_filled_sphere(t_data *data, t_sphere sphere)	// remplacer par structure sphere
{
	int				i;
	int				y1;
	double			x2;

	for(i = -sphere.diameter; i <= sphere.diameter; i++)  // Parcourir la hauteur du cercle.
	{
		y1 = sphere.pos.y + i;
		// Pour un y donné, trouver la distance horizontale x2 du centre du cercle au bord du cercle.
		x2 = sqrt(sphere.diameter * sphere.diameter - i*i);  // Selon l'équation du cercle
		for (int j = sphere.pos.x - x2; j <= sphere.pos.x + x2; j++)  // dessiner une ligne horizontale
		{
			ft_img_pix_put(data, j, y1, color_to_int(sphere.color));
		}
	}
}
