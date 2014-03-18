/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 15:55:05 by tdemay            #+#    #+#             */
/*   Updated: 2014/01/29 15:55:05 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# define D_CREATE(funct)	f_create_##funct

# include "class.h"

typedef struct	s_lst
{
	char			*type;
	void			*obj;
	int				x;
	int				y;
	int				z;
	struct s_lst	*next;
}				t_lst;

t_lst	*init_t_lst(char *type, void *obj, int x, int y, int z);
t_lst	*add_t_lst(t_lst *node, char *type, void *obj, int x, int y, int z);

#endif /* !LIST_H */
