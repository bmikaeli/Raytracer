/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 14:57:17 by tdemay            #+#    #+#             */
/*   Updated: 2014/01/29 14:57:17 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_H
# define CLASS_H

# include <stdlib.h>

/*
** \def		NEW(_CLASS_)
** \brief	Macro preprocesseur pour l'allocation memoire facile
** \author	tdemay
*/
# define NEW(_CLASS_)	((_CLASS_*)malloc(sizeof(_CLASS_)))

/*
** \def		DELETE(_OBJ_)
** \brief	Macro preprocesseur pour desallocation memoire facile
** \author	tdemay
*/
# define DELETE(_OBJ_)	free(_OBJ_)

#endif /* !CLASS_H */
