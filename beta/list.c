/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 15:55:29 by tdemay            #+#    #+#             */
/*   Updated: 2014/01/29 15:55:29 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_lst	*init_t_lst(char *type, void *obj, int x, int y, int z)
{
	t_lst	*ret;

	ret = NEW(t_lst);
	ret->type = type;
	ret->obj = obj;
	ret->x = x;
	ret->y = y;
	ret->z = z;
	ret->next = NULL;
	return (ret);
}

t_lst	*add_t_lst(t_lst *node, char *type, void *obj, int x, int y, int z)
{
	if (node == NULL)
		node = init_t_lst(type, obj, x, y, z);
	else if (node->next != NULL)
	{
		add_t_lst(node->next, type, obj, x, y, z);
	}
	else
	{
		node->next = add_t_lst(node->next, type, obj, x, y, z);
	}
	return (node);
}
