/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:25:18 by ajeftani          #+#    #+#             */
/*   Updated: 2023/02/24 13:57:08 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images(int i, int j, void *mlx, void *win)
{
	int		m;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "design/walls.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (img == NULL)
		mlx_protection();
	m = mlx_put_image_to_window(mlx, win, img, j * 30, i * 30);
	if (m == -1)
		mlx_protection();
}

void	put_images1(int i, int j, void *mlx, void *win)
{
	int		m;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "design/coins.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (img == NULL)
		mlx_protection();
	m = mlx_put_image_to_window(mlx, win, img, j * 30, i * 30);
	if (m == -1)
		mlx_protection();
}

void	put_images2(int i, int j, void *mlx, void *win)
{
	int		m;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "design/player.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (img == NULL)
		mlx_protection();
	m = mlx_put_image_to_window(mlx, win, img, j * 30, i * 30);
	if (m == -1)
		mlx_protection();
}

void	put_images3(int i, int j, void *mlx, void *win)
{
	int		m;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "design/door.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (img == NULL)
		mlx_protection();
	m = mlx_put_image_to_window(mlx, win, img, j * 30, i * 30);
	if (m == -1)
		mlx_protection();
}

void	put_images4(int i, int j, void *mlx, void *win)
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
