/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_countmove.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:28:51 by ajeftani          #+#    #+#             */
/*   Updated: 2023/03/02 15:27:28 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(int i, t_var *var)
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	int		m;

	(void)i;
	relative_path = "design/walls_for_count.xpm";
	img = mlx_xpm_file_to_image(var->mlx, relative_path, &img_width,
			&img_height);
	if (img == NULL)
		mlx_protection();
	m = mlx_put_image_to_window(var->mlx, var->win, img, 2 * 30, 0);
	if (m == -1)
		mlx_protection();
	mlx_string_put(var->mlx, var->win, 0, 10, 0xFFB100, "moves : ");
	var->string = ft_itoa(var->moves);
	mlx_string_put(var->mlx, var->win, 70, 10, 0xFFB100, var->string);
	free(var->string);
}

void	error(int n)
{
	if (n == 1)
	{
		write(1, "less or too many element\n", 26);
		exit(1);
	}
	if (n == 2)
	{
		write(1, "error no existing file", 22);
		exit(1);
	}
}

void	protect(int n)
{
	if (n < 0)
		error(2);
}

void	mlx_protection(void)
{
	write(1, "mlx error\n", 10);
	exit(1);
}

void	image_floor1(t_var *var)
{
	int	m;

	var->relative_path = "design/floor.xpm";
	var->img = mlx_xpm_file_to_image(var->mlx, var->relative_path,
			&var->img_width, &var->img_height);
	if (var->img == NULL)
		mlx_protection();
	m = mlx_put_image_to_window(var->mlx, var->win, var->img, var->anim_y * 30,
			var->anim_x * 30);
	if (m == -1)
		mlx_protection();
}
