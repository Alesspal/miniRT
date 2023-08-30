#include "ft_mlx.h"
#include "ft_raytracing.h"
#include <math.h>

// Fills the prime vector with its approriate components.
// p is the current pixel in which the ray is pointing towards.
void	fill_prime_ray(t_ray *prime_ray, t_mlx_win win, t_camera cam, t_point2D p)
{
	prime_ray->dir.x = -(win.win_w / 2) + p.x;
	prime_ray->dir.y = -(win.win_h / 2) + p.y;
	prime_ray->dir.z = (win.win_w / 2) / tan(cam.fov / 2);

	prime_ray->dir = ft_normalize(prime_ray->dir);
	prime_ray->origin = cam.pos;
}

// Checks if there are intersections with spheres and the casted prime ray.
// Retunrs 1 if there is an intersection with a sphere.
// Fills the intersection struct with the closest sphere to the camera.
void	sp_intersection(t_ray ray, t_sphere sp, t_intersection *intersection)
{
	t_vec		co;
	t_eq		eq;

	co = ft_get_vec(sp.origin, ray.origin);
	eq.a = 1;
	eq.b = 2.0 * ft_dot(co, ray.dir);
	eq.c = ft_dot(co, co) - pow(sp.radius, 2);
	eq.discriminant = pow(eq.b, 2) - (4 * eq.a * eq.c);

	if (eq.discriminant < 0)
	{
		intersection->shape_type = NO_SHAPE;
		return ;
	}

	eq.s1 = (-eq.b - sqrt(eq.discriminant)) / 2;
	eq.s2 = (-eq.b + sqrt(eq.discriminant)) / 2;

	if (eq.s1 > 0 && eq.s1 < eq.s2)
	{
		intersection->shape_type = SPHERE;
		intersection->pos = v_to_p(vec_add(p_to_v(ray.origin), vec_mult(ray.dir, eq.s1)));
		return ;
	}
	if (eq.s2 > 0 && eq.s2 < eq.s1)
	{
		intersection->shape_type = SPHERE;
		intersection->pos = v_to_p(vec_add(p_to_v(ray.origin), vec_mult(ray.dir, eq.s2)));
		return ;
	}

	// oc = ray.origin - sphere.center
    // a = ray.direction.dot(ray.direction)
    // b = 2.0 * oc.dot(ray.direction)
    // c = oc.dot(oc) - sphere.radius * sphere.radius
    // discriminant = b*b - 4*a*c

    // if discriminant < 0:
    //     return None  # No intersection

    // t1 = (-b - math.sqrt(discriminant)) / (2 * a)
    // t2 = (-b + math.sqrt(discriminant)) / (2 * a)

    // if t1 > 0 or t2 > 0:
    //     return min(t1, t2) if t1 > 0 else t2
    // else:
    //     return None  # Both intersections are behind the ray's origin
}

// Returns 1 if there is an intersection with an object and the casted prime ray.
// Returns 0 if not.

void	fill_intersection(t_ray ray, t_shapes *shape, t_intersection *intersection)
{
	intersection->shape_type = NO_SHAPE;
	// Go through the shapes list
	while (shape)
	{
		// sphere
		if (shape->type == SPHERE)
		{
			sp_intersection(ray, shape->shape.sphere, intersection);
		}

		// plane

		// cylinder

		shape = shape->next;
	}
}

void	rayshooter(t_data *data, t_camera cam)
{
	t_point2D		pixel;
	t_ray			prime_ray;
	t_intersection	intersection;

	// for testing purpose
	t_shapes shapes;

	shapes.shape.sphere.color = 0x77B5FE;
	shapes.shape.sphere.radius = 7;
	shapes.shape.sphere.origin.x = 0;
	shapes.shape.sphere.origin.y = 0;
	shapes.shape.sphere.origin.z = 30;
	shapes.id = 0;
	shapes.next = 0;
	shapes.type = SPHERE;

	pixel.y = -1;
	while (++pixel.y < data->win->win_h)
	{
		pixel.x = -1;
		while (++pixel.x < data->win->win_w)
		{
			fill_prime_ray(&prime_ray, *data->win, cam, pixel);

			// Check if the prime ray intersects any objects
			intersection.pixel = pixel;
			fill_intersection(prime_ray, &shapes, &intersection);

			// Compute lighting or shadows
			// if (intersection.shape_type != NO_SHAPE)
				// compute_light();

			// Set the pixel to the corresponding color
			if (intersection.shape_type != NO_SHAPE)
				ft_img_pix_put(data, pixel.x, pixel.y, 0x77B5FE);
		}
	}
}
