/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:03:07 by tdemay            #+#    #+#             */
/*   Updated: 2013/11/19 16:03:08 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putendl_fd(char const *str, int fd)
{
	register int	cnt;

	cnt = 0;
	cnt += write(fd, str, ft_strlen(str));
	cnt += write(fd, "\n", 1);
	return (0);
}
