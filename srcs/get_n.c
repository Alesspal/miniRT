#include "ft_shapes.h"
#include "ft_raytracing.h"

// sphere N = P - C
t_vec	get_n_sphere(t_intersection *p)
{
	t_vec		n;
	t_sphere	sphere;

	sphere = (t_sphere)p->shape.sphere;
	n = ft_get_vec(sphere.origin, p->coordinate);
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
	pc = ft_get_vec(cylinder.origin, p->coordinate);
	v = cylinder.orientation;
	dot_v_pc = ft_dot(v, pc);
	v.x *= dot_v_pc;
	v.y *= dot_v_pc;
	v.z *= dot_v_pc;
	n.x = pc.x - v.x;
	n.y = pc.y - v.y;
	n.z = pc.z - v.z;
	return (n);
}

// plan N = orientation of plan
t_vec	get_n_plan(t_intersection *p)
{
	t_vec		n;
	t_plan		plan;

	plan = (t_plan)p->shape.plan;
	n = ft_create_vec(plan.orientation.x,
		plan.orientation.y,
		plan.orientation.z);
	return (n);
}

t_vec get_n(t_intersection *p)
{
	if (p->shape_type == SHPERE)
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
	t_plan			plan;
	t_intersection	p1;
	t_intersection	p2;
	t_intersection	p3;

	p1.coordinate = ft_create_vec(3, 4 , 0);
	cylinder.origin = ft_create_vec(3, 5, -2);
	cylinder.orientation = ft_create_vec(1, 4, -3);
	p1.shape.cylinder = cylinder;
	p1.shape_type = CYLINDER;
	n = get_n(&p1);
	printf("cylinder : n.x = %f, n.y = %f, n.z = %f\n", n.x, n.y, n.z);
	n = ft_normalize(n);
	printf("normalized : n.x = %f, n.y = %f, n.z = %f\n", n.x, n.y, n.z);

	p2.coordinate = ft_create_vec(-5, -5 , -5);
	sphere.origin = ft_create_vec(-10, -10, -10);
	p2.shape.sphere = sphere;
	p2.shape_type = SHPERE;
	n = get_n(&p2);
	printf("sphere : n.x = %f, n.y = %f, n.z = %f\n", n.x, n.y, n.z);
	n = ft_normalize(n);
	printf("normalized : n.x = %f, n.y = %f, n.z = %f\n", n.x, n.y, n.z);

	p3.coordinate = ft_create_vec(3, 4 , -5);
	plan.orientation = ft_create_vec(9, -3, 275);
	p3.shape.plan = plan;
	p3.shape_type = PLAN;
	n = get_n(&p3);
	printf("plan : n.x = %f, n.y = %f, n.z = %f\n", n.x, n.y, n.z);
	n = ft_normalize(n);
	printf("normalized : n.x = %f, n.y = %f, n.z = %f\n", n.x, n.y, n.z);
	
	return (0);
} */
