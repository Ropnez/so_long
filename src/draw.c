/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma <buryilma@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:07:10 by buryilma          #+#    #+#             */
/*   Updated: 2023/09/30 14:03:03 by buryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

static void	render_map(t_game game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->wall_sprite, x * PIXEL, y * PIXEL);
			else if (game->map[y][x] == '0' || game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->floor_sprite, x * PIXEL, y * PIXEL);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->coin_sprite, x * PIXEL, y * PIXEL);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->exit_sprite, x * PIXEL, y * PIXEL);
			x++;
		}
		y++;
	}
}

int	render(t_game game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	render_map(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->dipper_sprite, game->player_x * PIXEL, game->player_y * PIXEL);
	return (0);
}
