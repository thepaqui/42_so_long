/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:31:14 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/24 16:41:58 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

static void	adjust_player_pos(t_player *player, t_vector win_size)
{
	if (player->pos.y < 0)
		player->pos.y = 0;
	if (player->pos.x < 0)
		player->pos.x = 0;
	if (player->pos.x > win_size.x - SPR_DIM - 1)
		player->pos.x = win_size.x - SPR_DIM - 1;
	if (player->pos.y > win_size.y - SPR_DIM - 1)
		player->pos.y = win_size.y - SPR_DIM - 1;
}

static void	update_player_pos(t_player *player, t_map *map)
{
	t_vector	test1;
	t_vector	test2;

	test1.x = player->pos.x + (SPR_DIM / 2);
	test1.y = player->pos.y + (SPR_DIM / 2) - player->speed;
	test2.x = player->pos.x + (SPR_DIM / 2);
	test2.y = player->pos.y + (SPR_DIM / 2) + player->speed;
	if (player->up && !touch_obj(test1, map, WALL, PLAYER_HITBOX))
		player->pos.y -= player->speed;
	else if (player->down && !touch_obj(test2, map, WALL, PLAYER_HITBOX))
		player->pos.y += player->speed;
	test1.x = player->pos.x + (SPR_DIM / 2) - player->speed;
	test1.y = player->pos.y + (SPR_DIM / 2);
	test2.x = player->pos.x + (SPR_DIM / 2) + player->speed;
	test2.y = player->pos.y + (SPR_DIM / 2);
	if (player->left && !touch_obj(test1, map, WALL, PLAYER_HITBOX))
		player->pos.x -= player->speed;
	else if (player->right && !touch_obj(test2, map, WALL, PLAYER_HITBOX))
		player->pos.x += player->speed;
}

static void	set_player_animations(t_player *player)
{
	if (player->state == PMOVE)
	{
		if (player->last_key == KEY_ARRUP)
			player->sprite->cur_spr = 1;
		if (player->last_key == KEY_ARRDO)
			player->sprite->cur_spr = 2;
		if (player->last_key == KEY_ARRLE)
			player->sprite->cur_spr = 3;
		if (player->last_key == KEY_ARRRI)
			player->sprite->cur_spr = 4;
	}
	else
		player->sprite->cur_spr = 0;
	if (player->coin_anim_len)
	{
		player->coin_anim_len--;
		player->sprite->cur_spr = 5;
	}
}

static void	set_player_speed(t_player *player)
{
	if ((player->up || player->down) && (player->left || player->right))
		player->speed = PLAYER_DIAG_SPEED;
	else
		player->speed = PLAYER_SPEED;
}

void	update_player(t_game *game)
{
	set_player_animations(game->player);
	set_player_speed(game->player);
	update_player_pos(game->player, game->map);
	adjust_player_pos(game->player, game->win_size);
}
