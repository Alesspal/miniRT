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

int	main(void)
{
	t_data		data;

	if (init_data(&data))
		ft_fatal_error("Error when initialising data", -1);

	t_scene		scene;
	t_camera	cam;
	t_shapes	shapes;
	t_sphere	sphere1;
	t_sphere	sphere2;
	t_sphere	sphere3;

	cam.fov = 150;

	cam.pos.x = 0;
	cam.pos.y = 0;
	cam.pos.z = 0;

	cam.dir.x = 0;
	cam.dir.y = 0;
	cam.dir.z = -1;

	sphere1.color = 0xFFFFFF;
	sphere1.radius = 5;
	sphere1.origin.x = 5;
	sphere1.origin.y = -3;
	sphere1.origin.z = -20;

	sphere2.color = 0xFFFFFF;
	sphere2.radius = -5;
	sphere2.origin.x = -5;
	sphere2.origin.y = -3;
	sphere2.origin.z = -20;

	sphere3.color = 0xFF0000;
	sphere3.radius = 6;
	sphere3.origin.x = 0;
	sphere3.origin.y = 0;
	sphere3.origin.z = -20;

	shapes.shape.sphere = sphere1;
	shapes.id = 0;
	shapes.type = SPHERE;
	shapes.next = malloc(sizeof(t_shapes));

	shapes.next->shape.sphere = sphere2;
	shapes.next->id = 1;
	shapes.next->type = SPHERE;
	shapes.next->next = malloc(sizeof(t_shapes));

	shapes.next->next->shape.sphere = sphere3;
	shapes.next->next->id = 2;
	shapes.next->next->type = SPHERE;
	shapes.next->next->next = NULL;

	scene.camera = cam;
	scene.shapes = &shapes;

	compute_camera(&scene.camera, data.win->aspect_ratio);
	draw_scene(&data, scene);

	mlx_put_image_to_window(data.win->mlx_ptr, data.win->mlx_win, data.img.mlx_img, 0, 0);
	mlx_hook(data.win->mlx_win, 17, 0, &exit_program, &data);
	mlx_key_hook(data.win->mlx_win, &ft_key_event, &data);
	mlx_loop(data.win->mlx_ptr);
	return (EXIT_SUCCESS);
}
