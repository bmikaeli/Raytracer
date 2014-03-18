/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 15:28:24 by tdemay            #+#    #+#             */
/*   Updated: 2014/03/17 11:12:56 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include "class.h"

/*
** \def		SQUARE(x)
** \brief	Macro preprocesseur pour la multiplication de deux nombre
** \author	bmikaeli
*/
# define SQUARE(x) (x * x)

/*
** \def		ADD(v1, v2)
** \brief	Macro preprocesseur pour l'addition de deux vecteurs
** \author	tdemay
*/
# define ADD(v1, v2) new_vect(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z)

/*
** \def		SUB(v1, v2)
** \brief	Macro preprocesseur pour la soustraction de deux vecteurs
** \author	tdemay
*/
# define SUB(v1, v2) new_vect(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z)

/*
** \def		DOTPROD(v1, v2)
** \brief	Macro preprocesseur pour un produit scalaire de deux vecteurs
** \author	tdemay
*/
# define DOTPROD(v1, v2) ((v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z))

/*
** \def		MULTC(v1, i)
** \brief 	multiplication d'un vecteur par une constante
** \author	aelola
*/
# define MULTC(v1, i) new_vect(i * v1->x, i * v1->y, i * v1->z)

/*
** \typedef	t_vect
** \struct	s_vect
** \brief	Object vecteur.
** \author	tdemay
**
** t_vect est un objet/structure definissant un vecteur mathématique.
** Il contient ses donnees : x, y, z.
*/
typedef struct	s_vect
{
	float	x;
	float	y;
	float	z;
}				t_vect;

/*
** \fn		t_vect	*new_vect(float x, float y, float z)
** \brief	Fonction de creation et initialisation de la struct t_vect
** \author	tdemay
**
** \param	x : valeur correspondant aux vecteur x
** \param	y : valeur correspondant aux vecteur y
** \param	z : valeur correspondant aux vecteur z
** \return	Pointeur de struct t_vect
*/
t_vect	*new_vect(float x, float y, float z);

/*
** \fn		t_vect	*copy_vect(t_vect *v)
** \brief	cree un nouveau vecteur et renvoie un pointeur
** \author	bmikaeli
**
** \param	v : float x, float y, float z
** \return	Pointeur de struct t_vect
*/
t_vect	*copy_vect(t_vect *v);

/*
** \fn		t_vect	*new_svect(float x, float y)
** \brief	Fonction de creation et initialisation
**			de la struct t_vect particulier
** \author	tdemay
**
** \param	x : valeur correspondant aux vecteur x
** \param	y : valeur correspondant aux vecteur y
** \return	Pointeur de struct cam initialise.
**
** Pour vecteur normaliser particulier ...
*/
t_vect	*new_svect(float phi, float theta);

/*
** \fn		t_vect	*vector_mult_scal(t_vect *dest, float scalaire)
** \brief	fait le produit scalaire de 2 vecteur
** \author	aelola
*/
t_vect	*vector_mult_scal(t_vect *dest, float scalaire);

/*
** \fn		t_vect		*vector_sub(t_vect *dest, t_vect *src)
** \brief	soustraire 2 vecteur
** \author	aelola
*/
t_vect		*vector_sub(t_vect *dest, t_vect *src);

/*
** \fn		void	vector_normalize(t_vect *vect)
** \brief	normalise un vecteur
** \author	aelola
*/
void	vector_normalize(t_vect *vect);

/*
** \fn		void	vector_normalize(t_vect *vect)
** \brief	retourne la longuer du vecteur
** \author	aelola
*/
float	vector_lenght(t_vect *vect);

#endif /* !VECTOR_H */
