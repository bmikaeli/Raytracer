/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:03:19 by tdemay            #+#    #+#             */
/*   Updated: 2013/11/19 16:03:20 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	ptr;
	int	j;

	i = 0;
	ptr = 0;
	j = 0;
	if (*s2 == '\0')
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		if (s2[j] == s1[i])
		{
			if (j == 0)
				ptr = i;
			j++;
		}
		else
			j = 0;
		i++;
		if (s2[j] == '\0')
			return ((char *)(s1 + ptr));
	}
	return (NULL);
}
