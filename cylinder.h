/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 16:47:12 by aelola            #+#    #+#             */
/*   Updated: 2014/03/16 18:21:14 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "class.h"
# include "vector.h"
# include "cam.h"
# include "color.h"

/*
** \typedef	t_cyl
** \struct	s_cyl
** \brief	Object cylindre.
** \author	aelola
*/
typedef struct	s_cyl
{
	t_vect	*pos;
	t_vect	*dir;
	int		rad;
	t_color	*color;
}				t_cyl;

/*
** \fn		float intersect_cyl(t_vect *dir, t_vect *cam, t_cyl *cyl)
** \brief	permet de verifier si il y a une intersection avec un cylindre
** \author	aelola
**
** \param
** \return
*/
float		intersect_cyl(t_vect *dir, t_vect *cam, t_cyl *cyl);


/*
** \fn		t_cyl *new_cyl(float x, float y, float z, int rad, t_color *c)
** \brief	ajoute un cylindre a la scene
** \author	aelola
**
** \param
** \return
*/
t_cyl		*new_cyl(float x, float y, float z, int rad, t_color *c);

#endif /* !CYLINDER_H */
