/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:47:21 by alesspal          #+#    #+#             */
/*   Updated: 2023/10/19 11:31:38 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "my_mlx.h"
#include "file_scene_parsing.h"
#include "raytracing.h"

int	main(int argc, char **argv)
{
	t_scene	scene;
	t_data	data;

	(void)data;
	if (argc != 2)
		return (printf("Input Error, try: ./miniRT example_scene.rt"));
	init_scene(&scene);
	if (file_parsing(argv[1], &scene))
		return (printf("Error during parsing\n"));
	if (init_data(&data))
		return (printf("Error initialising data\n"));
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
