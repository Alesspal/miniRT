/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:03:59 by alesspal          #+#    #+#             */
/*   Updated: 2023/08/26 19:47:57 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

# include "../mlx/mlx.h"

# define ASPECT_RATIO 16.0 / 9.0

typedef struct s_mlx_win
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		win_h;
	int		win_w;
}	t_mlx_win;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	t_mlx_win		*win;
	t_img			img;
}	t_data;

void	ft_img_pix_put(t_data *data, int x, int y, int color);
int		ft_key_event(int key, void *params);
int		exit_program(t_data *prm);

#endif