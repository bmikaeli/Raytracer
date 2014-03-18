/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 13:35:59 by aelola            #+#    #+#             */
/*   Updated: 2014/03/17 13:12:23 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_light		*make_light(t_vect *p, t_color *c)
{
	t_light		*l;

	l = NEW(t_light);
	l->pos = copy_vect(p);
	l->clr = c;
	return (l);
}
