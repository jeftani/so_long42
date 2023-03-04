/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:52:04 by ajeftani          #+#    #+#             */
/*   Updated: 2023/02/27 17:29:17 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c, int i)
{
	int	size;
	int	trick;

	size = 0;
	trick = 0;
	if (str[i] != c)
		trick = 1;
	while (str[i])
	{
		if (str[i] == c)
			trick = 1;
		else if (str[i] != c && trick == 1)
		{
			size++;
			trick = 0;
		}
		i++;
	}
	return (size);
}

void	*ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

static int	count_size(const char *str, char c, int i)
{
	int	wordsize;

	wordsize = 0;
	while (str[i] && str[i] != c)
	{
		wordsize++;
		i++;
	}
	return (wordsize);
}

static char	**ft_moresplit(char **ptr, int size, char const *s, char c)
{
	int	wordcount;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < size)
	{
		while (s[i] == c)
			i++;
		wordcount = count_size(s, c, i);
		ptr[j] = ft_substr(s, i, wordcount);
		if (!ptr[j])
			return (ft_free(ptr));
		i = i + wordcount;
		j++;
	}
	ptr[j] = 0;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		size;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = -1;
	size = count_words(s, c, i);
	ptr = (char **)malloc((size + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	return (ft_moresplit(ptr, size, s, c));
}
