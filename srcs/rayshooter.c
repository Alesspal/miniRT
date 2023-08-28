/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayshooter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:54:41 by eholzer           #+#    #+#             */
/*   Updated: 2023/08/28 19:20:38 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void	sp_intersection(t_ray ray, t_shapes *shape, t_intersection *intersection)
{
	
}

// Returns 1 if there is an intersection with an object and the casted prime ray.
// Returns 0 if not.

void	intersection(t_ray ray, t_shapes *shape, t_intersection *intersection)
{
	intersection->shape_type = NO_SHAPE;
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
	t_point2D		pixel;
	t_ray			prime_ray;
	t_intersection	intersection;

	pixel.y = -1;
	while (++pixel.y < data->win->win_h)
	{
		pixel.x = -1;
		while (++pixel.x < data->win->win_w)
		{
			fill_prime_ray(&prime_ray, *data->win, cam, pixel);

			// Check if the prime ray intersects any objects
			// intersection();

			// Compute lighting or shadows
			// if (intersection.shape_type != NO_SHAPE)
				// compute_light();

			// Set the pixel to the corresponding color
			ft_img_pix_put(data, pixel.x, pixel.y, 0x77B5FE);
		}
	}
}
