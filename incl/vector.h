/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:48:15 by alesspal          #+#    #+#             */
/*   Updated: 2023/10/17 15:58:55 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

t_vec		create_vec(float x, float y, float z);
t_vec		normalize(t_vec v);
float		dot(t_vec v1, t_vec v2);
t_vec		get_vec(t_vec p1, t_vec p2);
t_vec		vec_sub(t_vec vec1, t_vec vec2);
t_vec		vec_add(t_vec vec1, t_vec vec2);
t_vec		vec_mult(t_vec v, float scalar);
t_vec		cross_product(t_vec v1, t_vec v2);
float		vec_size(t_vec v);

#endif