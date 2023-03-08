/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:37:13 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/08 21:24:44 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

static void	update_projectile_anim(t_player *player)
{
	if (player->pro_anim_speed)
		player->pro_anim_speed--;
	else if (player->pro_dir.x > 0)
	{
		if (player->pro->cur_spr == 7)
			player->pro->cur_spr = 0;
		else
			player->pro->cur_spr++;
		player->pro_anim_speed = PRO_ANIM_LEN;
	}
	else
	{
		if (player->pro->cur_spr == 0)
			player->pro->cur_spr = 7;
		else
			player->pro->cur_spr--;
		player->pro_anim_speed = PRO_ANIM_LEN;
	}
}

void	update_projectile(t_game *game, t_player *player, t_map *map)
{
	t_vector	approx_pro_pos;

	(void)map;
	if (!player->pro_here)
		return ;
	player->pro_pos.x += player->pro_dir.x;
	player->pro_pos.y += player->pro_dir.y;
	approx_pro_pos.x = nearbyint(player->pro_pos.x);
	approx_pro_pos.y = nearbyint(player->pro_pos.y);
	// hitbox (bounce / destroy / collect / kill)
	//printf("Projectile is at pos (%f,%f)\n", player->pro_pos.x, player->pro_pos.y); //---------------
	if (approx_pro_pos.x < 0 || approx_pro_pos.y < 0
		|| approx_pro_pos.x + SPR_DIM > game->win_size.x - 1
		|| approx_pro_pos.y + SPR_DIM > game->win_size.y - 1)
	{
		player->pro_here--;
		return ;
	}
	update_projectile_anim(player);
	put_t_xpm_to_img(player->pro, game, approx_pro_pos);
}

void	throw(t_game *game)
{
	if (game->player->pro_here >= PRO_LIMIT)
		return ;
	game->player->pro_pos.x = (double)game->player->pos.x;
	game->player->pro_pos.y = (double)game->player->pos.y;
	get_player_to_cursor_dir(game, game->player);
	game->player->pro->cur_spr = 0;
	game->player->pro_anim_speed = PRO_ANIM_LEN;
	game->player->pro_here++;
	game->player->pro_bounces = 0;
	game->player->state = PTHROWEND;
}
