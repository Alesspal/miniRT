#include "../libft/libft.h"
#include "../incl/ft_mlx.h"
#include <stdio.h>

//test

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
	data->win->win_ht = 1080;
	data->win->win_wt = data->win->win_ht * ASPECT_RATIO;
	data->win->mlx_win = mlx_new_window(data->win->mlx_ptr, data->win->win_wt,
			data->win->win_ht, "Minirt");
	if (!data->win->mlx_win)
		return (1);
	data->img.mlx_img = mlx_new_image(data->win->mlx_ptr, data->win->win_wt,
			data->win->win_ht);
	if (!data->img.mlx_img)
		return (1);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	if (!data->img.addr)
		return (1);
	return (0);
}

int main(void)
{
	t_data		data;

	if (init_data(&data))
	{
		printf("Error : initialisation");
		return (EXIT_FAILURE);
	}

	mlx_put_image_to_window(data.win->mlx_ptr, data.win->mlx_win, data.img.mlx_img, 0, 0);
	mlx_hook(data.win->mlx_win, 17, 0, &exit_programm, &data);
	mlx_key_hook(data.win->mlx_win, &ft_key_event, &data);
	mlx_loop(data.win->mlx_ptr);
	return (EXIT_SUCCESS);
}
