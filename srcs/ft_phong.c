#include "ft_raytracing.h"
#include "ft_vector.h"
#include "ft_color.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ft_raytracing.h"

t_color i_diffuse(t_scene scene, t_intersection *p)
{
	t_color i_diffuse;
	t_vec	n;
	t_vec	l;
	float	dot_nl;

	n = ft_normalize(get_n(p));
	// printf("get_n x = %f, y = %f, z = %f\n", n.x, n.y, n.z);
	l = ft_normalize(vec_sub(p->pos, scene.spot_light.pos));
	// printf("get_l x = %f, y = %f, z = %f\n", l.x, l.y, l.z);
	dot_nl = ft_dot(n, l);
	// printf("dot_nl = %f\n", fmax(0, dot_nl));
	// printf("color diffuse1 = %i, g = %i, b = %i\n", i_diffuse.r, i_diffuse.g, i_diffuse.b);
	i_diffuse = change_intesity(scene.spot_light.color, fmax(0, dot_nl));
	// printf("color diffuse2 = %i, g = %i, b = %i\n", i_diffuse.r, i_diffuse.g, i_diffuse.b);
	return (i_diffuse);
}

/* int specular(t_scene scene, t_intersection *p)
{
	return (1);
} */

t_color shadow(/* t_scene scene, t_intersection *p */)
{
	return ((t_color){0, 0, 0});
}

t_color phong(t_scene scene, t_intersection *p)
{
	t_color shape_color;
	t_color final_color;

	final_color = addition_color(scene.ambient_light.color, i_diffuse(scene, p));	// ajout couleur ambiante + couleur diffuse
	// printf("color ambiante = %i, g = %i, b = %i\n", scene.ambient_light.color.r, scene.ambient_light.color.g, scene.ambient_light.color.b);
	// printf("color diffuse + ambiante = %i, g = %i, b = %i\n", final_color.r, final_color.g, final_color.b);
	if (p->shape_type == SPHERE)
		shape_color = p->shape.sphere.color;
	else if (p->shape_type == CYLINDER)
		shape_color = p->shape.cylinder.color;
	else
		shape_color = p->shape.plane.color;
	final_color = multiplication_color(final_color, shape_color);							// multiplier avec la couleur de la forme
	// printf("couleur final r = %i, g = %i, b = %i\n", final_color.r, final_color.g, final_color.b);
	return (final_color);
}

// void draw_scene(t_data data, t_scene scene, t_intersection *p)
// {
// 	int		x;
// 	int		y;
// 	t_color	color;
	
// 	x = 0;
// 	y = 0;
// 	// parcourir tout les pixels
// 	while (y < data.win->win_h)
// 	{
// 		while (x < data.win->win_w)
// 		{
// 			color = (t_color){0, 0, 0};
// 			if (p && x == p->pixel.x && y == p->pixel.y)
// 			{
// 				/* if (intersection(p->pos, scene.spot_light.pos))
// 				{
// 					color = shadow();
// 				}
// 				else
// 				{
// 					color = phong(scene, p);
// 				} */
// 				p = p->next;
// 			}
// 			else
// 				color = scene.ambient_light.color;
// 			ft_img_pix_put(&data, x, y, color_to_int(color));
// 			x++;
// 		}
// 		y++;
// 	}
// }

/* int main(void)
{
	t_scene scene;
	t_intersection p;

	p.shape_type = SHPERE;
	p.shape.sphere.origin = (t_vec){0, 0, 0};
	p.shape.sphere.color = (t_color){128, 128, 128};
	p.coordinate = (t_vec){1, 1, 1};
	scene.spot_light.coordinate = (t_vec){2, 2 ,2};
	scene.spot_light.color = (t_color){255, 255, 255};
	scene.ambient_light.color = (t_color){5, 5, 5};

	t_color pixel = phong(scene, &p);
	printf("pixel r = %i, g = %i, b = %i\n", pixel.r, pixel.g, pixel.b);
} */
