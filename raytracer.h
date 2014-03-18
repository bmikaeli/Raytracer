/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 11:20:44 by tdemay            #+#    #+#             */
/*   Updated: 2014/03/15 15:09:51 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "class.h"
# include "parse.h"
# include "light.h"
# include "color.h"

/*
** \def		ECHAP
** \brief	Macro preprocesseur pour definir la touche ECHAP
** \author	tdemay
*/
# define ECHAP		65307

/*
** \def		SWIDTH
** \brief	Macro preprocesseur pour largeur fenetre
** \author	tdemay
**
** Suppression futur pour parametre dans la scene
*/
# define SWIDTH		1000

/*
** \def		SHEIGHT
** \brief	Macro preprocesseur pour hauteur fenetre
** \author	tdemay
**
** Suppression futur pour parametre dans la scene
*/
# define SHEIGHT	1000

#endif /* !RAYTRACER_H */
