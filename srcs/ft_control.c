#include "ft_mlx.h"
#include <stdlib.h>

int	exit_program(t_data *prm)
{
	if (prm)
	{
		if (prm->img.mlx_img)
			mlx_destroy_image(prm->win->mlx_ptr, prm->img.mlx_img);
		if (prm->win)
		{
			if (prm->win->mlx_ptr)
				mlx_destroy_window(prm->win->mlx_ptr, prm->win->mlx_win);
			free(prm->win);
		}
	}
	exit(0);
}

int	ft_key_event(int key, void *params)
{
	t_data	*data;

	if (!params)
		return (1);
	data = (t_data *)params;
	if (key == 53)
		exit_program(data);
	return (0);
}
