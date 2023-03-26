/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:37:13 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 15:47:13 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

static void	update_projectile_anim(t_player *player)
{
	if (player->pro_break_anim != 0)
		return ;
	if (player->pro_anim_speed)
		player->pro_anim_speed--;
	else if (player->pro_dir.x > 0)
	{
		if (player->pro->cur_spr == 7)
			player->pro->cur_spr = 0;
		else
			player->pro->cur_spr++;
		player->pro_anim_speed = PRO_ANIM_LEN;
	}
	else
	{
		if (player->pro->cur_spr == 0)
			player->pro->cur_spr = 7;
		else
			player->pro->cur_spr--;
		player->pro_anim_speed = PRO_ANIM_LEN;
	}
}

static void	pro_collect_coin_help(t_vector snap_pos, t_map *map)
{
	t_vector	center_pos;
	int			coin;

	center_pos.x = snap_pos.x + (SPR_DIM / 2);
	center_pos.y = snap_pos.y + (SPR_DIM / 2);
	coin = touch_obj(center_pos, map, COIN, PRO_HITBOX);
	if (coin != NONE)
		pro_collect_coin(map, center_pos, coin);
}

void	update_projectile(t_game *game, t_player *player, t_map *map)
{
	t_vector	snap_pos;

	snap_pos.x = nearbyint(player->pro_pos.x);
	snap_pos.y = nearbyint(player->pro_pos.y);
	refresh_area(game, snap_pos, 2, 2);
	player->pro_pos.x += player->pro_dir.x;
	player->pro_pos.y += player->pro_dir.y;
	if (!PRO_SPECTRAL && !player->pro_break_anim)
		bounce(game, snap_pos);
	if (player->pro_break_anim > 0
		|| (PRO_BOUNCE_BREAK && player->pro_bounces >= PRO_BOUNCE_LIMIT))
		destroy_projectile(game, snap_pos);
	if (PRO_COLLECT && !player->pro_break_anim)
		pro_collect_coin_help(snap_pos, map);
	if (snap_pos.x < 0 || snap_pos.x + SPR_DIM > game->win_size.x - 1
		|| snap_pos.y < 0 || snap_pos.y + SPR_DIM > game->win_size.y - 1)
		destroy_projectile(game, snap_pos);
	update_projectile_anim(player);
}

void	throw(t_game *game)
{
	if (game->player->pro_here >= PRO_LIMIT)
		return ;
	game->player->pro_rethrow = 0;
	game->player->pro_pos.x = (double)game->player->pos.x;
	game->player->pro_pos.y = (double)game->player->pos.y;
	get_player_to_cursor_dir(game, game->player);
	if (game->player->pro_dir.x < 0)
		game->player->last_key = KEY_A;
	else if (game->player->pro_dir.x > 0)
		game->player->last_key = KEY_D;
	game->player->pro->cur_spr = 0;
	game->player->pro_anim_speed = PRO_ANIM_LEN;
	game->player->pro_here++;
	game->player->pro_bounces = 0;
	game->player->state = PTHROW;
}
