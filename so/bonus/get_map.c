/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:09:26 by ajeftani          #+#    #+#             */
/*   Updated: 2023/02/27 02:36:54 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_anim(t_var *var)
{
	static int	i;

	{
		if (i < 40)
		{
			i = ft_anim_cond(var, i, 'C');
		}
		if (i >= 40)
		{
			i = ft_anim_cond(var, i, 'A');
		}
		if (i >= 80)
		{
			i = ft_anim_cond(var, i, 'B');
		}
		if (i >= 100)
		{
			image_floor1(var);
			i = 0;
		}
		put_images_to_window(var, var->img, 'N');
		return (0);
	}
}

int	ft_destroy(void)
{
	exit(0);
}

int	ft_close(int keycode, t_var *win)
{
	if (keycode == 53)
	{
		win->destroy = mlx_destroy_window(win->mlx, win->win);
		if (win->destroy == -1)
			mlx_protection();
		exit(0);
	}
	else if (keycode == 126)
	{
		move_up(win);
	}
	else if (keycode == 125)
	{
		move_down(win);
	}
	else if (keycode == 124)
	{
		move_right(win);
	}
	else if (keycode == 123)
	{
		move_left(win);
	}
	return (0);
}

void	get_background(char **splited, t_var *var)
{
	int	i;
	int	j;
	int	imagefun;

	i = 0;
	var->relative_path = "design/floor.xpm";
	while (splited[i])
	{
		j = 0;
		while (splited[i][j])
		{
			var->img = mlx_xpm_file_to_image(var->mlx, var->relative_path,
					&var->img_width, &var->img_height);
			if (var->img == NULL)
				mlx_protection();
			imagefun = mlx_put_image_to_window(var->mlx, var->win, var->img, j
					* 30, i * 30);
			if (imagefun == -1)
				mlx_protection();
			image_to_window(splited, var, i, j);
			j++;
		}
		i++;
	}
}

void	get_map(char **splited, t_var *var)
{
	int	m;
	int	n;

	var->splited = splited;
	var->mlx = mlx_init();
	if (var->mlx == NULL)
		mlx_protection();
	var->win = mlx_new_window(var->mlx, ft_strlen(splited[0]) * 30,
			height_row_c(splited) * 30, "ajeftani");
	if (var->win == NULL)
		mlx_protection();
	get_background(splited, var);
	mlx_loop_hook(var->mlx, ft_anim, var);
	m = mlx_hook(var->win, 2, 0, ft_close, var);
	if (m == -1)
		mlx_protection();
	n = mlx_hook(var->win, 17, 0, ft_destroy, var);
	if (n == -1)
		mlx_protection();
	mlx_loop(var->mlx);
}
