/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 16:47:08 by aelola            #+#    #+#             */
/*   Updated: 2014/03/17 11:13:58 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include <stdio.h>

t_cyl			*new_cyl(float x, float y, float z, int rad, t_color *c)
{
	t_cyl		*new;

	new = NEW(t_cyl);
	new->pos = new_vect(x, y, z);
	new->rad = rad;
	new->color = c;
	return (new);
}

static float	get_min_sol(float b, float calc, float a)
{
	float		t1;
	float		t2;

	t1 = ((- b + sqrt(calc)) / (2 * a));
	t2 = ((- b - sqrt(calc)) / (2 * a));
	if (t1 < t2)
		return (t1);
	else
		return (t2);
}

t_vect			*ray_cylinder_b(t_vect *pos, t_vect *cam)
{
	float		a;
	t_vect		*mult_vector;

	a = DOTPROD(cam, pos);
	mult_vector = vector_mult_scal(pos, a);
	return (vector_sub(cam, mult_vector));
}

t_vect			*ray_cylinder_a(t_vect *pos, t_vect *dir)
{
	float		a;
	t_vect		*mult_vector;

	a = DOTPROD(dir, pos);
	mult_vector = vector_mult_scal(pos, a);
	return (vector_sub(dir, mult_vector));
}

float			intersect_cyl(t_vect *dir, t_vect *cam, t_cyl *cyl)
{
	float		a;
	float		b;
	float		c;
	float		calc;
	t_vect		*tab[2];

	vector_normalize(cyl->pos);
	tab[0] = ray_cylinder_a(cyl->pos, dir);
	tab[1] = ray_cylinder_b(cyl->pos, cam);
	a = DOTPROD(tab[0], tab[0]);
	b = 2 * DOTPROD(tab[0], tab[1]);
	c = DOTPROD(tab[1], tab[1]) - pow(cyl->rad, 2);
	calc = (pow(b, 2) - (4 * a * c)) / vector_lenght(dir);
	c = DOTPROD(tab[1], tab[1]) - pow(cyl->rad, 2);
	calc = (pow(b, 2) - (4 * a * c));
	if (calc >= 0)
		return (get_min_sol(b, calc, a));
	return (-1);
}

