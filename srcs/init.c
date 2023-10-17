#include "ft_raytracing.h"
#include "ft_mlx.h"
#include <math.h>
#include <stdlib.h>

// Initialize the data structure and the mlx window
int	init_data(t_data *data)
{
	data->win = malloc(sizeof(t_mlx_win));
	data->img.mlx_img = NULL;
	data->img.addr = NULL;
	if (!data->win)
		return (-1);
	data->win->mlx_ptr = mlx_init();
	if (!data->win->mlx_ptr)
		return (-1);
	data->win->aspect_ratio = 16.0 / 9.0;
	data->win->win_h = 1080;
	data->win->win_w = data->win->win_h * data->win->aspect_ratio;
	data->win->mlx_win = mlx_new_window(data->win->mlx_ptr, data->win->win_w,
			data->win->win_h, "miniRT");
	if (!data->win->mlx_win)
		return (-1);
	data->img.mlx_img = mlx_new_image(data->win->mlx_ptr, data->win->win_w,
			data->win->win_h);
	if (!data->img.mlx_img)
		return (-1);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	if (!data->img.addr)
		return (-1);
	return (0);
}

// Set up the camera's basis vectors and the virtual screen
void	init_camera(t_camera *cam, float aspect_ratio)
{
	t_vec	temp_up;

	if ((cam->dir.x == 0 && cam->dir.y == 1 && cam->dir.z == 0)
		|| (cam->dir.x == 0 && cam->dir.y == -1 && cam->dir.z == 0))
	{
		temp_up.x = 0;
		temp_up.y = 0;
		temp_up.z = 1;
	}
	else
	{
		temp_up.x = 0;
		temp_up.y = 1;
		temp_up.z = 0;
	}
	cam->v_scr.d = 1;
	cam->dir = ft_normalize(cam->dir);
	cam->right = ft_normalize(cross_product(cam->dir, temp_up));
	cam->up = ft_normalize(cross_product(cam->right, cam->dir));
	cam->v_scr.width = 2 * cam->v_scr.d * tan(cam->fov * M_PI / 360);
	cam->v_scr.height = cam->v_scr.width / aspect_ratio;
	cam->v_scr.center = vec_add(cam->pos, vec_mult(cam->dir, cam->v_scr.d));
	cam->v_scr.top_left = vec_add(vec_sub(cam->v_scr.center,
				vec_mult(cam->right, cam->v_scr.width / 2)),
			vec_mult(cam->up, cam->v_scr.height / 2));
}

// Initialize the scene to 0
void	init_scene(t_scene *scene)
{
	scene->ambient_light.color.r = 0;
	scene->ambient_light.color.g = 0;
	scene->ambient_light.color.b = 0;
	scene->ambient_light.intensity = 0;
	scene->spot_light.color.r = 0;
	scene->spot_light.color.g = 0;
	scene->spot_light.color.b = 0;
	scene->spot_light.intensity = 0;
	scene->spot_light.pos.x = 0;
	scene->spot_light.pos.y = 0;
	scene->spot_light.pos.z = 0;
	scene->camera.pos.x = 0;
	scene->camera.pos.y = 0;
	scene->camera.pos.z = 0;
	scene->camera.dir.x = 0;
	scene->camera.dir.y = 0;
	scene->camera.dir.z = 0;
	scene->camera.fov = 0;
	scene->shapes = NULL;
}
