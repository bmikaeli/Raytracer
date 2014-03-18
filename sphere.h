/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 16:01:24 by tdemay            #+#    #+#             */
/*   Updated: 2014/02/16 16:01:24 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "class.h"
# include "vector.h"
# include "cam.h"
# include "light.h"
# include <math.h>

/*
** \typedef	t_sphere
** \struct	s_sphere
** \brief	Object sphere
** \author	tdemay
**
** t_sphere est un objet/structure contenant les informations sur
** une sphere défini par sa position (en son centre),
** un rayon et une couleur.
*/
typedef struct	s_sphere
{
	t_vect	*pos;
	float	angle;
	float	rayon;
	t_color	*color;
}				t_sphere;

/*
** \fn		t_sphere *new_sphere(float x, float y, float z, float size, int c)
** \brief	Fonction de creation et initialisation de la struct t_sphere
** \author	tdemay
**
** \param	x : valeur correspondant aux vecteur x de la position
** \param	y : valeur correspondant aux vecteur y de la position
** \param	z : valeur correspondant aux vecteur z de la position
** \param	size : valeur correspondant a la taille de la sphere
** \param	c : valeur correspondant a la couleur de la sphere
** \return	Pointeur de struct t_sphere
*/
t_sphere	*new_sphere(float x, float y, float z, float size, t_color *c);

/*
** \fn		float		get_min_sol(float b, float calc, float a)
** \brief	Fonction de calcul des solutions d'une equation du 2nd degres
** \author	tdemay
**
** \param	b : valeur de l'equation b
** \param	calc : le discriminant
** \param	z : valeur de l'equation a
** \return	la solution la plus petite de la resolution d'equation.
*/
float		get_min_sol(float b, float calc, float a);

/*
** \fn		float		intersect_sphere(t_vect *point, t_cam *cam, t_sphere *s)
** \brief	Fonction de calcul d'intesection avec la sphere
** \author	tdemay
**
** \param	point : vecteur normalisé du pixel a chargé
** \param	cam : l'objet camera
** \param	s : l'objet sphere avec lequel on va tester l'intersection
** \return	la distance d'intersection (0 ou negatif si aucune intersection)
*/
float		intersect_sphere(t_vect *point, t_cam *cam, t_sphere *s);

#endif /* !SPHERE_H */
