/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_anim_idle_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:26:38 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 16:33:00 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

static void	player_anim_ground_idle_help(t_player *p, int s, int e)
{
	if (p->sprite->cur_spr < s || p->sprite->cur_spr > e)
	{
		p->sprite->cur_spr = s;
		p->anim_len = PA_GI_CD;
	}
	else if (!p->anim_len && !p->anim_state)
		p->sprite->cur_spr++;
	else if (!p->anim_len && p->anim_state)
		p->sprite->cur_spr--;
	if (p->sprite->cur_spr == e)
		p->anim_state = 1;
	else if (p->sprite->cur_spr == s)
		p->anim_state = 0;
}

void	player_anim_ground_idle(t_player *p)
{
	if (p->last_key == KEY_A)
		player_anim_ground_idle_help(p, PA_GIL_S, PA_GIL_E);
	else if (p->last_key == KEY_D)
		player_anim_ground_idle_help(p, PA_GIR_S, PA_GIR_E);
	p->anim_len--;
}
