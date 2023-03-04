/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:39:38 by ajeftani          #+#    #+#             */
/*   Updated: 2023/03/02 16:19:51 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_list
{
	char	*line;
	char	**map;
	char	**map2;
	char	**map3;
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
	int		n;
	int		destroy;
	char	*string;
	int		anim_y;
	int		anim_x;
}			t_var;

# define SPACE '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define LEAVING 'E'
# define PLAYER 'P'
# define ENEMY 'N'

void	check_element(char **splited, t_var *var);
void	check_empty_lines(char *splited);
void	check_map_name(char *name);
void	*ft_free(char **ptr);
void	check_path(char **splited, char **map2, char **map3);
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
void	print_moves(int i, t_var *var);
void	error(int n);
void	protect(int n);
void	mlx_protection(void);
void	image_floor(t_var *var);
int		height_row_c(char **splited);
void	put_images_player_up(int i, int j, void *mlx, void *win);
void	put_images_player_down(int i, int j, void *mlx, void *win);
void	put_images_player_left(int i, int j, void *mlx, void *win);
void	put_images_player_right(int i, int j, void *mlx, void *win);
void	exit_position(char **splited, t_var *var);
void	put_door_open(int i, int j, void *mlx, void *win);
void	put_image_direction(int r, t_var *var);
void	enemy(char **splited, int y, int x, char c);
void	put_images5(int i, int j, void *mlx, void *win);
void	ft_animation_player(int i, int j, void *mlx, void *win);
void	put_images_to_window(t_var *game, void *img_data, char c);
void	ft_continuous(t_var *var, char c);
void	ft_continous1(t_var *var, char c);
int		ft_anim_cond(t_var *var, int i, char c);
void	image_floor1(t_var *var);
void	gamestatus(int c);
void	mlx_protection2(void *var);
#endif
