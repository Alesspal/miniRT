#include "ft_mlx.h"
#include "ft_raytracing.h"
#include <math.h>

// Fills the prime vector with its approriate components.
// p is the current pixel in which the ray is pointing towards.
void	fill_prime_vec(t_vec *prime_vec, t_mlx_win win, t_camera cam, t_point2D p)
{
	prime_vec->x = -(win.win_w / 2) + p.x;
	prime_vec->y = -(win.win_h / 2) + p.y;
	prime_vec->z = (win.win_w / 2) / tan(cam.fov / 2);

}

// Checks if there are intersections with spheres and the casted prime ray.
// Retunrs 1 if there is an intersection with a sphere.
// Fills the intersection struct with the closest sphere to the camera.
void	sp_intersection(t_vec ray, t_shapes *shape, t_intersection *intersection)
{
	
}

// Returns 1 if there is an intersection with an object and the casted prime ray.
// Returns 0 if not.

// ------------ actually it will take a void and fill intersection. if intersection.shape is void it means there is no intersection
void	intersection(t_vec ray, t_shapes *shape, t_intersection *intersection)
{
	// Go through the shapes list
	while (shape)
	{
		// sphere
		if (shape->type == SPHERE)
		{
			sp_intersection(ray, shape, intersection);
		}

		// plane

		// cylinder

		shape = shape->next;
	}
}

void	rayshooter(t_data *data, t_camera cam)
{
	t_point2D	pixel;
	t_vec	curr_prime_vec;

	pixel.y = -1;
	while (++pixel.y < data->win->win_h)
	{
		pixel.x = -1;
		while (++pixel.x < data->win->win_w)
		{
			fill_prime_vec(&curr_prime_vec, *data->win, cam, pixel);
			ft_img_pix_put(data, pixel.x, pixel.y, 0x77B5FE);
		}
	}
}
