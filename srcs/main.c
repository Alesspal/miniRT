#include "libft.h"
#include "ft_mlx.h"
#include "ft_vector.h"
#include "ft_shapes.h"
#include "ft_raytracing.h"
#include "ft_color.h"
#include <stdio.h>

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
	data->win->win_h = 768;
	// data->win->win_h = 1080;
	data->win->win_w = data->win->win_h * ASPECT_RATIO;
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

int	main(void)
{
	t_data		data;

	if (init_data(&data))
		ft_fatal_error("Error when initialising data", -1);

	// Aless's stuff
	// printf("size of int = %lu\n", sizeof(int));
	// t_color color = {255, 0, 0};
	// printf("color in int = %x\n", color_to_int(color));
	// t_color color2 = {0, 255, 0};
	// printf("color2 in int = %x\n", color_to_int(color2));
	// t_color color3 = add_color(color, color2);
	// printf("color3 in int = %x\n", color_to_int(color3));
	// t_color color4 = mult_color((t_color){100, 25, 230}, (t_color){45, 150, 200});
	// printf("color4 in int = %x\n", color_to_int(color4));
	// t_color color5 = change_intesity(color, 0.5);
	// printf("color5 in int = %x\n", color_to_int(color));
	
	// draw_filled_sphere(&data, create_sphere((t_point3D){200, 200, 200}, 100, color_to_int(color)));
	// draw_filled_sphere(&data, create_sphere((t_point3D){400, 200, 200}, 100, color_to_int(color2)));
	// draw_filled_sphere(&data, create_sphere((t_point3D){600, 200, 200}, 100, color_to_int(color3)));
	// draw_filled_sphere(&data, create_sphere((t_point3D){800, 200, 200}, 100, color_to_int(color4)));
	// draw_filled_sphere(&data, create_sphere((t_point3D){1000, 200, 200}, 100, color_to_int(color5)));
	// draw_filled_sphere(&data, create_sphere((t_point3D){1000, 200, 200}, 100, 0x77B5FE));

	// ---------- Eric stuff ----------
	t_scene		scene;
	t_camera	cam;
	t_shapes	shapes;

	cam.fov = 90;

	cam.pos.x = 0;
	cam.pos.y = 0;
	cam.pos.z = 0;

	cam.dir.x = 0;
	cam.dir.y = 0;
	cam.dir.z = 1;


	shapes.shape.sphere.color = 0x77B5FE;
	shapes.shape.sphere.radius = 7;
	shapes.shape.sphere.origin.x = 0;
	shapes.shape.sphere.origin.y = 0;
	shapes.shape.sphere.origin.z = 30;
	shapes.id = 0;
	shapes.next = 0;
	shapes.type = SPHERE;

	scene.camera = cam;
	scene.shapes = &shapes;

	rayshooter(&data, scene);

	mlx_put_image_to_window(data.win->mlx_ptr, data.win->mlx_win, data.img.mlx_img, 0, 0);
	mlx_hook(data.win->mlx_win, 17, 0, &exit_program, &data);
	mlx_key_hook(data.win->mlx_win, &ft_key_event, &data);
	mlx_loop(data.win->mlx_ptr);
	return (EXIT_SUCCESS);
}
