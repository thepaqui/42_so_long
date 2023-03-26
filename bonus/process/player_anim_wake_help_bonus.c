/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_anim_wake_help_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:44:17 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 16:08:51 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

void	player_anim_wake_startup(t_player *p)
{
	if (p->anim_len < 0)
		p->anim_len = PA_WSU_LEN;
	if (!p->anim_len)
	{
		if (p->sprite->cur_spr != PA_WSU_E)
			p->sprite->cur_spr--;
		else
			p->sprite->cur_spr = PA_WLO_S;
	}
	if (p->sprite->cur_spr == PA_WLO_S)
	{
		p->anim_state = PAS_LOOK;
		p->anim_len = PA_WLO_LEN;
		p->anim_loops = 0;
	}
}

void	player_anim_wake_look(t_player *p)
{
	if (p->anim_len < 0)
	{
		if (p->sprite->cur_spr == PA_WLO_E || p->sprite->cur_spr == PA_WLO_S)
			p->anim_len = PA_WLO_CD + (rand() % 13);
		else
			p->anim_len = PA_WLO_LEN;
	}
	if (!p->anim_len)
	{
		if (p->anim_loops % 2 == 0)
			p->sprite->cur_spr++;
		else
			p->sprite->cur_spr--;
		if (p->sprite->cur_spr == PA_WLO_E || p->sprite->cur_spr == PA_WLO_S)
			p->anim_loops++;
	}
	if (p->anim_loops / 2 == PA_WLO_NB)
	{
		p->anim_state = PAS_SCRATCH;
		p->sprite->cur_spr = PA_WSC_S;
		p->anim_len = PA_WSC_LEN;
		p->anim_loops = 0;
	}
}

void	player_anim_wake_scratch(t_player *p)
{
	if (p->anim_len < 0)
		p->anim_len = PA_WSC_LEN;
	if (!p->anim_len)
	{
		if (p->sprite->cur_spr == 90)
		{
			p->sprite->cur_spr = 96;
			p->anim_loops++;
		}
		else if (p->sprite->cur_spr == 96 && p->anim_loops < PA_WSC_NB)
			p->sprite->cur_spr = 90;
		else
			p->sprite->cur_spr++;
	}
	if (p->sprite->cur_spr == PA_WSC_E)
	{
		p->pro_dir.y = INITIAL_JUMP_SPEED;
		p->pro_pos.y = p->pos.y;
		p->anim_state = PAS_JUMP;
		p->sprite->cur_spr = PA_WJU_S;
		p->anim_len = PA_WJU_LEN;
		p->anim_loops = 0;
	}
}

void	player_anim_wake_jump(t_game *g, t_player *p)
{
	if (p->anim_len < 0)
		p->anim_len = PA_WJU_LEN;
	if (!p->anim_len)
	{
		if (p->sprite->cur_spr == PA_WJU_S)
			p->sprite->cur_spr = 63;
		else if (p->sprite->cur_spr != PA_WJU_E)
			p->sprite->cur_spr++;
	}
	p->pos.x -= 2;
	if (p->pro_dir.y - GRAVITY > 0)
		p->pro_dir.y -= GRAVITY;
	p->pro_pos.y -= p->pro_dir.y;
	p->pos.y = nearbyint(p->pro_pos.y);
	if (p->sprite->cur_spr == PA_WJU_E
		&& p->pos.y < g->win_size.y / 2 - (3 * (SPR_DIM / 2)))
	{
		p->anim_state = PAS_FALL;
		p->pro_dir.y = 0;
	}
}

void	player_anim_wake_fall(t_game *g, t_player *p)
{
	p->pos.x -= 2;
	p->pro_dir.y -= GRAVITY;
	p->pro_pos.y -= p->pro_dir.y;
	p->pos.y = nearbyint(p->pro_pos.y);
	if (p->pos.y > g->win_size.y / 2)
		p->sprite->cur_spr = PA_WFA_S;
	if (p->pos.y > g->win_size.y)
		p->anim_state = PAS_END;
}
