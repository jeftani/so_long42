/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_v1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:29:01 by ajeftani          #+#    #+#             */
/*   Updated: 2023/02/27 17:30:37 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_double(char **splited, t_var *var)
{
	var->n = 0;
	var->i = 0;
	var->coins = 0;
	var->p = 0;
	var->e = 0;
	while (splited[var->i])
	{
		var->j = 0;
		while (splited[var->i][var->j])
		{
			if (splited[var->i][var->j] == PLAYER)
				var->p++;
			else if (splited[var->i][var->j] == LEAVING)
				var->e++;
			else if (splited[var->i][var->j] == COLLECTIBLE)
				var->coins++;
			else if (splited[var->i][var->j] == ENEMY)
				var->n++;
			var->j++;
		}
		var->i++;
	}
	if ((var->p != 1 || var->e != 1 || var->coins < 1 || var->n < 1))
		error(1);
}

void	check_element(char **splited, t_var *var)
{
	int	i;
	int	j;

	i = 0;
	while (splited[i])
	{
		j = 0;
		while (splited[i][j])
		{
			if (splited[i][j] == PLAYER || splited[i][j] == WALL
				|| splited[i][j] == COLLECTIBLE || splited[i][j] == LEAVING
				|| splited[i][j] == SPACE || splited[i][j] == ENEMY)
				j++;
			else
			{
				write(1, "error element not defined\n", 26);
				exit(1);
			}
		}
		i++;
	}
	check_double(splited, var);
}

void	check_empty_lines(char *splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		if ((splited[i] == '\n' && splited[i + 1] == '\n')
			|| splited[0] == '\n')
		{
			write(1, "Error empty line\n", 17);
			exit(1);
		}
		i++;
	}
	if (splited[i - 1] == '\n')
	{
		write(1, "Error empty line\n", 17);
		exit(1);
	}
}

void	check_map_name(char *name)
{
	int		i;
	int		len;
	char	**ptr;

	i = 0;
	ptr = ft_split(name, '.');
	while (ptr[i])
	{
		i++;
	}
	i--;
	len = ft_strncmp(&ptr[i][0], "ber", 4);
	if (len != 0)
	{
		write(1, ".ber doesnt exist", 17);
		exit(1);
	}
	ft_free(ptr);
}

void	enemy(char **splited, int y, int x, char c)
{
	if ((splited[y][x] == WALL || splited[y][x] == '*') || splited[y][x] == 'N')
		return ;
	splited[y][x] = '*';
	floodfill(splited, y + 1, x, c);
	floodfill(splited, y - 1, x, c);
	floodfill(splited, y, x + 1, c);
	floodfill(splited, y, x - 1, c);
}
