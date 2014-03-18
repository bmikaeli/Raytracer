/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 14:24:37 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/03/16 15:30:10 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

float	vector_lenght(t_vect *vect)
{
	return (sqrt(SQUARE(vect->x) + SQUARE(vect->y)+ SQUARE(vect->z )));
}

void	vector_normalize(t_vect *vect)
{
	float			lenght;

	lenght = vector_lenght(vect);
	if (lenght > 0)
	{
		//lenght = 1 / lenght;
		vect->x = vect->x / lenght;
		vect->y = vect->y / lenght;
		vect->z = vect->z / lenght;
	}
}

t_vect	*vector_sub(t_vect *dest, t_vect *src)
{
	t_vect	*result;

	result = NEW(t_vect);
	result->x = dest->x - src->x;
	result->y = dest->y - src->y;
	result->z = dest->z - src->z;
	return (result);
}

t_vect	*vector_mult_scal(t_vect *dest, float scalaire)
{
	t_vect	*result;

	result = NEW(t_vect);
	result->x = dest->x * scalaire;
	result->y = dest->y * scalaire;
	result->z = dest->z * scalaire;
	return (result);
}