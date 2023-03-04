/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_windowV1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:02:58 by ajeftani          #+#    #+#             */
/*   Updated: 2023/03/02 17:30:05 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images_to_window(t_var *game, void *img_data, char c)
{
	int	i;
	int	j;
	int	m;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (c == 'N' && game->splited[i][j] == ENEMY)
			{
				m = mlx_put_image_to_window(game->mlx, game->win, img_data, 30
						* j, i * 28);
				if (m == -1)
					mlx_protection();
				game->anim_x = j;
				game->anim_y = i;
			}
			j++;
		}
		i++;
	}
}
