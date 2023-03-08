/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:45:30 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/08 18:45:57 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

int	print_move_count(t_game *game, int moves, int *last)
{
	t_vector	pos;
	t_vector	size;

	size.x = ft_strlen(MOV_PREFIX) + 2;
	if (moves >= 100)
		size.x = ft_strlen(MOV_PREFIX) + MOV_MAX_DIGITS;
	if (size.x > game->map->size.x)
		size.x = game->map->size.x;
	if (moves != *last || game->player->pos.y < SPR_DIM * 2
		|| game->last_cpos.y < SPR_DIM * 2
		|| game->player->pro_pos.y < SPR_DIM * 2)
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

void	print_coin_count(t_game *game, int movsize, int coins, int *last)
{
	t_vector	pos;
	t_vector	size;

	if (game->map->size.x > movsize + 3
		&& (coins != *last || game->player->pos.y < SPR_DIM * 2
			|| game->last_cpos.y < SPR_DIM * 2
			|| game->player->pro_pos.y < SPR_DIM * 2))
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
