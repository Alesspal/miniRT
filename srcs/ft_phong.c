/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phong.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:07:19 by alesspal          #+#    #+#             */
/*   Updated: 2023/08/28 10:31:07 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_raytracing.h"
#include "../incl/ft_vector.h"
#include <stdio.h>
#include <stdlib.h>
#include "ft_raytracing.h"

/* int diffuse(t_scene scene, t_intersection *p)
{
	return (1);
}

int shadow(t_scene scene, t_intersection *p)
{
	return (0x000000);
}

int specular(t_scene scene, t_intersection *p)
{
	return (1);
}

// à proteger
void ft_phong(t_data data, t_scene scene, t_intersection *p)
{
	int x;
	int y;
	int color;
	
	x = 0;
	y = 0;
	// parcourir tout les pixels
	while (y < data.win->win_h)
	{
		while (x < data.win->win_w)
		{
			color = 0;
			if (x == p->pixel_coordinate.x && y == p->pixel_coordinate.y)
			{
				if (intersection(p->coordinate, scene.spot_light.coordinate))
				{
					// noir
				}
				else
				{
					// algo
				}
				p = p->next;
			}
			// ajout de la couleur ambiante
			ft_img_pix_put(&data, p->pixel_coordinate.x, p->pixel_coordinate.y, color);
			x++;
		}
		y++;
	}
} */

// fonction qui calcul la couleur d'un pixel
// prend en param la position de la lumière
// et les intersections de la caméra jusqu'a un pixel d'une forme visible (P)
// {
// 	while (les points P)
// 	{
// 		calcule comment la lumière interagis avec la couleur de la sphere
// 	}
// 	met le reste dans la couleur ambiante définit
// }

// fonction qui calcule la couleur
// prend en param un point P, la position de la lumière et la structure de la forme
// {
// 	if (P intersecte qqch de sa position jusqu'à la source lumineuse)
// 		peindre le pixel en noir ou couleur ambiante
// 	sinon
//	{
//		créer le vecteur N
//		vect N = vect P - vect O (cendre de la forme) (fonction find_N) 
//		le normaliser
//		créer le vecteur L
//		vect L = vect S (source lumineuse) - vect P
//		le normaliser
//		créer le vecteur V (optionnel)
//		vect V =  vect cam - vect P (optionnel)
//		le normaliser (optionnel)
//		calculer le produit scalaire de N * L
//		couleur = I source * RGB de la forme * produit scalaire de N * L
//		peindre le pixel en la couleur trouvé
//	}
// }
