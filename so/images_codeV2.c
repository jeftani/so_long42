/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_codeV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:09:43 by ajeftani          #+#    #+#             */
/*   Updated: 2023/02/24 14:07:09 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_floor(t_var *var)
{
	int	m;

	var->relative_path = "design/floor.xpm";
	var->img = mlx_xpm_file_to_image(var->mlx, var->relative_path,
			&var->img_width, &var->img_height);
	if (var->img == NULL)
		mlx_protection();
	m = mlx_put_image_to_window(var->mlx, var->win, var->img, var->pos_y * 30,
			var->pos_x * 30);
	if (m == -1)
		mlx_protection();
}

void	put_images_player_up(int i, int j, void *mlx, void *win)
{
	int		m;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "design/player_up.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (img == NULL)
		mlx_protection();
	m = mlx_put_image_to_window(mlx, win, img, j * 30, i * 30);
	if (m == -1)
		mlx_protection();
}

void	put_images_player_down(int i, int j, void *mlx, void *win)
{
	int		m;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "design/player_down.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (img == NULL)
		mlx_protection();
	m = mlx_put_image_to_window(mlx, win, img, j * 30, i * 30);
	if (m == -1)
		mlx_protection();
}

void	put_images_player_left(int i, int j, void *mlx, void *win)
{
	int		m;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "design/player_left.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (img == NULL)
		mlx_protection();
	m = mlx_put_image_to_window(mlx, win, img, j * 30, i * 30);
	if (m == -1)
		mlx_protection();
}

void	put_images_player_right(int i, int j, void *mlx, void *win)
{
	int		m;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "design/player_right.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (img == NULL)
		mlx_protection();
	m = mlx_put_image_to_window(mlx, win, img, j * 30, i * 30);
	if (m == -1)
		mlx_protection();
}
