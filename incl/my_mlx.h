/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:48:09 by alesspal          #+#    #+#             */
/*   Updated: 2023/10/17 15:58:07 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MLX_H
# define MY_MLX_H

# include "mlx.h"
# include <stdio.h>

typedef struct s_mlx_win
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		win_h;
	int		win_w;
	double	aspect_ratio;
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

void	img_pix_put(t_data *data, int x, int y, int color);
int		key_event(int key, void *params);
int		exit_program(t_data *prm);
int		init_data(t_data *data);

#endif