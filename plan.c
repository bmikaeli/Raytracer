/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 19:29:55 by tdemay            #+#    #+#             */
/*   Updated: 2014/03/17 11:13:27 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plan.h"

t_plan			*new_plan(t_vect *pos, t_vect *dir, t_color *c)
{
	t_plan	*new;

	new = NEW(t_plan);
	new->pos = pos;
	new->dir = dir;
	new->color = c;
	return (new);
}

float			intersect_plan(t_vect *point, t_cam *cam, t_plan *p)
{
	float	t;
	float	dv;
	t_vect	*dir_norm;

	dir_norm = copy_vect(p->dir);
	vector_normalize(dir_norm);
	dv = - (dir_norm->x * p->pos->x) - (dir_norm->y * p->pos->y)
		- (dir_norm->z * p->pos->z);
	t = ((DOTPROD(dir_norm, cam->pos) - dv) / DOTPROD(dir_norm, point));
	if (t > 0)
		return (t);
	return (-1);
}
