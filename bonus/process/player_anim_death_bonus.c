/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_anim_death_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:28:01 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 16:54:06 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

void	player_anim_death(t_game *game, t_player *player)
{
	t_vector	tmp;

	refresh_bg_color(game, player->pos, 1, 1);
	player->pro_pos.x += player->pro_dir.x;
	player->pro_pos.y += player->pro_dir.y;
	player->pos.x = nearbyint(player->pro_pos.x);
	player->pos.y = nearbyint(player->pro_pos.y);
	tmp.x = game->curs_pos.x - player->pos.x;
	tmp.y = game->curs_pos.y - player->pos.y;
	if (tmp.x > -3 && tmp.x < 3)
		player->pos.x = game->curs_pos.x;
	if (tmp.y > -3 && tmp.y < 3)
		player->pos.y = game->curs_pos.y;
	if (player->anim_len < 0)
		player->anim_len = PA_DIE_LEN;
	player_anim_move_die(player);
	put_t_xpm_to_img(player->sprite, game, player->pos);
	if (player->pos.x == game->curs_pos.x && player->pos.y == game->curs_pos.y)
	{
		refresh_bg_color(game, player->pos, 1, 1);
		player->anim_len = PA_SPIN_LEN;
		player->state = PSPIN;
		player->sprite->cur_spr = PA_SPIN_S;
	}
}

void	player_anim_death_init(t_game *game, t_player *player)
{
	player->state = PDEATH;
	player->anim_len = PA_GROUND_LEN;
	game->curs_pos.x = game->win_size.x / 2 - (SPR_DIM / 2);
	game->curs_pos.y = game->win_size.y / 2 + SPR_DIM + (SPR_DIM / 2);
	if (game->curs_pos.y + SPR_DIM > game->win_size.y)
		game->curs_pos.y = game->win_size.y - SPR_DIM;
	get_player_to_cursor_dir(game, player);
	player->pro_dir.x /= PRO_SPEED;
	player->pro_dir.y /= PRO_SPEED;
	player->pro_dir.x *= PLAYER_DIAG_SPEED;
	player->pro_dir.y *= PLAYER_DIAG_SPEED;
	player->pro_pos.x = game->player->pos.x;
	player->pro_pos.y = game->player->pos.y;
	if (player->pro_dir.x > 0)
	{
		player->last_key = KEY_D;
		player->sprite->cur_spr = PA_DIE_SR;
	}
	else
	{
		player->last_key = KEY_A;
		player->sprite->cur_spr = PA_DIE_SL;
	}
}

static void	player_anim_spin_help(t_player *p, int s, int e)
{
	if (!p->anim_len)
	{
		if (p->sprite->cur_spr == PA_SPIN_LS)
			p->anim_loops++;
		if (p->sprite->cur_spr == e)
			p->sprite->cur_spr = s;
		else
			p->sprite->cur_spr++;
	}
	p->anim_len--;
}

void	player_anim_spin(t_game *g, t_player *p)
{
	if (p->anim_loops == PA_SPIN_NB)
	{
		p->pos.y -= SPR_DIM;
		refresh_bg_color(g, p->pos, 1, 2);
		p->pos.y += SPR_DIM;
		p->anim_len = PA_FAINT_T_LEN;
		p->state = PFAINT;
		p->sprite->cur_spr = PA_FAINT_T;
		return ;
	}
	p->pos.y -= SPR_DIM;
	refresh_bg_color(g, p->pos, 1, 2);
	p->pos.y += SPR_DIM;
	if (p->anim_len < 0)
		p->anim_len = PA_SPIN_LEN + (p->anim_loops * 2);
	player_anim_spin_help(p, PA_SPIN_S, PA_SPIN_E);
	put_t_xpm_to_img(p->sprite, g, p->pos);
	p->sprite->cur_spr -= 7;
	p->pos.y -= SPR_DIM;
	put_t_xpm_to_img(p->sprite, g, p->pos);
	p->sprite->cur_spr += 7;
	p->pos.y += SPR_DIM;
}

void	player_anim_faint(t_game *g, t_player *p)
{
	t_xpm	*sp;

	refresh_bg_color(g, p->pos, 1, 1);
	sp = p->sprite;
	if (p->anim_len < 0)
	{
		if (sp->cur_spr >= PA_FAINT_T && sp->cur_spr < PA_FAINT_S)
			p->anim_len = PA_FAINT_T_LEN;
		else
			p->anim_len = PA_FAINT_LEN;
	}
	if (!p->anim_len)
	{
		if (sp->cur_spr >= PA_FAINT_T && sp->cur_spr < PA_FAINT_S)
			sp->cur_spr++;
		else
		{
			if (sp->cur_spr == PA_FAINT_E)
				sp->cur_spr = PA_FAINT_S;
			else
				sp->cur_spr++;
		}
	}
	p->anim_len--;
	put_t_xpm_to_img(sp, g, p->pos);
}
