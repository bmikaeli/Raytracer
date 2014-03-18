/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 16:28:56 by tdemay            #+#    #+#             */
/*   Updated: 2014/03/17 13:23:50 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "sphere.h"
# include "plan.h"
# include "cylinder.h"

/*
** \typedef	t_scene
** \struct	s_scene
** \brief	Object scene.
** \author	tdemay
**
** t_scene est un objet/structure contenant les differents objets
** qui on etais ajoutes a la scene.
** Le nombre de sphere, et un tableau d'object t_sphere.
** Le nombre de plan, et un tableau d'object t_plan.
** Le nombre de lumiere, et un tableau d'object t_light.
** Dans le futur d'autres objets peuvent se rajouter.
*/
typedef struct	s_scene
{
	int			count_s;
	int			count_p;
	int			count_l;
	int			count_cyl;
	t_sphere	**tab_s;
	t_plan		**tab_p;
	t_cyl		**tab_cyl;
	t_light		**tab_l;
}				t_scene;

t_scene		*add_light(t_scene *rob, t_light *new);
/*
** \fn		t_scene		*new_scene(void)
** \brief	Fonction de creation et initialisation de la struct scene.
** \author	tdemay
**
** \return	Pointeur de struct scene initialise.
*/
t_scene		*new_scene(void);

/*
** \fn		t_scene		*add_sphere(t_scene *rob, t_sphere *new)
** \brief	Fonction d'ajout d'une sphere dans la scene
** \author	tdemay
**
** \param	rob : la scene ou l'on veut rajouter la sphere
** \param	new : la sphere a ajouter a la scene
** \return	Pointeur de struct scene avec ajout d'une sphere
*/
t_scene		*add_sphere(t_scene *rob, t_sphere *new);

/*
** \fn		t_scene		*add_plan(t_scene *rob, t_plan *new)
** \brief	Fonction d'ajout d'un plan dans la scene
** \author	tdemay
**
** \param	rob : la scene ou l'on veut rajouter le plan
** \param	new : le plan a ajouter a la scene
** \return	Pointeur de struct scene avec ajout d'un plan
*/
t_scene		*add_plan(t_scene *rob, t_plan *new);

/*
** ajoute un cylindre a la scene
*/
t_scene		*add_cyl(t_scene *rob, t_cyl *cyl);

#endif /* !SCENE_H */
