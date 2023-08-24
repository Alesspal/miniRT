/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:29:02 by alesspal          #+#    #+#             */
/*   Updated: 2023/08/24 13:26:15 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
#define FT_VECTOR_H

typedef struct s_vector
{
	float x;
	float y;
	float z;
}	t_vector;

t_vector	ft_normalize(t_vector v);
float		ft_dot(t_vector v1, t_vector v2);

#endif