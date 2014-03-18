/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:11:23 by tdemay            #+#    #+#             */
/*   Updated: 2014/03/16 18:25:27 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAM_H
# define CAM_H

# include "vector.h"

/*
** \typedef	t_cam
** \struct	s_cam
** \brief	Object camera.
** \author	tdemay
**
** t_cam est un objet/structure contenant les configurations de la camera
** permettant la génération de la prise de vue dans l'espace en raytracing.
*/
typedef struct	s_cam
{
	t_vect	*pos;
	float	FOV;
}				t_cam;

/*
** \fn		t_cam	*cam_init(void)
** \brief	Fonction de creation et initialisation de la struct cam.
** \author	tdemay
**
** \return	Pointeur de struct cam initialise.
*/
t_cam			*cam_init(void);

#endif /* !CAM_H */
