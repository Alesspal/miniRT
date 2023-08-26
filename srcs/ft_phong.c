/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phong.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:07:19 by alesspal          #+#    #+#             */
/*   Updated: 2023/08/26 17:12:48 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_raytracing.h"
#include "../incl/ft_vector.h"
#include <stdio.h>
#include <stdlib.h>
#include "ft_raytracing.h"

// sphere N = P - C
t_vec	get_n_sphere(t_intersection *p)
{
	t_vec		n;
	t_sphere	sphere;

	sphere = (t_sphere)p->shape.sphere;
	n = ft_create_vec(p->coordinate.x - sphere.origin.x,
		p->coordinate.y - sphere.origin.y,
		p->coordinate.z - sphere.origin.z);
	return (n);
}

// cylinder N = P - C - dot(cam, P - C) * cam
t_vec	get_n_cylinder(t_intersection *p)
{
	t_vec		n;
	t_cylinder	cylinder;
	t_vec		pc;
	t_vec		v;
	float		dot_v_pc;

	cylinder = (t_cylinder)p->shape.cylinder;
	pc = ft_create_vec(p->coordinate.x - cylinder.origin.x,
		p->coordinate.y - cylinder.origin.y,
		p->coordinate.z - cylinder.origin.z);
	v = cylinder.orientation;
	dot_v_pc = ft_dot(v, pc);
	v.x *= dot_v_pc;
	v.y *= dot_v_pc;
	v.z *= dot_v_pc;
	n.x = pc.x - v.x;
	n.y = pc.y - v.y;
	n.z = pc.z - v.z;
	return (n);
}

// plan N = orientation of plan
t_vec	get_n_plan(t_intersection *p)
{
	t_vec		n;
	t_plan		plan;

	plan = (t_plan)p->shape.plan;
	n = ft_create_vec(plan.orientation.x,
		plan.orientation.y,
		plan.orientation.z);
	return (n);
}

t_vec get_n(t_intersection *p)
{
	if (p->shape_type == SHPERE)
		return (get_n_sphere(p));
	else if (p->shape_type == CYLINDER)
		return (get_n_cylinder(p));
	else
		return (get_n_plan(p));
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
	t_vec			n;
	t_cylinder		cylinder;
	t_sphere		sphere;
	t_plan			plan;
	t_intersection	p1;
	t_intersection	p2;
	t_intersection	p3;

	p1.coordinate = ft_create_vec(3, 4 , 0);
	cylinder.origin = ft_create_vec(3, 5, -2);
	cylinder.orientation = ft_create_vec(1, 4, -3);
	p1.shape.cylinder = cylinder;
	p1.shape_type = CYLINDER;
	n = get_n(&p1);
	printf("cylinder : n.x = %f, n.y = %f, n.z = %f\n", n.x, n.y, n.z);
	n = ft_normalize(n);
	printf("normalized : n.x = %f, n.y = %f, n.z = %f\n", n.x, n.y, n.z);

	p2.coordinate = ft_create_vec(-5, -5 , -5);
	sphere.origin = ft_create_vec(-10, -10, -10);
	p2.shape.sphere = sphere;
	p2.shape_type = SHPERE;
	n = get_n(&p2);
	printf("sphere : n.x = %f, n.y = %f, n.z = %f\n", n.x, n.y, n.z);
	n = ft_normalize(n);
	printf("normalized : n.x = %f, n.y = %f, n.z = %f\n", n.x, n.y, n.z);

	p3.coordinate = ft_create_vec(3, 4 , -5);
	plan.orientation = ft_create_vec(9, -3, 275);
	p3.shape.plan = plan;
	p3.shape_type = PLAN;
	n = get_n(&p3);
	printf("plan : n.x = %f, n.y = %f, n.z = %f\n", n.x, n.y, n.z);
	n = ft_normalize(n);
	printf("normalized : n.x = %f, n.y = %f, n.z = %f\n", n.x, n.y, n.z);
	
	return (0);
} */