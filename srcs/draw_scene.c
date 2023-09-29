#include "ft_mlx.h"
#include "ft_raytracing.h"

void	draw_scene(t_data *data, t_scene scene)
{
	t_point2D		pixel;
	t_ray			prime_ray;
	t_intersection	intersection;
	int				color;

	prime_ray.origin = scene.camera.pos;
	printf("prime_ray.origin = (%f, %f, %f)\n", prime_ray.origin.x, prime_ray.origin.y, prime_ray.origin.z);
	printf("sphere.origin = (%f, %f, %f)\n", scene.shapes->shape.sphere.origin.x, scene.shapes->shape.sphere.origin.y, scene.shapes->shape.sphere.origin.z);
	printf("sphere.radius = %f\n", scene.shapes->shape.sphere.radius);
	printf("camera.pos = (%f, %f, %f)\n", scene.camera.pos.x, scene.camera.pos.y, scene.camera.pos.z);
	printf("camera.dir = (%f, %f, %f)\n", scene.camera.dir.x, scene.camera.dir.y, scene.camera.dir.z);
	printf("camera.up = (%f, %f, %f)\n", scene.camera.up.x, scene.camera.up.y, scene.camera.up.z);
	printf("camera.right = (%f, %f, %f)\n", scene.camera.right.x, scene.camera.right.y, scene.camera.right.z);
	pixel.y = -1;
	while (++pixel.y < data->win->win_h)
	{
		pixel.x = -1;
		while (++pixel.x < data->win->win_w)
		{
			// Fill the prime ray with its approriate components
			fill_prime_ray(&prime_ray, *data->win, scene.camera, pixel);
			printf("prime_ray.dir = (%f, %f, %f)\n", prime_ray.dir.x, prime_ray.dir.y, prime_ray.dir.z);
			// Check if the prime ray intersects any objects
			intersection.pixel = pixel; // maybe not necessary
			fill_intersection(prime_ray, scene.shapes, &intersection);
			// printf("casting ray at (%d, %d)\n", pixel.x, pixel.y);
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
