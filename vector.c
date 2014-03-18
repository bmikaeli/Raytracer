/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 15:30:07 by tdemay            #+#    #+#             */
/*   Updated: 2014/03/14 19:05:39 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vect	*copy_vect(t_vect *v)
{
	return (new_vect(v->x, v->y, v->z));
}

t_vect	*new_vect(float x, float y, float z)
{
	t_vect	*new;

	new = NEW(t_vect);
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}

t_vect	*new_svect(float x, float y)
{
	t_vect	*new;

	new = NEW(t_vect);
	new->x = tan(y) * 100;
	new->y = tan(x) * 100;
	new->z = 0;
	return (new);
}

