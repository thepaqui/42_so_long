/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:57:00 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 15:58:10 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

static void	win(t_game *game)
{
	if (!game->end_frame)
	{
		player_anim_end_init(game, game->player);
		draw_all_canvas(game);
		game->end_color = 0x00FF0000;
		game->end_frame++;
	}
	ending_sequence(game);
}

static void	lose(t_game *game)
{
	if (!game->end_frame)
	{
		player_anim_death_init(game, game->player);
		put_background_color_to_img(game, GAME_OVER_BG);
		game->end_frame++;
	}
	game_over_sequence(game, game->player);
}

static void	play(t_game *game)
{
	update_player(game, game->player);
	if (game->nbenemies)
		update_enemies(game, game->enemies);
	update_cursor(game);
	update_map(game->map, game);
	if (game->map->totalcoins - game->map->nbcoins < MAXCOINS)
		update_coins(game->map);
	prepare_new_frame(game);
}

static int	main_loop(t_game *game)
{
	if (game->state == GAME_STOP)
		stop_sequence(game);
	else if (game->state == GAME_WIN)
		win(game);
	else if (game->state == GAME_LOSE)
		lose(game);
	else
		play(game);
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
	mlx_mouse_hook(game->win, handle_click, game);
	mlx_hook(game->win, ON_KEYDOWN, 0, handle_key_press, game);
	mlx_hook(game->win, ON_KEYUP, 0, handle_key_release, game);
	mlx_loop(game->mlx);
}
