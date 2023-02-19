/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:33:28 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/19 15:11:18 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void	draw_coins(t_game *game)
{
	t_vector	pos;
	int	i;

	i = -1;
	while (++i < game->map->totalcoins)
	{
		pos.x = game->map->coin_pos[i].x * SPR_DIM;
		pos.y = game->map->coin_pos[i].y * SPR_DIM;
		if (game->map->map[pos.y / SPR_DIM][pos.x / SPR_DIM] == 'C')
		{
			game->map->sprite->cur_spr = 0;
			put_t_xpm_to_img(game->map->sprite, game, pos);
			put_t_xpm_to_img(game->map->coin_spr, game, pos);
		}
	}
}

void	update_coins(t_map *map)
{
		if (!map->coin_speed)
		{
			if (map->coin_spr->cur_spr == 7)
				map->coin_spr->cur_spr = 0;
			else
				map->coin_spr->cur_spr++;
			map->coin_speed = COIN_SPEED;
		}
		else
			map->coin_speed--;
}

void	collect_coin(t_map *map, t_game *game, t_vector pos, int coin)
{
	t_vector	map_pos;
	t_vector	diff;

	if (coin == CENTER)
	{
		diff.x = 0;
		diff.y = 0;
	}
	else
	{
		if (coin == TOP_LEFT || coin == TOP_RIGHT)
			diff.y = (PLAYER_HITBOX / 2) * -1;
		else if (coin == BOT_LEFT || coin == BOT_RIGHT)
			diff.y = (PLAYER_HITBOX / 2);
		if (coin == TOP_LEFT || coin == BOT_LEFT)
			diff.x = (PLAYER_HITBOX / 2) * -1;
		else if (coin == TOP_RIGHT || coin == BOT_RIGHT)
			diff.x = (PLAYER_HITBOX / 2);
	}
	map_pos.x = (pos.x + diff.x) / SPR_DIM;
	map_pos.y = (pos.y + diff.y) / SPR_DIM;
	map->map[map_pos.y][map_pos.x] = EMPTY;
	map->nbcoins--;
	game->player->coin_anim_len = PLAYER_COIN_ANIM_LEN;
}
