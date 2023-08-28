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
	printf("get_n x = %f, y = %f, z = %f\n", n.x, n.y, n.z);
	l = ft_normalize(ft_get_vec(p->coordinate, scene.spot_light.coordinate));
	printf("get_l x = %f, y = %f, z = %f\n", l.x, l.y, l.z);
	dot_nl = ft_dot(n, l);
	printf("dot_nl = %f\n", fmax(0, dot_nl));
	i_diffuse = change_intesity(scene.spot_light.color, fmax(0, dot_nl));
	printf("color diffuse = %i, g = %i, b = %i\n", i_diffuse.r, i_diffuse.g, i_diffuse.b);
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

	final_color = add_color(scene.ambient_light.color, i_diffuse(scene, p));	// ajout couleur ambiante + couleur diffuse
	printf("color ambiante = %i, g = %i, b = %i\n", scene.ambient_light.color.r, scene.ambient_light.color.g, scene.ambient_light.color.b);
	printf("color diffuse + ambiante = %i, g = %i, b = %i\n", final_color.r, final_color.g, final_color.b);
	if (p->shape_type == SHPERE)
		shape_color = p->shape.sphere.color;
	else if (p->shape_type == CYLINDER)
		shape_color = p->shape.cylinder.color;
	else
		shape_color = p->shape.plan.color;
	final_color = mult_color(final_color, shape_color);							// multiplier avec la couleur de la forme
	printf("couleur final r = %i, g = %i, b = %i\n", final_color.r, final_color.g, final_color.b);
	return (final_color);
}

/* int main(void)
{
	t_scene scene;
	t_intersection p;

	p.shape_type = SHPERE;
	p.shape.sphere.origin = (t_point3D){0, 0, 0};
	p.shape.sphere.color = (t_color){128, 128, 128};
	p.coordinate = (t_point3D){1, 1, 1};
	scene.spot_light.coordinate = (t_point3D){2, 2 ,2};
	scene.spot_light.color = (t_color){255, 255, 255};
	scene.ambient_light.color = (t_color){5, 5, 5};

	t_color pixel = phong(scene, &p);
	printf("pixel r = %i, g = %i, b = %i\n", pixel.r, pixel.g, pixel.b);
} */

// à proteger
/* void draw_scene(t_data data, t_scene scene, t_intersection *p)
{
	int		x;
	int		y;
	t_color	color;
	
	x = 0;
	y = 0;
	// parcourir tout les pixels
	while (y < data.win->win_h)
	{
		while (x < data.win->win_w)
		{
			if (x == p->pixel_coordinate.x && y == p->pixel_coordinate.y)
			{
				if (intersection(p->coordinate, scene.spot_light.coordinate))
				{
					color = shadow();
				}
				else
				{
					color = phong(scene, p);
				}
				p = p->next;
			}
			ft_img_pix_put(&data, p->pixel_coordinate.x, p->pixel_coordinate.y, color_to_int(color));
			x++;
		}
		y++;
	}
} */

// fonction qui calcul la couleur d'un pixel
// prend en param la position de la lumière
// et les intersections de la caméra jusqu'a un pixel d'une forme visible (P)
// {
// 	while (les points P)
// 	{
// 		calcule comment la lumière interagis avec la couleur de la sphere
// 	}
// 	met le reste dans la couleur ambiante définit
// }

// fonction qui calcule la couleur
// prend en param un point P, la position de la lumière et la structure de la forme
// {
// 	if (P intersecte qqch de sa position jusqu'à la source lumineuse)
// 		peindre le pixel en noir ou couleur ambiante
// 	sinon
//	{
//		créer le vecteur N
//		vect N = vect P - vect O (cendre de la forme) (fonction find_N) 
//		le normaliser
//		créer le vecteur L
//		vect L = vect S (source lumineuse) - vect P
//		le normaliser
//		créer le vecteur V (optionnel)
//		vect V =  vect cam - vect P (optionnel)
//		le normaliser (optionnel)
//		calculer le produit scalaire de N * L
//		couleur = I source * RGB de la forme * produit scalaire de N * L
//		peindre le pixel en la couleur trouvé
//	}
// }
