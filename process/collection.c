/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:33:28 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/17 21:45:51 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void	draw_coins(t_game *game)
{
	t_vector	pos;

	pos.y = 0;
	while (pos.y < game->camera->size.y)
	{
		pos.x = 0;
		while (pos.x < game->camera->size.x)
		{
			if (game->map->map[pos.y / SPR_DIM][pos.x / SPR_DIM] == 'C'
				&& game->map->coin_speed == COIN_SPEED)
			{
				game->map->sprite->cur_spr = 0;
				put_t_xpm_to_img(game->map->sprite, game, pos);
				//printf("Drawing coin at (%i,%i)\n", pos.x, pos.y); //-------------
				put_t_xpm_to_img(game->map->coin_spr, game, pos);
			}
			pos.x += SPR_DIM;
		}
		pos.y += SPR_DIM;
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