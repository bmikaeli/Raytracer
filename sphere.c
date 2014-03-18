/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 16:06:54 by tdemay            #+#    #+#             */
/*   Updated: 2014/03/17 11:13:20 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

t_sphere		*new_sphere(float x, float y, float z, float size, t_color *c)
{
	t_sphere	*new;

	new = NEW(t_sphere);
	new->pos = new_vect(x, y, z);
	new->rayon = size;
	new->color = c;
	return (new);
}

float			get_min_sol(float b, float delta, float a)
{
	float	t1;
	float	t2;

	t1 = ((- b + sqrt(delta)) / (2 * a));
	t2 = ((- b - sqrt(delta)) / (2 * a));
	if (t1 < t2)
		return (t1);
	else
		return (t2);
}

float			intersect_sphere(t_vect *point, t_cam *cam, t_sphere *s)
{
	t_vect	*var;
	float	a;
	float	b;
	float	c;
	float	delta;

	var = SUB(cam->pos, s->pos);
	a = DOTPROD(point, point);
	b = 2 * DOTPROD(point, var);
	c = DOTPROD(var, var) - SQUARE(s->rayon);
	delta = SQUARE(b) - (4 * a * c);
	if (delta >= 0)
		return (get_min_sol(b, delta, a));
	return (-1);
}
