/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:00:43 by ajeftani          #+#    #+#             */
/*   Updated: 2022/11/01 20:03:37 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *string, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	size_t	slen;

	i = 0;
	if (!string)
		return (NULL);
	if (start > ft_strlen(string))
		start = ft_strlen(string);
	slen = ft_strlen(string + start);
	if (len > slen)
		sub = malloc(slen + 1);
	else
		sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	while (string[start + i] && (i < len))
	{
		sub[i] = string[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
