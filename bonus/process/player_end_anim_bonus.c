/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_end_anim_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:26:31 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/15 05:59:57 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

void	refresh_bg_color(t_game *game, int color, t_vector opos, t_vector size)
{
	t_vector	pos;

	pos.y = opos.y - 1;
	while (++pos.y < opos.y + (SPR_DIM * size.y))
	{
		pos.x = opos.x - 1;
		while (++pos.x < opos.x + (SPR_DIM * size.x))
			put_pixel_to_img(game, pos, color);
	}
}

void	player_anim_end(t_game *game, t_player *player)
{
	t_vector	tmp;

	//player->pos.y -= SPR_DIM;
	draw_canvas_part(game, player->pos, 2, 2);
	//player->pos.y += SPR_DIM;
	player->pro_pos.x += player->pro_dir.x;
	player->pro_pos.y += player->pro_dir.y;
	player->pos.x = nearbyint(player->pro_pos.x);
	player->pos.y = nearbyint(player->pro_pos.y);
	if (player->anim_len < 0)
		player->anim_len = PA_GROUND_LEN;
	player_anim_move_help(player, PA_GL_S, PA_GL_E, PA_GR_S, PA_GR_E);
	put_t_xpm_to_img(player->sprite, game, player->pos);
	tmp.x = game->curs_pos.x - player->pos.x;
	tmp.y = game->curs_pos.y - player->pos.y;
	if (tmp.x > -3 && tmp.x < 3)
		player->pos.x = game->curs_pos.x;
	if (tmp.y > -3 && tmp.y < 3)
		player->pos.y = game->curs_pos.y;
	if (player->pos.x == game->curs_pos.x && player->pos.y == game->curs_pos.y)
	{
		player->state = PCHEER;
		player->sprite->cur_spr = PA_CHEER_S;
	}
}

void	player_anim_end_init(t_game *game, t_player *player)
{
	player->state = PWIN;
	player->sprite->cur_spr = 0;
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
		player->last_key = KEY_D;
	else
		player->last_key = KEY_A;
}

static void	player_anim_cheer_help(t_player *p, int s, int e)
{
	if (!p->anim_len)
	{
		if (p->sprite->cur_spr == s)
			p->sprite->cur_spr = 63;
		else if (p->sprite->cur_spr == 69)
			p->sprite->cur_spr = e;
		else if (p->sprite->cur_spr == e)
			p->sprite->cur_spr = s;
		else
			p->sprite->cur_spr++;
	}
	p->anim_len--;
}

void	player_anim_cheer(t_game *game, t_player *player)
{
	player->pos.y -= SPR_DIM;
	draw_canvas_part(game, player->pos, 1, 2);
	player->pos.y += SPR_DIM;
	if (player->anim_len < 0)
		player->anim_len = PA_CHEER_LEN;
	player_anim_cheer_help(player, PA_CHEER_S, PA_CHEER_E);
	put_t_xpm_to_img(player->sprite, game, player->pos);
	player->sprite->cur_spr -= 7;
	player->pos.y -= SPR_DIM;
	put_t_xpm_to_img(player->sprite, game, player->pos);
	player->sprite->cur_spr += 7;
	player->pos.y += SPR_DIM;
}
