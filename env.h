/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:13:55 by tdemay            #+#    #+#             */
/*   Updated: 2014/03/17 13:18:57 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "scene.h"
# include "light.h"
# include "cam.h"

/*
** \typedef	t_env
** \struct	s_env
** \brief	Object environnement.
** \author	tdemay
**
** t_env contient l'environnement global du programme.
** MLX et WIN concerne la minilibx.
** cam va contenir notre object/structure t_cam (cf. cam.h)
** s va contenir notre object/structure t_scene (cf. scene.h)
*/
typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_cam		*cam;
	t_scene		*s;
	t_light		**l;
}				t_env;

#endif /* !ENV_H */
