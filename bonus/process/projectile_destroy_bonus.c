/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile_destroy_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:37:13 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 15:52:44 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

static void	anim_destroy_projectile(t_player *p)
{
	if (p->pro_break_anim > PRO_BREAK_ANIM_LEN * 3)
		p->pro->cur_spr = 8;
	else if (p->pro_break_anim > PRO_BREAK_ANIM_LEN * 2)
		p->pro->cur_spr = 9;
	else if (p->pro_break_anim > PRO_BREAK_ANIM_LEN)
		p->pro->cur_spr = 10;
	else
		p->pro->cur_spr = 11;
	p->pro_break_anim--;
	if (!p->pro_break_anim)
		p->pro_break_anim--;
	if (p->pro_rethrow > 1)
		p->pro_rethrow--;
}

static void	anim_end_destroy_projectile(t_game *g, t_player *p)
{
	p->pro_pos.x = -1;
	p->pro_pos.y = -1;
	p->pro_here = 0;
	p->pro_bounces = 0;
	p->pro_break_anim = 0;
	if (p->pro_rethrow)
		throw(g);
}

void	destroy_projectile(t_game *game, t_vector pos)
{
	t_vector	rpos;

	rpos.x = pos.x;
	rpos.y = pos.y;
	if (rpos.x < 0)
		rpos.x = 0;
	if (rpos.y < 0)
		rpos.y = 0;
	if (rpos.x + (SPR_DIM * 2) > game->win_size.x - 1)
		rpos.x = game->win_size.x - 1 - (SPR_DIM * 2);
	if (rpos.y + (SPR_DIM * 2) > game->win_size.y - 1)
		rpos.y = game->win_size.y - 1 - (SPR_DIM * 2);
	refresh_area(game, rpos, 2, 2);
	if (!game->player->pro_break_anim)
	{
		game->player->pro_dir.x = 0;
		game->player->pro_dir.y = 0;
		game->player->pro_break_anim = PRO_BREAK_ANIM_LEN * 4;
	}
	if (game->player->pro_break_anim > 0)
		anim_destroy_projectile(game->player);
	if (game->player->pro_break_anim < 0 || game->player->pro_rethrow == 1)
		anim_end_destroy_projectile(game, game->player);
}
