/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:15:19 by ajeftani          #+#    #+#             */
/*   Updated: 2022/11/04 02:45:27 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*string;
	size_t	i;

	string = (char *)s;
	i = ft_strlen(s);
	while (i > 0 && string[i] != (char)c)
		i--;
	if (string[i] == (char)c)
		return (string + i);
	else
		return (NULL);
}
