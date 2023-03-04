/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:10:10 by ajeftani          #+#    #+#             */
/*   Updated: 2022/11/04 19:58:50 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*source1;
	unsigned char	*source2;
	size_t			i;

	if (n == 0)
		return (0);
	source1 = (unsigned char *)s1;
	source2 = (unsigned char *)s2;
	i = 0;
	while (source1[i] == source2[i] && i < n - 1)
		i++;
	if (source1[i] != source2[i])
		return (source1[i] - source2[i]);
	return (source1[i] - source2[i]);
}
