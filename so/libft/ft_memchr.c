/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:48:14 by ajeftani          #+#    #+#             */
/*   Updated: 2022/11/04 17:57:31 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*source;
	size_t			i;

	if (n == 0)
		return (NULL);
	source = (unsigned char *)s;
	i = 0;
	while (n > i)
	{
		if (source[i] == (unsigned char)c)
			return (source + i);
		i++;
	}
	return (NULL);
}
