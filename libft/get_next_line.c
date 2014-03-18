/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 11:53:31 by tdemay            #+#    #+#             */
/*   Updated: 2013/12/06 12:32:54 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int		bufToStr(char buf[BUFF_SIZE], int *idx, char **tmp)
{
	int			i;
	char		*tmp2;

	i = 0;
	tmp2 = ft_strnew(BUFF_SIZE);
	while (tmp2 && *idx < BUFF_SIZE && buf[*idx] != '\n'
			&& buf[(*idx % BUFF_SIZE)] != EOF)
	{
		tmp2[i] = buf[*idx];
		*idx += 1;
		i++;
	}
	*tmp = ft_strjoin(*tmp, tmp2);
	if (buf[*idx] == '\n')
	{
		*idx = (*idx + 1) % BUFF_SIZE;
		return (1);
	}
	if (buf[(*idx % BUFF_SIZE)] == EOF)
	{
		*idx = (*idx + 1) % BUFF_SIZE;
		return (0);
	}
	*idx = (*idx) % BUFF_SIZE;
	return (-1);
}

int				get_next_line(int const fd, char **line)
{
	static char	buf[BUFF_SIZE];
	static int	idx = 0;
	int			ret;
	char		*tmp;

	ret = -1;
	tmp = ft_strnew(BUFF_SIZE);
	if (tmp && idx != 0 && BUFF_SIZE > 1)
	{
		ret = bufToStr(buf, &idx, &tmp);
	}
	while (tmp && ret < 0)
	{
		ft_bzero(buf, BUFF_SIZE);
		ret = read(fd, buf, BUFF_SIZE);
		if (ret > 0)
			ret = bufToStr(buf, &idx, &tmp);
		else if (ret == -1)
			return (-1);
	}
	*line = tmp;
	return (ret);
}
