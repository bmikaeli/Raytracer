/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 16:08:45 by aelola            #+#    #+#             */
/*   Updated: 2014/03/17 14:06:43 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color		*new_color(int r, int g, int b)
{
	t_color		*c;

	c = NEW(t_color);
	c->r = r;
	c->g = g;
	c->b = b;
	return (c);
}

void		mult(t_color *c1, double f)
{
	c1->r = MIN(c1->r * f, 255);
	c1->g = MIN(c1->g * f, 255);
	c1->b = MIN(c1->b * f, 255);
}

t_color		*cpy_color(t_color *c)
{
	return (new_color(c->r, c->g, c->b));
}

t_color		*sub_colour(t_color *c1, const t_color *c2)
{
	t_color		*c3;

	c3 = NEW(t_color);
	c3->r = -MIN(c1->r - c2->r, 0);
	c3->g = -MIN(c1->g - c2->g, 0);
	c3->b = -MIN(c1->b - c2->b, 0);
	return (c3);
}

void		sub_color(t_color *c1, const t_color *c2)
{
	c1->r = MIN(c1->r - c2->r, 0);
	c1->g = MIN(c1->g - c2->g, 0);
	c1->b = MIN(c1->b - c2->b, 0);
}

t_color		*add_colour(t_color *c1, const t_color *c2)
{
	t_color *c3;

	c3 = NEW(t_color);
	c3->r = MIN(c1->r + c2->r, 255);
	c3->g = MIN(c1->g + c2->g, 255);
	c3->b = MIN(c1->b + c2->b, 255);
	return (c3);
}
