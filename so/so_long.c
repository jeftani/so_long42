/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:45:19 by ajeftani          #+#    #+#             */
/*   Updated: 2023/02/28 21:08:57 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	middle_walls(char **splited)
{
	int	i;
	int	len;

	i = 1;
	while (splited[i])
	{
		len = ft_strlen(splited[i]);
		if (splited[i][0] == '1' && splited[i][len - 1] == '1')
		{
			i++;
		}
		else
		{
			write(1, "error middle walls\n", 19);
			exit(1);
		}
	}
}

void	check_walls(char **splited)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	{
		while (splited[len])
			len++;
		len--;
		while (splited[0][j] && splited[len][j])
		{
			if (splited[0][j] == '1' && splited[len][j] == '1')
			{
				j++;
			}
			else
			{
				write(1, "error in walls \n", 16);
				exit(1);
			}
		}
	}
	middle_walls(splited);
}

void	check_len(char **splited)
{
	int	i;

	i = 1;
	while (splited[i])
	{
		if (ft_strlen(splited[0]) == ft_strlen(splited[i]))
			i++;
		else
		{
			write(1, "error line len\n", 15);
			exit(1);
		}
	}
}

int	main(int ac, char **argv)
{
	t_var	var;
	char	*line;
	char	**splited;

	if (ac == 2)
	{
		var.moves = 1;
		check_map_name(argv[1]);
		var.fd = open(argv[1], O_RDONLY);
		protect(var.fd);
		line = get_next_line(var.fd);
		check_empty_lines(line);
		splited = ft_split(line, '\n');
		check_element(splited, &var);
		check_len(splited);
		check_walls(splited);
		var.map = ft_split(line, '\n');
		var.map2 = ft_split(line, '\n');
		check_path(var.map, var.map2);
		player_position(splited, &var);
		exit_position(splited, &var);
		get_map(splited, &var);
	}
	else
		write(1, "less or more argument\n", 22);
}
