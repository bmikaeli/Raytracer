/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 13:36:07 by aelola            #+#    #+#             */
/*   Updated: 2014/03/16 18:25:40 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "vector.h"
# include "color.h"

/*
** \typedef	t_light
** \struct	s_light
** \brief	Object light.
** \author	tdemay
**
** t_cam est un objet/structure contenant les configurations de la camera
** permettant la génération de la prise de vue dans l'espace en raytracing.
*/
typedef struct	s_light
{
	t_vect		*pos;
	t_color		*clr;
}				t_light;

/*
** \fn		t_light	*make_light(t_vect *p, t_color *c)
** \brief	declaration de la lumiere
** \author	aelola
**
** \param
*/
t_light	*make_light(t_vect *p, t_color *c);

#endif /* !LIGHT_H */
