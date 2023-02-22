/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 13:37:30 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/22 17:14:41 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

static int	print_move_count(t_game *game, int moves, int *last)
{
	t_vector	pos;
	t_vector	size;

	size.x = ft_strlen(MOV_PREFIX) + 2;
	if (moves >= 100)
		size.x = ft_strlen(MOV_PREFIX) + MOV_MAX_DIGITS;
	if (game->map->size.x < size.x)
		size.x = game->map->size.x;
	if (game->player->pos.y < SPR_DIM * 2 || moves != *last)
	{
		size.y = 1;
		pos.y = 0;
		pos.x = 0;
		draw_bg_part(game, game->map, pos, size);
		if (game->map->size.x > ft_strlen(MOV_PREFIX) + size.x)
		{
			put_str_to_img(MOV_PREFIX, pos, game, RED);
			pos.x = ft_strlen(MOV_PREFIX) * SPR_DIM;
		}
		put_nbr_to_img(moves, pos, game, BLUE);
		*last = moves;
	}
	return (size.x);
}

static void	print_coin_count(t_game *game, int movsize, int coins, int *last)
{
	t_vector	pos;
	t_vector	size;

	//printf("Map width = %d\n", game->map->size.x); //------------
	//printf("Move counter width = %d\n", movsize); //------------
	//printf("Collected coins = %d\n", coins); //------------
	if (game->map->size.x > movsize + 3
		&& (game->player->pos.y < SPR_DIM * 2 || coins != *last))
	{
		size.x = 2;
		if (coins > 9)
			size.x = 3;
		if (coins > 99)
			size.x = 4;
		size.y = 1;
		pos.y = 0;
		pos.x = SPR_DIM * (game->map->size.x - size.x);
		draw_bg_part(game, game->map, pos, size);
		put_nbr_to_img(coins, pos, game, 0x00FFD700);
		pos.x += SPR_DIM * (size.x - 1);
		put_str_to_img("$", pos, game, 0x00FFD700);
		*last = coins;
	}
}

void	prepare_new_frame(t_game *game)
{
	int	movsize;

	draw_map(game);
	draw_coins(game);
	movsize = print_move_count(game, game->moves, &game->last_moves);
	print_coin_count(game, movsize, game->map->nbcoins, &game->map->last);
	put_t_xpm_to_img(game->player->sprite, game, game->player->pos);
}

void	refresh_player_area(t_game *game)
{
	t_vector	pos;
	t_vector	size;

	pos.x = game->player->pos.x - SPR_DIM;
	size.x = 3;
	pos.y = game->player->pos.y - SPR_DIM;
	size.y = 3;
	draw_bg_part(game, game->map, pos, size);
}
