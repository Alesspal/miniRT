#include "ft_shapes.h"
#include <math.h>

t_sphere create_sphere(t_vec pos, float diameter, t_color color)
{
	t_sphere	sphere;

	sphere.pos = pos;
	sphere.radius = diameter / 2;
	sphere.color = color;
	return (sphere);
}

t_cylinder	create_cylinder(t_vec pos, t_vec dir, float diameter, float height, t_color color)
{
	t_cylinder cylinder;

	cylinder.pos = pos;
	cylinder.dir = dir;
	cylinder.radius = diameter / 2;
	cylinder.height = height;
	cylinder.color = color;
	return (cylinder);
}

t_plane	create_plane(t_vec pos, t_vec n, t_color color)
{
	t_plane	plane;

	plane.pos = pos;
	plane.n = n;
	plane.color = color;
	return (plane);
}

void	draw_filled_sphere(t_data *data, t_sphere sphere)	// remplacer par structure sphere
{
	int				i;
	int				y1;
	double			x2;

	for(i = -sphere.radius; i <= sphere.radius; i++)  // Parcourir la hauteur du cercle.
	{
		y1 = sphere.pos.y + i;
		// Pour un y donné, trouver la distance horizontale x2 du centre du cercle au bord du cercle.
		x2 = sqrt(sphere.radius * sphere.radius - i*i);  // Selon l'équation du cercle
		for (int j = sphere.pos.x - x2; j <= sphere.pos.x + x2; j++)  // dessiner une ligne horizontale
		{
			ft_img_pix_put(data, j, y1, color_to_int(sphere.color));
		}
	}
}
