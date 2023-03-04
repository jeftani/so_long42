/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:35:47 by ajeftani          #+#    #+#             */
/*   Updated: 2022/11/03 16:00:31 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (find[0] == '\0')
		return ((char *)src);
	if (!src && !len)
		return (NULL);
	while (src[i] && i < len)
	{
		j = 0;
		if (src[i] == find[j])
		{
			while (src[i + j] == find[j] && (i + j) < len)
			{
				j++;
				if (find[j] == '\0')
					return ((char *)&src[i]);
			}
		}
		i++;
	}
	return (0);
}
