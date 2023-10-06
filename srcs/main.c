#include "libft.h"
#include "ft_mlx.h"
#include "ft_vector.h"
#include "ft_shapes.h"
#include "ft_raytracing.h"
#include "ft_color.h"
#include <stdio.h>
#include "file_scene_parsing.h"
#include "display.h"

int	init_data(t_data *data)
{
	data->win = malloc(sizeof(t_mlx_win));
	data->img.mlx_img = NULL;
	data->img.addr = NULL;
	if (!data->win)
		return (1);
	data->win->mlx_ptr = mlx_init();
	if (!data->win->mlx_ptr)
		return (1);
	data->win->aspect_ratio = 16.0 / 9.0;
	data->win->win_h = 1000;
	data->win->win_w = data->win->win_h * data->win->aspect_ratio;
	data->win->mlx_win = mlx_new_window(data->win->mlx_ptr, data->win->win_w,
			data->win->win_h, "Minirt");
	if (!data->win->mlx_win)
		return (1);
	data->img.mlx_img = mlx_new_image(data->win->mlx_ptr, data->win->win_w,
			data->win->win_h);
	if (!data->img.mlx_img)
		return (1);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	if (!data->img.addr)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_scene	scene = {0};
	t_data	data;

	if (argc != 2)
	{
		printf("Error of inputs of arguments\n arguments valid : [name of program] [file of scene]\n");
		return (EXIT_FAILURE);
	}
	if (init_data(&data))
		ft_fatal_error("Error when initialising data", -1);

	if (file_parsing(argv[1], &scene))
	{
		printf("Error parsing\n");
		return (EXIT_FAILURE);
	}
	display_scene(scene);
	init_camera(&scene.camera, data.win->aspect_ratio);
	draw_scene(&data, scene);

	mlx_put_image_to_window(data.win->mlx_ptr, data.win->mlx_win, data.img.mlx_img, 0, 0);
	
	if (file_parsing(argv[1], &scene))
	{
		printf("Error : parsing failed\n");
		return (EXIT_FAILURE);
	}
	display_scene(scene);
	mlx_hook(data.win->mlx_win, 17, 0, &exit_program, &data);
	mlx_key_hook(data.win->mlx_win, &ft_key_event, &data);
	mlx_loop(data.win->mlx_ptr);
	return (EXIT_SUCCESS);
}
