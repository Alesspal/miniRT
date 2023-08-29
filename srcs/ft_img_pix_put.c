#include "ft_mlx.h"

void	ft_img_pix_put(t_data *data, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if (x >= data->win->win_w || y >= data->win->win_h || x <= 0 || y <= 0)
		return ;
	i = data->img.bpp - 8;
	pixel = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	while (i >= 0)
	{
		if (data->img.endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (data->img.bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
