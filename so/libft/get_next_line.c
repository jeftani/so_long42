/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:13:45 by ajeftani          #+#    #+#             */
/*   Updated: 2023/02/23 15:38:00 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_read(int fd, char *ptr)
{
	ssize_t	a;
	char	*dst;

	if (!ptr)
		ptr = ft_strdup("");
	dst = (char *)malloc(BUFFER_SIZE + 1);
	if (!dst)
		return (NULL);
	a = 1;
	while (a != 0)
	{
		a = read(fd, dst, BUFFER_SIZE);
		if (a == -1)
		{
			free(ptr);
			free(dst);
			return (NULL);
		}
		dst[a] = '\0';
		ptr = ft_strjoin(ptr, dst);
	}
	free(dst);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*ptr;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	ptr = gnl_read(fd, ptr);
	if (!ptr)
		return (NULL);
	return (ptr);
}
