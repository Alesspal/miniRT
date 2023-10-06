#include "ft_mlx.h"
#include "ft_raytracing.h"

void	draw_scene(t_data *data, t_scene scene)
{
	t_point2D		pixel;
	t_ray			prime_ray;
	t_intersection	intersection;
	t_color			color;

	prime_ray.pos = scene.camera.pos;
	pixel.y = -1;
	while (++pixel.y < data->win->win_h)
	{
		pixel.x = -1;
		while (++pixel.x < data->win->win_w)
		{
			// Fill the prime ray with its approriate components
			fill_prime_ray(&prime_ray, *data->win, scene.camera, pixel);

			// Check if the prime ray intersects any objects
			fill_intersection(prime_ray, scene.shapes, &intersection);
			
			// Compute the color of the pixel
			if (intersection.shape_type != NO_SHAPE)
			{
				// théoriquement c'est mieux de faire comme ça mais c'est chelou
				/* if (check_intersection(scene.spot_light.pos, intersection.pos, scene.shapes))
				{
					if (intersection.shape_type == SPHERE)
						color = change_intesity(intersection.shape.sphere.color, 0.3);
					else if (intersection.shape_type == CYLINDER)
						color = change_intesity(intersection.shape.cylinder.color, 0.3);
					else if (intersection.shape_type == PLANE)
						color = change_intesity(intersection.shape.plane.color, 0.3);
				}
				else
				{
					color = phong(scene, &intersection);
				} */

				// ça fait les ombres dans les ombres à cause de i_diffuse
				color = phong(scene, &intersection);
				if (check_intersection(scene.spot_light.pos, intersection.pos, scene.shapes))
				{
					color = change_intesity(color, 0.3);
				}

				// printf("color2 = %i, g = %i, b = %i\n", color.r, color.g, color.b);
				ft_img_pix_put(data, pixel.x, pixel.y, color_to_int(color));
			}
			else
			{
				// Set the pixel to the background color
				// printf("A = %i, g = %i, b = %i\n", scene.ambient_light.color.r, scene.ambient_light.color.g, scene.ambient_light.color.b);
				ft_img_pix_put(data, pixel.x, pixel.y, color_to_int(scene.ambient_light.mod_color));
			}
		}
	}
}
