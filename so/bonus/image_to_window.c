/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:03:59 by ajeftani          #+#    #+#             */
/*   Updated: 2023/02/26 18:59:33 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_to_window(char **splited, t_var *var, int i, int j)
{
	if (splited[i][j] == WALL)
		put_images(i, j, var->mlx, var->win);
	else if (splited[i][j] == COLLECTIBLE)
		put_images1(i, j, var->mlx, var->win);
	else if (splited[i][j] == PLAYER)
		put_images2(i, j, var->mlx, var->win);
	else if (splited[i][j] == LEAVING)
		put_images3(i, j, var->mlx, var->win);
}

void	exit_position(char **splited, t_var *var)
{
	int	i;
	int	j;

	i = 0;
	while (splited[i])
	{
		j = 0;
		while (splited[i][j])
		{
			if (splited[i][j] != LEAVING)
				j++;
			else if (splited[i][j] == LEAVING)
			{
				var->door_i = i;
				var->door_j = j;
				return ;
			}
		}
		i++;
	}
	return ;
}

void	put_door_open(int i, int j, void *mlx, void *win)
{
	int		m;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "design/door_open.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (img == NULL)
		mlx_protection();
	m = mlx_put_image_to_window(mlx, win, img, j * 30, i * 30);
	if (m == -1)
		mlx_protection();
}

void	put_image_direction(int r, t_var *var)
{
	if (r == 1)
	{
		image_floor(var);
		put_images_player_up(var->pos_x, var->pos_y, var->mlx, var->win);
	}
	else if (r == 2)
	{
		image_floor(var);
		put_images_player_down(var->pos_x, var->pos_y, var->mlx, var->win);
	}
	else if (r == 3)
	{
		image_floor(var);
		put_images_player_right(var->pos_x, var->pos_y, var->mlx, var->win);
	}
	else if (r == 4)
	{
		image_floor(var);
		put_images_player_left(var->pos_x, var->pos_y, var->mlx, var->win);
	}
}
