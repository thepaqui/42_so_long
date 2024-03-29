/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_pos_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:39:32 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 17:32:23 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

void	update_enemy_speed(t_enemy *enemy)
{
	if (enemy->type == E_DEAD || enemy->dir == NONE)
	{
		enemy->speed = 0;
		return ;
	}
	enemy->speed = 1;
	if (enemy->dir == TOP || enemy->dir == LEFT)
		enemy->speed = -1;
	if (enemy->turn)
		enemy->speed *= 1;
	else if (enemy->type == E_FLY_V)
		enemy->speed *= EFV_SPEED;
	else if (enemy->type == E_FLY_H)
		enemy->speed *= EFH_SPEED;
	else if (enemy->type == E_GROUND)
		enemy->speed *= EG_SPEED;
}

static void	update_enemy_v_pos(t_enemy *enemy, t_map *map, int tmpdir)
{
	t_vector	offpos;

	enemy->pos.y += enemy->speed;
	offpos.y = enemy->pos.y + SPR_DIM;
	offpos.x = enemy->pos.x;
	while ((enemy->speed < 0 && get_obj_from_pos(enemy->pos, map) == WALL)
		|| (enemy->speed > 0 && get_obj_from_pos(offpos, map) == WALL))
	{
		enemy->turn = 1;
		if (enemy->dir == tmpdir)
		{
			if (enemy->dir == TOP)
				enemy->dir = BOT;
			else if (enemy->dir == BOT)
				enemy->dir = TOP;
		}
		if (enemy->speed < 0)
			enemy->pos.y++;
		else
			enemy->pos.y--;
		offpos.y = enemy->pos.y + SPR_DIM;
	}
}

static void	update_enemy_h_pos(t_enemy *enemy, t_map *map, int tmpdir)
{
	t_vector	offpos;

	enemy->pos.x += enemy->speed;
	offpos.y = enemy->pos.y;
	offpos.x = enemy->pos.x + SPR_DIM;
	while ((enemy->speed < 0 && get_obj_from_pos(enemy->pos, map) == WALL)
		|| (enemy->speed > 0 && get_obj_from_pos(offpos, map) == WALL))
	{
		unclip_enemy(enemy, tmpdir);
		offpos.x = enemy->pos.x + SPR_DIM;
	}
}

static void	update_enemy_g_pos(t_enemy *enemy, t_map *map, int tmpdir)
{
	t_vector	offpos;
	t_vector	grpos;

	enemy->pos.x += enemy->speed;
	offpos.y = enemy->pos.y;
	offpos.x = enemy->pos.x + SPR_DIM;
	grpos.y = enemy->pos.y + SPR_DIM;
	grpos.x = enemy->pos.x + (SPR_DIM / 2);
	while ((enemy->speed < 0 && get_obj_from_pos(enemy->pos, map) == WALL)
		|| (enemy->speed > 0 && get_obj_from_pos(offpos, map) == WALL)
		|| (get_obj_from_pos(grpos, map) != WALL))
	{
		unclip_enemy(enemy, tmpdir);
		offpos.x = enemy->pos.x + SPR_DIM;
		grpos.x = enemy->pos.x + (SPR_DIM / 2);
	}
}

void	update_enemy_pos(t_enemy *enemy, t_map *map)
{
	int	tmpdir;

	tmpdir = enemy->dir;
	if (enemy->type == E_FLY_V)
		update_enemy_v_pos(enemy, map, tmpdir);
	else if (enemy->type == E_FLY_H)
		update_enemy_h_pos(enemy, map, tmpdir);
	else if (enemy->type == E_GROUND)
		update_enemy_g_pos(enemy, map, tmpdir);
}
