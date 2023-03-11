/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile_collisions_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:56:54 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/11 15:27:07 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

void	bounce(t_game *game, t_vector pos)
{
	int			lr;
	int			tb;
	t_vector	rpos;

	rpos.x = pos.x + (SPR_DIM / 2);
	rpos.y = pos.y + (SPR_DIM / 2);
	lr = touch_obj_lr(rpos, game->map, WALL, PRO_HITBOX);
	tb = touch_obj_tb(rpos, game->map, WALL, PRO_HITBOX);
	if ((lr == LEFT && game->player->pro_dir.x < 0)
		|| (lr == RIGHT && game->player->pro_dir.x >= 0))
	{
		game->player->pro_dir.x *= -1;
		game->player->pro_bounces++;
	}
	if ((tb == TOP && game->player->pro_dir.y < 0)
		|| (tb == BOT && game->player->pro_dir.y >= 0))
	{
		game->player->pro_dir.y *= -1;
		game->player->pro_bounces++;
	}
}

void	pro_collect_coin(t_map *map, t_vector pos, int coin)
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
			diff.y = (PRO_HITBOX / 2) * -1;
		else if (coin == BOT_LEFT || coin == BOT_RIGHT)
			diff.y = (PRO_HITBOX / 2);
		if (coin == TOP_LEFT || coin == BOT_LEFT)
			diff.x = (PRO_HITBOX / 2) * -1;
		else if (coin == TOP_RIGHT || coin == BOT_RIGHT)
			diff.x = (PRO_HITBOX / 2);
	}
	map_pos.x = (pos.x + diff.x) / SPR_DIM;
	map_pos.y = (pos.y + diff.y) / SPR_DIM;
	map->map[map_pos.y][map_pos.x] = EMPTY;
	map->nbcoins++;
}
