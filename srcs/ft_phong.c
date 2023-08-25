/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phong.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:07:19 by alesspal          #+#    #+#             */
/*   Updated: 2023/08/25 15:58:23 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_raytracing.h"
#include "../incl/ft_vector.h"
#include <stdio.h>
#include <stdlib.h>

// sphere N = P - C
t_vec	get_normalized_n_sphere(t_intersection *p)
{
	t_vec		n;
	t_sphere	*sphere;

	sphere = (t_sphere *)p->shape;
	n = ft_create_vec(p->coordinate.x - sphere->origin.x,
		p->coordinate.y - sphere->origin.y,
		p->coordinate.z - sphere->origin.z);
	return (ft_normalize(n));
}

// cylinder N = P - C - dot(cam, P - C) * cam
t_vec	get_normalized_n_cylinder(t_intersection *p)
{
	t_vec		n;
	t_cylinder	*cylinder;
	t_vec		pc;
	t_vec		v;
	float		dot_v_pc;

	cylinder = (t_cylinder *)p->shape;
	pc = ft_create_vec(p->coordinate.x - cylinder->origin.x,
		p->coordinate.y - cylinder->origin.y,
		p->coordinate.z - cylinder->origin.z);
	v = cylinder->orientation;
	dot_v_pc = ft_dot(v, pc);
	v.x *= dot_v_pc;
	v.y *= dot_v_pc;
	v.z *= dot_v_pc;
	n.x = pc.x - v.x;
	n.y = pc.y - v.y;
	n.z = pc.z - v.z;
	return (ft_normalize(n));
}

// plan N = orientation of plan
t_vec	get_normalized_n_plan(t_intersection *p)
{
	t_vec		n;
	t_plan		*plan;

	plan = (t_plan *)p->shape;
	n = ft_create_vec(plan->orientation.x,
		plan->orientation.y,
		plan->orientation.z);
	return (ft_normalize(n));
}

// structure scene qui à comme variable
// lumière ambiante
// light spot
// caméra
// liste de tout les objets

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

/* int main(void)
{
	t_cylinder		cylinder;
	t_intersection	p1;
	t_sphere		sphere;
	t_intersection	p2;
	t_plan			plan;
	t_intersection	p3;

	p1.coordinate = ft_create_vec(3, 4 , 0);
	cylinder.origin = ft_create_vec(3, 5, -2);
	cylinder.orientation = ft_create_vec(1, 4, -3);
	p1.shape = &cylinder;
	t_vec n_cylinder = get_normalized_n_cylinder(&p1);
	printf("cylinder : n.x = %f, n.y = %f, n.z = %f\n", n_cylinder.x, n_cylinder.y, n_cylinder.z);

	p2.coordinate = ft_create_vec(-5, -5 , -5);
	sphere.origin = ft_create_vec(-10, -10, -10);
	p2.shape = &sphere;
	t_vec n_sphere = get_normalized_n_sphere(&p2);
	printf("sphere : n.x = %f, n.y = %f, n.z = %f\n", n_sphere.x, n_sphere.y, n_sphere.z);

	p3.coordinate = ft_create_vec(3, 4 , -5);
	plan.orientation = ft_create_vec(9, -3, 275);
	p3.shape = &plan;
	t_vec n_plan = get_normalized_n_plan(&p3);
	printf("plan : n.x = %f, n.y = %f, n.z = %f\n", n_plan.x, n_plan.y, n_plan.z);

	return (0);
} */