/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:45:34 by ajeftani          #+#    #+#             */
/*   Updated: 2023/02/27 04:54:42 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(char **splited, t_var *var)
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
				var->pos_x = i;
				var->pos_y = j;
				return ;
			}
		}
		i++;
	}
	return ;
}

void	move_up(t_var *var)
{
	if (var->splited[var->pos_x - 1][var->pos_y] == SPACE ||
		var->splited[var->pos_x - 1][var->pos_y] == PLAYER)
	{
		image_floor(var);
		put_images_player_up(--var->pos_x, var->pos_y, var->mlx, var->win);
		print_moves(var->moves++, var);
	}
	else if (var->splited[var->pos_x - 1][var->pos_y] == COLLECTIBLE)
	{
		image_floor(var);
		var->img = mlx_xpm_file_to_image(var->mlx, var->relative_path,
				&var->img_width, &var->img_height);
		ft_continuous(var, 'U');
	}
	else if (var->splited[var->pos_x - 1][var->pos_y] == ENEMY)
		gamestatus('L');
	else if ((var->coins == 0 && var->splited[var->pos_x
				- 1][var->pos_y] == LEAVING))
		gamestatus('G');
	put_image_direction(1, var);
	if (var->coins == 0)
		put_door_open(var->door_i, var->door_j, var->mlx, var->win);
}

void	move_down(t_var *var)
{
	if (var->splited[var->pos_x + 1][var->pos_y] == SPACE ||
		var->splited[var->pos_x + 1][var->pos_y] == PLAYER)
	{
		image_floor(var);
		put_images_player_down(++var->pos_x, var->pos_y, var->mlx, var->win);
		print_moves(var->moves++, var);
	}
	else if (var->splited[var->pos_x + 1][var->pos_y] == COLLECTIBLE)
	{
		image_floor(var);
		var->img = mlx_xpm_file_to_image(var->mlx, var->relative_path,
				&var->img_width, &var->img_height);
		ft_continuous(var, 'D');
	}
	else if (var->splited[var->pos_x + 1][var->pos_y] == ENEMY)
		gamestatus('L');
	else if ((var->coins == 0 && var->splited[var->pos_x
				+ 1][var->pos_y] == LEAVING))
		gamestatus('G');
	put_image_direction(2, var);
	if (var->coins == 0)
		put_door_open(var->door_i, var->door_j, var->mlx, var->win);
}

void	move_right(t_var *var)
{
	if (var->splited[var->pos_x][var->pos_y + 1] == SPACE ||
		var->splited[var->pos_x][var->pos_y + 1] == PLAYER)
	{
		image_floor(var);
		put_images_player_right(var->pos_x, ++var->pos_y, var->mlx, var->win);
		print_moves(var->moves++, var);
	}
	else if (var->splited[var->pos_x][var->pos_y + 1] == COLLECTIBLE)
	{
		image_floor(var);
		var->img = mlx_xpm_file_to_image(var->mlx, var->relative_path,
				&var->img_width, &var->img_height);
		ft_continous1(var, 'R');
	}
	else if (var->splited[var->pos_x][var->pos_y + 1] == ENEMY)
		gamestatus('L');
	else if ((var->coins == 0 && var->splited[var->pos_x][var->pos_y
			+ 1] == LEAVING))
		gamestatus('G');
	put_image_direction(3, var);
	if (var->coins == 0)
		put_door_open(var->door_i, var->door_j, var->mlx, var->win);
}

void	move_left(t_var *var)
{
	if (var->splited[var->pos_x][var->pos_y - 1] == SPACE ||
		var->splited[var->pos_x][var->pos_y - 1] == PLAYER)
	{
		image_floor(var);
		put_images_player_left(var->pos_x, --var->pos_y, var->mlx, var->win);
		print_moves(var->moves++, var);
	}
	else if (var->splited[var->pos_x][var->pos_y - 1] == COLLECTIBLE)
	{
		image_floor(var);
		var->img = mlx_xpm_file_to_image(var->mlx, var->relative_path,
				&var->img_width, &var->img_height);
		ft_continous1(var, 'L');
	}
	else if (var->splited[var->pos_x][var->pos_y - 1] == ENEMY)
		gamestatus('L');
	else if ((var->coins == 0 && var->splited[var->pos_x][var->pos_y
			- 1] == LEAVING))
		gamestatus('G');
	put_image_direction(4, var);
	if (var->coins == 0)
		put_door_open(var->door_i, var->door_j, var->mlx, var->win);
}
