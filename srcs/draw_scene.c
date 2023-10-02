#include "ft_mlx.h"
#include "ft_raytracing.h"

void	draw_scene(t_data *data, t_scene scene)
{
	t_point2D		pixel;
	t_ray			prime_ray;
	t_intersection	intersection;
	int				color;

	prime_ray.origin = scene.camera.pos;
	pixel.y = -1;
	while (++pixel.y < data->win->win_h)
	{
		pixel.x = -1;
		while (++pixel.x < data->win->win_w)
		{
			// Fill the prime ray with its approriate components
			fill_prime_ray(&prime_ray, *data->win, scene.camera, pixel);

			// Check if the prime ray intersects any objects
			intersection.pixel = pixel; // maybe not necessary
			fill_intersection(prime_ray, scene.shapes, &intersection);
			
			// Compute the color of the pixel
			if (intersection.shape_type != NO_SHAPE)
			{
				// printf("intersection at (%d, %d)\n", pixel.x, pixel.y);
				color = 0x77B5FE; // temporary
				// compute_light(intersection, scene, &color);
				ft_img_pix_put(data, pixel.x, pixel.y, color);
			}
			else
			{
				// Set the pixel to the background color
				ft_img_pix_put(data, pixel.x, pixel.y, 0x000000);
			}
		}
	}
}
