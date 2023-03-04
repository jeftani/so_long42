/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:39:38 by ajeftani          #+#    #+#             */
/*   Updated: 2023/02/27 17:30:07 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_list
{
	char	**map;
	char	**map2;
	int		fd;
	void	*mlx;
	void	*win;
	int		pos_j;
	int		pos_i;
	int		pos_x;
	int		pos_y;
	int		coins;
	int		moves;
	char	**splited;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	int		door_i;
	int		door_j;
	int		i;
	int		j;
	int		p;
	int		e;
	int		destroy;
}			t_var;

# define SPACE '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define LEAVING 'E'
# define PLAYER 'P'

void	check_element(char **splited, t_var *var);
void	check_empty_lines(char *splited);
void	check_map_name(char *name);
void	*ft_free(char **ptr);
void	check_path(char **splited, char **map2);
void	floodfill(char **splited, int y, int x, char c);
void	get_map(char **splited, t_var *var);
void	put_images2(int i, int j, void *mlx, void *win);
void	move_up(t_var *var);
void	player_position(char **splited, t_var *var);
void	move_down(t_var *var);
void	move_right(t_var *var);
void	move_left(t_var *var);
void	image_to_window(char **splited, t_var *var, int i, int j);
void	put_images(int i, int j, void *mlx, void *win);
void	put_images1(int i, int j, void *mlx, void *win);
void	put_images2(int i, int j, void *mlx, void *win);
void	put_images3(int i, int j, void *mlx, void *win);
void	put_images4(int i, int j, void *mlx, void *win);
void	put_images_coll(int i, int j, void *mlx, void *win);
void	print_moves(int i);
void	error(int n);
void	protect(int n);
void	gamestatus(int c);
void	mlx_protection(void);
void	image_floor(t_var *var);
void	put_images_player_up(int i, int j, void *mlx, void *win);
void	put_images_player_down(int i, int j, void *mlx, void *win);
void	put_images_player_left(int i, int j, void *mlx, void *win);
void	put_images_player_right(int i, int j, void *mlx, void *win);
void	exit_position(char **splited, t_var *var);
void	put_image_direction(int r, t_var *var);
void	put_door_open(int i, int j, void *mlx, void *win);
#endif
