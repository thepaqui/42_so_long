/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_anim_move_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:33:55 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 16:53:35 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

static void	player_anim_move_help(t_player *p, int s, int e)
{
	if (p->sprite->cur_spr < s || p->sprite->cur_spr > e)
		p->sprite->cur_spr = s;
	else if (!p->anim_len)
		p->sprite->cur_spr++;
	if (p->sprite->cur_spr > e)
		p->sprite->cur_spr = s;
}

void	player_anim_move_die(t_player *p)
{
	if (p->last_key == KEY_A)
		player_anim_move_help(p, PA_DIE_SL, PA_DIE_EL);
	else if (p->last_key == KEY_D)
		player_anim_move_help(p, PA_DIE_SR, PA_DIE_ER);
	p->anim_len--;
}

void	player_anim_move_ground(t_player *p)
{
	if (p->last_key == KEY_A)
		player_anim_move_help(p, PA_GL_S, PA_GL_E);
	else if (p->last_key == KEY_D)
		player_anim_move_help(p, PA_GR_S, PA_GR_E);
	p->anim_len--;
}

static void	player_anim_move_fly(t_player *p)
{
	if (p->last_key == KEY_A)
		player_anim_move_help(p, PA_FL_S, PA_FL_E);
	else if (p->last_key == KEY_D)
		player_anim_move_help(p, PA_FR_S, PA_FR_E);
	p->anim_len--;
}

void	player_anim_move(t_player *p, t_xpm *psp)
{
	if (p->grounded && (p->state == PIDLE
			|| (p->down == 1 && !p->left && !p->right)))
	{
		if (psp->cur_spr != PA_GIL_S && psp->cur_spr != PA_GIR_S
			&& psp->cur_spr != PA_GIL_E && psp->cur_spr != PA_GIR_E
			&& (p->anim_len < 0 || p->anim_len > PA_GI_LEN))
			p->anim_len = PA_GI_LEN;
		else if ((psp->cur_spr == PA_GIL_S || psp->cur_spr == PA_GIR_S
				|| psp->cur_spr == PA_GIL_E || psp->cur_spr == PA_GIR_E)
			&& (p->anim_len < 0 || p->anim_len > PA_GI_CD))
			p->anim_len = PA_GI_CD;
		player_anim_ground_idle(p);
	}
	else if (p->grounded)
	{
		if (p->anim_len < 0 || p->anim_len > PA_GROUND_LEN)
			p->anim_len = PA_GROUND_LEN;
		player_anim_move_ground(p);
	}
	else
	{
		if (p->anim_len < 0 || p->anim_len > PA_FLY_LEN)
			p->anim_len = PA_FLY_LEN;
		player_anim_move_fly(p);
	}
}
