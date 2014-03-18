/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 19:26:59 by tdemay            #+#    #+#             */
/*   Updated: 2014/03/16 18:26:32 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAN_H
# define PLAN_H

# include "class.h"
# include "vector.h"
# include "cam.h"
# include "color.h"

/*
** \typedef	t_pan
** \struct	s_plan
** \brief	Object plan.
** \author	tdemay
**
*/
typedef struct	s_plan
{
	t_vect	*pos;
	t_vect	*dir;
	t_color	*color;
}				t_plan;

/*
** \fn		t_plan		*new_plan(float x, float y, float z, int c)
** \brief	Fonction de creation et initialisation de la struct t_plan
** \author	tdemay
**
** \param	x : valeur correspondant aux vecteur x de la position
** \param	y : valeur correspondant aux vecteur y de la position
** \param	z : valeur correspondant aux vecteur z de la position
** \param	c : valeur correspondant a la couleur de la plan
** \return	Pointeur de struct t_plan
*/
t_plan		*new_plan(t_vect *pos, t_vect *dir, t_color *c);

/*
** \fn		float		intersect_plan(t_vect *point, t_cam *cam, t_plan *p)
** \brief	Fonction de calcul d'intesection avec le plan
** \author	tdemay
**
** \param	point : vecteur normalisé du pixel a chargé
** \param	cam : l'objet camera
** \param	s : l'objet plan avec lequel on va tester l'intersection
** \return	la distance d'intersection (0 ou negatif si aucune intersection)
*/
float		intersect_plan(t_vect *point, t_cam *cam, t_plan *p);

#endif /* !PLAN_H */
