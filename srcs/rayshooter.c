/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayshooter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:54:41 by eholzer           #+#    #+#             */
/*   Updated: 2023/08/25 16:09:06 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"
#include "ft_raytracing.h"
#include <math.h>

int	get_dist_to_screen(int win_w, int fov)
{
	return ((win_w / 2) / tan(fov / 2));
}

// under construction
// void	fill_prime_vec(t_vec *prime_vec, int dist_to_screen, t_mlx_win win)
// {
// 	prime_vec->x = 
// }

void	rayshooter(t_data *data, t_camera cam)
{
	int		i;
	int		j;
	// (void) cam;
	int		dist_to_screen;
	t_vec	curr_prime_vec;

	dist_to_screen = get_dist_to_screen(data->win->win_w, cam.fov);
	j = -1;
	while (++j < data->win->win_h)
	{
		i = -1;
		while (++i < data->win->win_w)
		{
			// fill_prime_vec(&curr_prime_vec);
			ft_img_pix_put(data, i, j, 0x77B5FE);
		}
	}
}
