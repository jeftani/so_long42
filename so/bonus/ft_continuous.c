/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_continuous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:06:31 by ajeftani          #+#    #+#             */
/*   Updated: 2023/03/02 17:23:05 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_continous1(t_var *var, char c)
{
	if (c == 'R')
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img, ++var->pos_y * 30,
			var->pos_x * 30);
		put_images_player_right(var->pos_x, var->pos_y, var->mlx, var->win);
		var->coins--;
		var->splited[var->pos_x][var->pos_y] = SPACE;
		print_moves(var->moves++, var);
	}
	else if (c == 'L')
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img, --var->pos_y * 30,
			var->pos_x * 30);
		put_images_player_left(var->pos_x, var->pos_y, var->mlx, var->win);
		var->coins--;
		var->splited[var->pos_x][var->pos_y] = SPACE;
		print_moves(var->moves++, var);
	}
}

void	ft_continuous(t_var *var, char c)
{
	if (c == 'U')
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img, var->pos_y * 30,
			--var->pos_x * 30);
		put_images_player_up(var->pos_x, var->pos_y, var->mlx, var->win);
		var->coins--;
		var->splited[var->pos_x][var->pos_y] = SPACE;
		print_moves(var->moves++, var);
	}
	else if (c == 'D')
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img, var->pos_y * 30,
			++var->pos_x * 30);
		put_images_player_down(var->pos_x, var->pos_y, var->mlx, var->win);
		var->coins--;
		var->splited[var->pos_x][var->pos_y] = SPACE;
		print_moves(var->moves++, var);
	}
}

int	ft_anim_cond(t_var *var, int i, char c)
{
	char	*filename;
	int		img_width;
	int		img_height;

	if (c == 'C')
		filename = "design/resize1.xpm";
	else if (c == 'A')
		filename = "design/resize2.xpm";
	else if (c == 'B')
		filename = "design/resize3.xpm";
	else
		return (0);
	var->img = mlx_xpm_file_to_image(var->mlx, filename, &img_width,
			&img_height);
	if (var->img == NULL)
		mlx_protection();
	i = i + 1;
	return (i);
}

int	height_row_c(char **splited)
{
	int	i;
	int	j;

	i = 0;
	while (splited[i])
	{
		j = 0;
		while (splited[i][j])
		{
			j++;
		}
		i++;
	}
	return (i);
}
