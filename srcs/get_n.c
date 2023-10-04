#include "ft_shapes.h"
#include "ft_raytracing.h"

// sphere N = P - C
t_vec	get_n_sphere(t_intersection *p)
{
	t_vec		n;
	t_sphere	sphere;

	sphere = (t_sphere)p->shape.sphere;
	n = ft_create_vec(p->pos.x - sphere.origin.x,
		p->pos.y - sphere.origin.y,
		p->pos.z - sphere.origin.z);
	return (n);
}

// cylinder N = P - C - dot(cam, P - C) * cam
t_vec	get_n_cylinder(t_intersection *p)
{
	t_vec		n;
	t_cylinder	cylinder;
	t_vec		pc;
	t_vec		v;
	float		dot_v_pc;

	cylinder = (t_cylinder)p->shape.cylinder;
	pc = ft_create_vec(p->pos.x - cylinder.origin.x,
		p->pos.y - cylinder.origin.y,
		p->pos.z - cylinder.origin.z);
	v = cylinder.dir;
	dot_v_pc = ft_dot(v, pc);
	v.x *= dot_v_pc;
	v.y *= dot_v_pc;
	v.z *= dot_v_pc;
	n.x = pc.x - v.x;
	n.y = pc.y - v.y;
	n.z = pc.z - v.z;
	return (n);
}

// plane N = dir of plane
t_vec	get_n_plan(t_intersection *p)
{
	t_vec		n;
	t_plane		plane;

	plane = (t_plane)p->shape.plane;
	n = ft_create_vec(plane.normal.x,
		plane.normal.y,
		plane.normal.z);
	return (n);
}

t_vec	get_n(t_intersection *p)
{
	if (p->shape_type == SPHERE)
		return (get_n_sphere(p));
	else if (p->shape_type == CYLINDER)
		return (get_n_cylinder(p));
	else
		return (get_n_plan(p));
}

/* int main(void)
{
	t_vec			n;
	t_cylinder		cylinder;
	t_sphere		sphere;
	t_plan			plane;
	t_intersection	p1;
	t_intersection	p2;
	t_intersection	p3;

	p1.pos = ft_create_vec(3, 4 , 0);
	cylinder.origin = ft_create_vec(3, 5, -2);
	cylinder.dir = ft_create_vec(1, 4, -3);
	p1.shape.cylinder = cylinder;
	p1.shape_type = CYLINDER;
	n = get_n(&p1);
	printf("cylinder : n.x = %f, n.y = %f, n.z = %f\n", n.x, n.y, n.z);
	n = ft_normalize(n);
	printf("normalized : n.x = %f, n.y = %f, n.z = %f\n", n.x, n.y, n.z);

	p2.pos = ft_create_vec(-5, -5 , -5);
	sphere.origin = ft_create_vec(-10, -10, -10);
	p2.shape.sphere = sphere;
	p2.shape_type = SHPERE;
	n = get_n(&p2);
	printf("sphere : n.x = %f, n.y = %f, n.z = %f\n", n.x, n.y, n.z);
	n = ft_normalize(n);
	printf("normalized : n.x = %f, n.y = %f, n.z = %f\n", n.x, n.y, n.z);

	p3.pos = ft_create_vec(3, 4 , -5);
	plane.dir = ft_create_vec(9, -3, 275);
	p3.shape.plane = plane;
	p3.shape_type = PLAN;
	n = get_n(&p3);
	printf("plane : n.x = %f, n.y = %f, n.z = %f\n", n.x, n.y, n.z);
	n = ft_normalize(n);
	printf("normalized : n.x = %f, n.y = %f, n.z = %f\n", n.x, n.y, n.z);
	
	return (0);
} */
