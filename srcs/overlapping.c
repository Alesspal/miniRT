#include "ft_shapes.h"
#include "ft_raytracing.h"

void	remove_overlapping_sp(t_shapes *shapes)
{
	t_shapes	*curr;

	curr = shapes;
	shapes = shapes->next;
	while (shapes)
	{
		if (curr->type == shapes->type)
		{
			if (curr->shape.sphere.pos.x == shapes->shape.sphere.pos.x
				&& curr->shape.sphere.pos.y == shapes->shape.sphere.pos.y
				&& curr->shape.sphere.pos.z == shapes->shape.sphere.pos.z
				&& curr->shape.sphere.radius == shapes->shape.sphere.radius)
			{
				shapes->display = false;
			}
		}
		shapes = shapes->next;
	}
}

void	remove_overlapping_pl(t_shapes *shapes)
{
	t_shapes	*curr;

	curr = shapes;
	shapes = shapes->next;
	while (shapes)
	{
		if (curr->type == shapes->type)
		{
			if (curr->shape.plane.pos.x == shapes->shape.plane.pos.x
				&& curr->shape.plane.pos.y == shapes->shape.plane.pos.y
				&& curr->shape.plane.pos.z == shapes->shape.plane.pos.z
				&& curr->shape.plane.n.x == shapes->shape.plane.n.x
				&& curr->shape.plane.n.y == shapes->shape.plane.n.y
				&& curr->shape.plane.n.z == shapes->shape.plane.n.z)
			{
				shapes->display = false;
			}
		}
		shapes = shapes->next;
	}
}

void	remove_overlapping_cy(t_shapes *shapes)
{
	t_shapes	*curr;

	curr = shapes;
	shapes = shapes->next;
	while (shapes)
	{
		if (curr->type == shapes->type)
		{
			if (curr->shape.cylinder.pos.x == shapes->shape.cylinder.pos.x
				&& curr->shape.cylinder.pos.y == shapes->shape.cylinder.pos.y
				&& curr->shape.cylinder.pos.z == shapes->shape.cylinder.pos.z
				&& curr->shape.cylinder.dir.x == shapes->shape.cylinder.dir.x
				&& curr->shape.cylinder.dir.y == shapes->shape.cylinder.dir.y
				&& curr->shape.cylinder.dir.z == shapes->shape.cylinder.dir.z
				&& curr->shape.cylinder.radius == shapes->shape.cylinder.radius
				&& curr->shape.cylinder.height == shapes->shape.cylinder.height)
			{
				shapes->display = false;
			}
		}
		shapes = shapes->next;
	}
}

void	remove_overlapping_objects(t_shapes *shapes)
{
	while (shapes)
	{
		if (shapes->type == SPHERE)
			remove_overlapping_sp(shapes);
		if (shapes->type == PLANE)
			remove_overlapping_pl(shapes);
		if (shapes->type == CYLINDER)
			remove_overlapping_cy(shapes);
		shapes = shapes->next;
	}
}
