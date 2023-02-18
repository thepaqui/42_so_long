/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:57:00 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/17 22:47:35 by thepaqui         ###   ########.fr       */
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
	//printf("Player speed\t%d\n", game->player->speed);
	printf("\n");
}

static void	print_moves(int moves)
{
	ft_putnbr_fd(moves, 1);
	if (moves > 1)
		ft_putstr_fd(" moves\n", 1);
	else
		ft_putstr_fd(" move\n", 1);
}

static int	main_loop(t_game *game)
{
	debug(game, 1); //-----------------------------------
	print_moves(game->moves);
	if (game->state == GAME_STOP)
		close_window(game, 0, NULL);
	else
	{
		update_player(game);
		update_map(game->map, game);
		update_coins(game->map);
		prepare_new_frame(game);
		mlx_put_image_to_window(MLX, WIN, IMGIMG, 0, 0);
	}
	return (0);
}

static void	get_window_camera_size(t_game *game)
{
	if (game->map->size.x <= 20)
		game->camera->size.x = game->map->size.x * SPR_DIM;
	else
	{
		game->scroll = 1;
		game->camera->size.x = SPR_DIM * 16;
	}
	if (game->map->size.y <= 18)
		game->camera->size.y = game->map->size.y * SPR_DIM;
	else
	{
		game->scroll = 1;
		game->camera->size.y = SPR_DIM * 14;
	}
}

void	launch_game(t_game *game)
{
	MLX = mlx_init();
	get_window_camera_size(game);
	open_window(game);
	IMGIMG = mlx_new_image(MLX, WINWID, WINHEI);
	IMGADD = mlx_get_data_addr(IMGIMG, &IMGBPP, &IMGLLEN, &IMGENDI);
	game->state = GAME_STARTUP;
	XPLAYER = game->map->start.x * SPR_DIM;
	YPLAYER = game->map->start.y * SPR_DIM;
	mlx_loop_hook(MLX, main_loop, game);
	mlx_hook(WIN, ON_KEYDOWN, 0, handle_key_press, game);
	mlx_hook(WIN, ON_KEYUP, 0, handle_key_release, game);
	mlx_loop(MLX);
}
