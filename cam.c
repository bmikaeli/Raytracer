/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:55:26 by tdemay            #+#    #+#             */
/*   Updated: 2014/03/13 18:50:38 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cam.h"

t_cam	*cam_init(void)
{
	t_cam	*new;

	new = NEW(t_cam);
	new->pos = new_vect(0, 0, 0);
	new->FOV = tan((45 * M_PI) / 180);
	return (new);
}