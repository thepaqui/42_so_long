/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:31:14 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 16:23:49 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

static void	adjust_player_pos(t_player *player, t_vector win_size, t_map *map)
{
	t_vector	tpos;

	if (player->pos.y < 0)
		player->pos.y = 0;
	if (player->pos.x < 0)
		player->pos.x = 0;
	if (player->pos.x > win_size.x - SPR_DIM - 1)
		player->pos.x = win_size.x - SPR_DIM - 1;
	if (player->pos.y > win_size.y - SPR_DIM - 1)
		player->pos.y = win_size.y - SPR_DIM - 1;
	tpos.x = player->pos.x;
	tpos.y = player->pos.y + SPR_DIM;
	snap_to_grid(&tpos);
	tpos.x = player->pos.x + SPR_DIM / 2;
	if (get_obj_from_pos(tpos, map) == WALL)
	{
		player->pos.y = tpos.y - SPR_DIM;
		player->grounded = 1;
	}
	else
		player->grounded = 0;
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
	if (player->state == PTHROW)
		player_anim_throw(player);
	if (player->state == PTHROWEND)
	{
		if (player->up || player->down || player->left || player->right)
			player->state = PMOVE;
		else
			player->state = PIDLE;
	}
	if (player->state == PMOVE || player->state == PIDLE)
		player_anim_move(player, player->sprite);
}

static void	set_player_speed(t_player *player)
{
	if ((player->up || player->down) && (player->left || player->right))
		player->speed = PLAYER_DIAG_SPEED;
	else
		player->speed = PLAYER_SPEED;
}

void	update_player(t_game *game, t_player *player)
{
	if (player->state == PMOVE && !player->up && !player->down
		&& !player->left && !player->right)
		player->state = PIDLE;
	if (player->state == PIDLE)
		refresh_area(game, player->pos, 2, 2);
	else
		refresh_area(game, player->pos, 3, 3);
	set_player_animations(player);
	set_player_speed(player);
	update_player_pos(player, game->map);
	adjust_player_pos(player, game->win_size, game->map);
}
