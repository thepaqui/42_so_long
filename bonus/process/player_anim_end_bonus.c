/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_anim_end_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:26:31 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 17:43:17 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

int	player_anim_end(t_game *game, t_player *player)
{
	t_vector	tmp;

	draw_canvas_part(game, player->pos, 2, 2);
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
		player->anim_len = PA_GROUND_LEN;
	player_anim_move_ground(player);
	put_t_xpm_to_img(player->sprite, game, player->pos);
	if (player->pos.x == game->curs_pos.x && player->pos.y == game->curs_pos.y)
	{
		draw_canvas_part(game, player->pos, 2, 2);
		player->state = PCHEER;
		player->sprite->cur_spr = PA_CHEER_S;
	}
	return (0);
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
	draw_canvas_part(game, player->pos, 2, 3);
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
