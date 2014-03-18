/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:58:27 by tdemay            #+#    #+#             */
/*   Updated: 2014/03/17 14:12:31 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "env.h"
# include "vector.h"
# include "cylinder.h"

/*
** \fn		int		int		parse_cylinder(t_env *e, t_vect *point, int *color)
** \brief	parse tous les cylindre pour fair les intersections
** \author	aelola
**
** \return	la distance du cylindre et la colour du cylindre le plus proche
*/
float		parse_cylinder(t_env *e, t_vect *point, t_color **color);

/*
** \fn		int		parse_sphere(t_env *e, t_vect *point, int *color)
** \brief	parse tous les spheres pour faire les intersections
** \author	tdemay
**
** \param	e : environnement contenant la scene et les objets
**				associé a la minilibx
** \param	point : vecteur normalisé du pixel a chargé
** \param	color : pointeur sur la couleur pour retour
** \param	z : numero de la lumiere utilise pour le calcul
** \return	la couleur de la sphere le plus proche pour le pixel calculé
*/
float		parse_sphere(t_env *e, t_vect *point, t_color **color, int z);

/*
** \fn		int		parse_plan(t_env *e, t_vect *point, int *color)
** \brief	parse tous les plans pour faire les intersections
** \author	tdemay
**
** \param	e : environnement contenant la scene et les objets
**				associé a la minilibx
** \param	point : vecteur normalisé du pixel a chargé
** \param	color : pointeur sur la couleur pour retour
** \return	la couleur du plan le plus proche pour le pixel calculé
*/
float		parse_plan(t_env *e, t_vect *point, t_color **color);

/*
** \fn		int		parse_element(t_env *e, t_vect *point)
** \brief	Fonction de parse de tous les elements de la scene pour raytracer
** \author	tdemay
**
** \param	e : environnement contenant la scene et les objets
**				associé a la minilibx
** \param	point : vecteur normalisé du pixel a chargé
** \return	la couleur de l'objet le plus proche pour le pixel calculé
*/
t_color		*parse_element(t_env *e, t_vect *point);

#endif /* !PARSE_H */
