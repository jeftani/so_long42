/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:57:00 by ajeftani          #+#    #+#             */
/*   Updated: 2023/02/27 17:57:47 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	stuck(char **splited)
{
	int	i;
	int	j;

	i = 0;
	while (splited[i])
	{
		j = 0;
		while (splited[i][j])
		{
			if (splited[i][j] == PLAYER || splited[i][j] == COLLECTIBLE)
			{
				write(1, "error Element stuck\n", 20);
				exit(1);
			}
			else
				j++;
		}
		i++;
	}
}

void	stuck1(char **splited)
{
	int	i;
	int	j;

	i = 0;
	while (splited[i])
	{
		j = 0;
		while (splited[i][j])
		{
			if (splited[i][j] == PLAYER || splited[i][j] == LEAVING)
			{
				write(1, "error Element stuck\n", 20);
				exit(1);
			}
			else
				j++;
		}
		i++;
	}
}

void	stuck2(char **splited)
{
	int	i;
	int	j;

	i = 0;
	while (splited[i])
	{
		j = 0;
		while (splited[i][j])
		{
			if (splited[i][j] == PLAYER || splited[i][j] == LEAVING)
			{
				write(1, "error Element stuck\n", 20);
				exit(1);
			}
			else
				j++;
		}
		i++;
	}
}

void	check_path(char **splited, char **map2, char **map3)
{
	int	i;
	int	j;

	i = 0;
	while (splited[i])
	{
		j = 0;
		while (splited[i][j])
		{
			if (splited[i][j] != PLAYER)
				j++;
			else if (splited[i][j] == PLAYER)
			{
				floodfill(splited, i, j, 'E');
				stuck(splited);
				floodfill(map2, i, j, '1');
				stuck1(map2);
				floodfill(map3, i, j, 'N');
				stuck2(map3);
				return ;
			}
		}
		i++;
	}
}

void	floodfill(char **splited, int y, int x, char c)
{
	if (c == 'E')
	{
		if ((splited[y][x] == WALL || splited[y][x] == '*')
			|| splited[y][x] == c)
			return ;
		splited[y][x] = '*';
		floodfill(splited, y + 1, x, c);
		floodfill(splited, y - 1, x, c);
		floodfill(splited, y, x + 1, c);
		floodfill(splited, y, x - 1, c);
	}
	else if (c == '1')
	{
		if ((splited[y][x] == WALL || splited[y][x] == '*'))
			return ;
		splited[y][x] = '*';
		floodfill(splited, y + 1, x, '1');
		floodfill(splited, y - 1, x, '1');
		floodfill(splited, y, x + 1, '1');
		floodfill(splited, y, x - 1, '1');
	}
	else if (c == 'N')
	{
		enemy(splited, y, x, c);
	}
}
