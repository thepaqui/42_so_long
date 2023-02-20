/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:57:00 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/20 17:38:48 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include <stdio.h> //--------------------------------------------------

static void	debug(t_game *game, int silent)
{
	if (silent)
		return ;
	printf("Player position\t(%d,%d)\n", game->player->pos.x, game->player->pos.y);
	printf("Player is on cell (%d,%d)\n", game->map->start.x, game->map->start.y);
	printf("\n");
}

static void	print_moves(t_game *game, int moves, int *last)
{
	t_vector	pos;

	if (game->player->pos.y < SPR_DIM || moves != *last)
	{
		pos.x = SPR_DIM * 0;
		pos.y = SPR_DIM * 0;
		put_str_to_img("MOVES: ", pos, game, RED);
		pos.x = SPR_DIM * 7;
		put_nbr_to_img(moves, pos, game, BLUE);
		*last = moves;
	}
}

static int	main_loop(t_game *game)
{
	debug(game, 1); //-----------------------------------
	if (game->state == GAME_STOP)
		close_window(game, 0, NULL);
	else
	{
		update_player(game);
		update_map(game->map, game);
		update_coins(game->map);
		prepare_new_frame(game);
		print_moves(game, game->moves, &game->last_moves);
		mlx_put_image_to_window(game->mlx, game->win, game->image->img, 0, 0);
	}
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
