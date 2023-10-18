/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:47:21 by alesspal          #+#    #+#             */
/*   Updated: 2023/10/18 10:07:04 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "my_mlx.h"
#include "file_scene_parsing.h"
#include "raytracing.h"

void	display_sphere(t_sphere sphere)
{
	printf("-----SPHERE-----\n");
	printf("pos : %f, %f, %f\n", sphere.pos.x, sphere.pos.y, sphere.pos.z);
	printf("radius : %f\n", sphere.radius);
	printf("rgb : %d, %d, %d\n", sphere.color.r, sphere.color.g, sphere.color.b);
	printf("----------------\n");
}

void	display_cylinder(t_cylinder cylinder)
{
	printf("-----CYLINDER-----\n");
	printf("pos : %f, %f, %f\n", cylinder.pos.x, cylinder.pos.y, cylinder.pos.z);
	printf("dir : %f, %f, %f\n", cylinder.dir.x, cylinder.dir.y, cylinder.dir.z);
	printf("radius : %f\n", cylinder.radius);
	printf("height : %f\n", cylinder.height);
	printf("rgb : %d, %d, %d\n", cylinder.color.r, cylinder.color.g, cylinder.color.b);
	printf("------------------\n");
}

void	display_plan(t_plane plan)
{
	printf("-----PLAN-----\n");
	printf("pos : %f, %f, %f\n", plan.pos.x, plan.pos.y, plan.pos.z);
	printf("dir : %f, %f, %f\n", plan.normal.x, plan.normal.y, plan.normal.z);
	printf("rgb : %d, %d, %d\n", plan.color.r, plan.color.g, plan.color.b);
	printf("--------------\n");
}

void	display_shapes(t_shapes *shapes)
{
	while (shapes)
	{
		printf("ID = %d\n", shapes->id);
		if (shapes->type == SPHERE)
			display_sphere(shapes->shape.sphere);
		else if (shapes->type == CYLINDER)
			display_cylinder(shapes->shape.cylinder);
		else if (shapes->type == PLANE)
			display_plan(shapes->shape.plane);
		shapes = shapes->next;
	}
}

int	main(int argc, char **argv)
{
	t_scene	scene;
	t_data	data;

	if (argc != 2)
		ft_fatal_error("Input Error, try: ./miniRT example_scene.rt",
			EXIT_FAILURE);
	init_scene(&scene);
	if (file_parsing(argv[1], &scene))
		ft_fatal_error("Error during parsing", EXIT_FAILURE);
	if (init_data(&data))
		ft_fatal_error("Error initialising data", EXIT_FAILURE);
	init_camera(&scene.camera, data.win->aspect_ratio);
	remove_overlapping_objects(scene.shapes);
	draw_scene(&data, scene);
	free_shapes(scene.shapes);
	mlx_put_image_to_window(data.win->mlx_ptr, data.win->mlx_win,
		data.img.mlx_img, 0, 0);
	mlx_hook(data.win->mlx_win, 17, 0, &exit_program, &data);
	mlx_key_hook(data.win->mlx_win, &key_event, &data);
	mlx_loop(data.win->mlx_ptr);
	return (EXIT_SUCCESS);
}
