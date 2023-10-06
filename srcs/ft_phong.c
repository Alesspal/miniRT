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
	i_diffuse = change_intesity(scene.spot_light.mod_color, fmax(0, dot_nl));
	// printf("color diffuse2 = %i, g = %i, b = %i\n", i_diffuse.r, i_diffuse.g, i_diffuse.b);
	return (i_diffuse);
}

/* t_color i_specular(t_scene scene, t_intersection *p)
{
    t_color specular_color;
    t_vec reflect_dir;
    float spec_intensity;

    // Calculate the reflection vector R
	t_vec n = ft_normalize(get_n(p));
	t_vec l = ft_normalize(vec_sub(p->pos, scene.spot_light.pos));
    reflect_dir = vec_sub(vec_mult(n,l), 2)
    
    // Specular reflection formula
    spec_intensity = pow(fmax(0.0, dot_product(view_dir, reflect_dir)), shininess);

    // Multiply by the light color and intensity
    specular_color.r = light_color.r * spec_intensity;
    specular_color.g = light_color.g * spec_intensity;
    specular_color.b = light_color.b * spec_intensity;

    return specular_color;
} */

t_color shadow(/* t_scene scene, t_intersection *p */)
{
	return ((t_color){0, 0, 0});
}

t_color phong(t_scene scene, t_intersection *p)
{
	t_color shape_color;
	t_color final_color;

	final_color = addition_color(scene.ambient_light.mod_color, i_diffuse(scene, p));	// ajout couleur ambiante + couleur diffuse
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
