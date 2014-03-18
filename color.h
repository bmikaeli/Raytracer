/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 16:08:49 by aelola            #+#    #+#             */
/*   Updated: 2014/03/17 14:07:25 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "class.h"

# define COLOR(x) (x->r << 16) + (x->g << 8) + x->b
# define MAX(x, y) ((x > y) ? x : y)
# define MIN(x, y) ((x < y) ? x : y)
/*
** \typedef	t_cyl
** \struct	s_cyl
** \brief	Object couleur.
** \author	aelola
*/
typedef struct	s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;
/*
** \fn		t_color		*sub_colour(t_color *c1, const t_color *c2)
** \brief	Fonction permettant la synthese soustractive
** \args	prend en parametre deux structures t_color
** \author	bmikaeli
**
** \return	malloc une structure t_color et la renvoie
*/
t_color		*sub_colour(t_color *c1, const t_color *c2);


/*
** \fn		t_color		*sub_colour(t_color *c1, const t_color *c2)
** \brief	Fonction soustrayant deux couleurs
** \args	prend en parametre deux structures t_color
**
** \author	bmikaeli
*/
void		sub_color(t_color *c1, const t_color *c2);

/*
** \fn		t_color		*new_color(int r, int g, int b)
** \brief
** \author	aelola
**
** \param
** \return
*/
t_color		*new_color(int r, int g, int b);

/*
** \fn		void		mult(t_color *c1, double f)
** \brief	e
** \author	aelola
**
** \param
*/
void		mult(t_color *c1, double f);

/*
** \fn		t_color		*cpy_color(t_color *c)
** \brief
** \author	aelola
**
** \param
** \return
*/
t_color		*cpy_color(t_color *c);


/*
** \fn		t_color		*add_colour(t_color *c1, const t_color *c2)
** \brief	Fonction additionnant deux couleurs
** \args	prend en parametre deux structures t_color
**
** \author	bmikaeli
*/
t_color		*add_colour(t_color *c1, const t_color *c2);

#endif /* !COLOR_H */
