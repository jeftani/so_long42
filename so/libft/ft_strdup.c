/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:03:45 by ajeftani          #+#    #+#             */
/*   Updated: 2022/11/03 15:59:10 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	index;
	char	*copy;

	index = 0;
	i = ft_strlen(s1);
	copy = (char *)malloc(i + 1 * sizeof(char));
	if (!copy)
		return (NULL);
	while (s1[index])
	{
		copy[index] = s1[index];
		index++;
	}
	copy[i] = '\0';
	return (copy);
}
