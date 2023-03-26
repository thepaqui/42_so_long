/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:57:00 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/25 17:16:55 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

static int	main_loop(t_game *game)
{
	if (game->state == GAME_STOP)
		stop_sequence(game);
	else if (game->state == GAME_WIN)
	{
		if (!game->end_frame)
		{
			put_background_color_to_img(game, BLACK);
			game->end_color = 0x00FF0000;
			game->end_frame++;
		}
		ending_sequence(game);
	}
	else
	{
		update_player(game);
		update_map(game->map, game);
		if (game->map->totalcoins - game->map->nbcoins < MAXCOINS)
			update_coins(game->map);
		prepare_new_frame(game);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->image->img, 0, 0);
	return (0);
}

void	launch_game(t_game *game)
{
	t_img	*t;

	game->mlx = mlx_init();
	game->win_size.x = game->map->size.x * SPR_DIM;
	game->win_size.y = game->map->size.y * SPR_DIM;
	open_window(game);
	t = game->image;
	t->img = mlx_new_image(game->mlx, game->win_size.x, game->win_size.y);
	t->add = mlx_get_data_addr(t->img, &t->bpp, &t->line_len, &t->endian);
	game->state = GAME_STARTUP;
	game->player->pos.x = game->map->start.x * SPR_DIM;
	game->player->pos.y = game->map->start.y * SPR_DIM;
	mlx_loop_hook(game->mlx, main_loop, game);
	mlx_hook(game->win, ON_KEYDOWN, 0, handle_key_press, game);
	mlx_hook(game->win, ON_KEYUP, 0, handle_key_release, game);
	mlx_loop(game->mlx);
}
