/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_anim_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:33:55 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/14 23:57:51 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

static void	player_anim_throw_help(t_player *player, int left, int right)
{
	if (player->anim_len <= 0)
		player->anim_len = PA_THROW_LEN;
	if (player->last_key == KEY_A)
	{
		if (player->anim_len > PA_THROW_LEN - 4)
			player->sprite->cur_spr = left;
		else if (player->anim_len > PA_THROW_LEN - 5)
			player->sprite->cur_spr = left + 1;
		else
			player->sprite->cur_spr = left + 2;
	}
	else if (player->last_key == KEY_D)
	{
		if (player->anim_len > PA_THROW_LEN - 4)
			player->sprite->cur_spr = right;
		else if (player->anim_len > PA_THROW_LEN - 5)
			player->sprite->cur_spr = right + 1;
		else
			player->sprite->cur_spr = right + 2;
	}
	player->anim_len--;
	if (!player->anim_len)
		player->state = PTHROWEND;
}

void	player_anim_throw(t_player *player)
{
	if (player->grounded)
		player_anim_throw_help(player, PA_THROW_GL, PA_THROW_GR);
	else
		player_anim_throw_help(player, PA_THROW_FL, PA_THROW_FR);
}

void	player_anim_move_help(t_player *p, int ls, int le, int rs, int re)
{
	if (p->last_key == KEY_A)
	{
		if (p->sprite->cur_spr < ls || p->sprite->cur_spr > le)
			p->sprite->cur_spr = ls;
		else if (!p->anim_len)
			p->sprite->cur_spr++;
		if (p->sprite->cur_spr > le)
			p->sprite->cur_spr = ls;
	}
	else if (p->last_key == KEY_D)
	{
		if (p->sprite->cur_spr < rs || p->sprite->cur_spr > re)
			p->sprite->cur_spr = rs;
		else if (!p->anim_len)
			p->sprite->cur_spr++;
		if (p->sprite->cur_spr > re)
			p->sprite->cur_spr = rs;
	}
	p->anim_len--;
}

void	player_anim_move(t_player *player)
{
	if (player->grounded && (player->state == PIDLE
		|| (player->down == 1 && !player->left && !player->right)))
	{
		player->anim_len = 0;
		if (player->last_key == KEY_A)
			player->sprite->cur_spr = PA_GIL;
		else if (player->last_key == KEY_D)
			player->sprite->cur_spr = PA_GIR;
	}
	else if (player->grounded)
	{
		if (player->anim_len < 0 || player->anim_len > PA_GROUND_LEN)
			player->anim_len = PA_GROUND_LEN;
		player_anim_move_help(player, PA_GL_S, PA_GL_E, PA_GR_S, PA_GR_E);
	}
	else
	{
		if (player->anim_len < 0 || player->anim_len > PA_FLY_LEN)
			player->anim_len = PA_FLY_LEN;
		player_anim_move_help(player, PA_FL_S, PA_FL_E, PA_FR_S, PA_FR_E);
	}
}
