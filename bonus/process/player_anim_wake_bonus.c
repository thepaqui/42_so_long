/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_anim_wake_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:44:17 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 16:09:24 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

static void	refresh_bg_wake_color(t_game *g, t_vector opos, int wid, int hei)
{
	t_vector	pos;

	pos.y = opos.y - 1;
	while (++pos.y < opos.y + (SPR_DIM * hei))
	{
		pos.x = opos.x - 1;
		while (++pos.x < opos.x + (SPR_DIM * wid))
			put_pixel_to_img(g, pos, WAKING_BG);
	}
}

void	player_anim_wake(t_game *g, t_player *p)
{
	p->pos.y -= SPR_DIM;
	refresh_bg_wake_color(g, p->pos, 1, 2);
	p->pos.y += SPR_DIM;
	if (p->anim_state == PAS_STARTUP)
		player_anim_wake_startup(p);
	else if (p->anim_state == PAS_LOOK)
		player_anim_wake_look(p);
	else if (p->anim_state == PAS_SCRATCH)
		player_anim_wake_scratch(p);
	else if (p->anim_state == PAS_JUMP)
		player_anim_wake_jump(g, p);
	else if (p->anim_state == PAS_FALL)
		player_anim_wake_fall(g, p);
	else if (p->anim_state == PAS_END)
		g->state = GAME_STOP;
	p->anim_len--;
	put_t_xpm_to_img(p->sprite, g, p->pos);
	if (p->anim_state == PAS_JUMP || p->sprite->cur_spr == PA_WJU_E)
	{
		p->sprite->cur_spr -= 7;
		p->pos.y -= SPR_DIM;
		put_t_xpm_to_img(p->sprite, g, p->pos);
		p->sprite->cur_spr += 7;
		p->pos.y += SPR_DIM;
	}
}
