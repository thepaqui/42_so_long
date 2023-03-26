/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_anim_throw_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:37:30 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 16:38:08 by thepaqui         ###   ########.fr       */
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
