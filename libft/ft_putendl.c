/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:03:07 by tdemay            #+#    #+#             */
/*   Updated: 2013/11/19 16:03:08 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putendl(char const *str)
{
	register int	cnt;

	cnt = 0;
	cnt += write(1, str, ft_strlen(str));
	cnt += write(1, "\n", 1);
	return (cnt);
}
