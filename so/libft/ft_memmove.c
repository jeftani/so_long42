/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 00:53:24 by ajeftani          #+#    #+#             */
/*   Updated: 2022/11/04 00:02:17 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if (source == NULL && dest == NULL)
		return (0);
	i = 0;
	if (dest < source)
	{
		while (len > i)
		{
			dest[i] = source[i];
			i++;
		}
	}
	else
		while (len--)
			dest[len] = source[len];
	return (dest);
}
