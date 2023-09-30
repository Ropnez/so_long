/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma <buryilma@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:13:28 by buryilma          #+#    #+#             */
/*   Updated: 2023/09/30 15:17:48 by buryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# define PIXEL 64

typedef struct s_game
{
	void			*mlx;
	void			*mlx_win;

	void			*dipper_sprite;
	void			*floor_sprite;
	void			*wall_sprite;
	void			*coin_sprite;
	void			*exit_sprite;

	int				player_x;
	int				player_y;

	unsigned int	moves;
	char			**map;

	int				exit;
	int				ply;
	int				coins;

	int				exit_is_possible;
}					*t_game;

void				load_sprite(t_game game);
void				start_game(char *map_name);

int					game_exit(t_game game);
int					key_down(int keycode, t_game game);

int					render(t_game game);

char				**map_constructor(int fd);
int					map_validation(t_game sl);
int					flood_fill(t_game game);

void				ft_freematrix(char **matrix);
char				**ft_matrixdup(char **matrix);
int					ft_matrixlen(char **matrix);

#endif