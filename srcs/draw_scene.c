/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:54:11 by alesspal          #+#    #+#             */
/*   Updated: 2023/10/17 16:02:57 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_mlx.h"
#include "raytracing.h"

t_color	get_pixel_color(t_intersection inter, t_scene scene)
{
	t_color	color;

	if (inter.shape_type != NO_SHAPE)
	{
		color = phong(scene, &inter);
		if (check_intersection(scene.spot_light.pos, inter.pos,
				scene.shapes, inter.id))
			color = change_intesity(color, 0.3);
	}
	else
		color = (t_color){0, 0, 0};
	return (color);
}

void	draw_scene(t_data *data, t_scene scene)
{
	t_point2D		pixel;
	t_ray			prime_ray;
	t_intersection	inter;
	t_color			color;

	prime_ray.pos = scene.camera.pos;
	pixel.y = -1;
	while (++pixel.y < data->win->win_h)
	{
		pixel.x = -1;
		while (++pixel.x < data->win->win_w)
		{
			set_prime_ray(&prime_ray, *data->win, scene.camera, pixel);
			set_intersection(prime_ray, scene.shapes, &inter);
			color = get_pixel_color(inter, scene);
			img_pix_put(data, pixel.x, pixel.y, color_to_int(color));
		}
	}
}
