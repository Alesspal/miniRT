#include "ft_raytracing.h"
#include "ft_vector.h"
#include "ft_color.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ft_raytracing.h"

t_color	i_diffuse(t_scene scene, t_intersection *p)
{
	t_color	i_diffuse;
	t_vec	n;
	t_vec	l;
	float	dot_nl;

	n = ft_normalize(get_n(p));
	l = ft_normalize(ft_get_vec(p->pos, scene.spot_light.pos));
	dot_nl = ft_dot(n, l);
	i_diffuse = change_intesity(scene.spot_light.mod_color, fmax(0, dot_nl));
	return (i_diffuse);
}

t_color	phong(t_scene scene, t_intersection *p)
{
	t_color	shape_color;
	t_color	final_color;

	final_color = addition_color(scene.ambient_light.mod_color,
			i_diffuse(scene, p));
	if (p->shape_type == SPHERE)
		shape_color = p->shape.sphere.color;
	else if (p->shape_type == CYLINDER)
		shape_color = p->shape.cylinder.color;
	else
		shape_color = p->shape.plane.color;
	final_color = multiplication_color(final_color, shape_color);
	return (final_color);
}
