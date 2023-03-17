/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_anim_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:33:55 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/17 19:18:06 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

static void	player_anim_throw_help(t_player *player, int left, int right)
{
	if (player->anim_len <= 0 || player->anim_len > PA_THROW_LEN)
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

void	player_anim_ground_idle(t_player *p, int ls, int le, int rs, int re)
{
	if (p->last_key == KEY_A)
	{
		if (p->sprite->cur_spr < ls || p->sprite->cur_spr > le)
		{
			p->sprite->cur_spr = ls;
			p->anim_len = PA_GI_CD;
		}
		else if (!p->anim_len && !p->anim_state)
			p->sprite->cur_spr++;
		else if (!p->anim_len && p->anim_state)
			p->sprite->cur_spr--;
		if (p->sprite->cur_spr == le)
			p->anim_state = 1;
		else if (p->sprite->cur_spr == ls)
			p->anim_state = 0;
	}
	else if (p->last_key == KEY_D)
	{
		if (p->sprite->cur_spr < rs || p->sprite->cur_spr > re)
		{
			p->sprite->cur_spr = rs;
			p->anim_len = PA_GI_CD;
		}
		else if (!p->anim_len && !p->anim_state)
			p->sprite->cur_spr++;
		else if (!p->anim_len && p->anim_state)
			p->sprite->cur_spr--;
		if (p->sprite->cur_spr == re)
			p->anim_state = 1;
		else if (p->sprite->cur_spr == rs)
			p->anim_state = 0;
	}
	p->anim_len--;
}

void	player_anim_move(t_player *player)
{
	if (player->grounded && (player->state == PIDLE
		|| (player->down == 1 && !player->left && !player->right)))
	{
		if (player->sprite->cur_spr != PA_GIL_S && player->sprite->cur_spr != PA_GIR_S
			&& player->sprite->cur_spr != PA_GIL_E && player->sprite->cur_spr != PA_GIR_E
			&& (player->anim_len < 0 || player->anim_len > PA_GI_LEN))
			player->anim_len = PA_GI_LEN;
		else if ((player->sprite->cur_spr == PA_GIL_S || player->sprite->cur_spr == PA_GIR_S
				|| player->sprite->cur_spr == PA_GIL_E || player->sprite->cur_spr == PA_GIR_E)
			&& (player->anim_len < 0 || player->anim_len > PA_GI_CD))
			player->anim_len = PA_GI_CD;
		player_anim_ground_idle(player, PA_GIL_S, PA_GIL_E, PA_GIR_S, PA_GIR_E);
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
