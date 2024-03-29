/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 13:37:30 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 16:58:20 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

void	prepare_new_frame(t_game *game)
{
	int	*movsize;
	int	coins;

	draw_map(game);
	draw_coins(game);
	movsize = &game->movesize;
	coins = game->map->nbcoins;
	*movsize = print_move_count(game, game->moves, &game->last_moves, coins);
	print_coin_count(game, *movsize, coins, &game->map->last);
	game->last_movesize = *movsize;
	if (game->nbenemies)
		draw_enemies(game, game->enemies);
	draw_cursor(game);
	put_t_xpm_to_img(game->player->sprite, game, game->player->pos);
}

void	snap_to_grid(t_vector *pos)
{
	pos->x = (pos->x / SPR_DIM) * SPR_DIM;
	pos->y = (pos->y / SPR_DIM) * SPR_DIM;
	if (pos->x < 0)
		pos->x = 0;
	if (pos->y < 0)
		pos->y = 0;
}

void	refresh_area(t_game *game, t_vector pos, int width, int height)
{
	t_vector	rpos;
	t_vector	offset;
	t_vector	size;

	if (width % 2 == 0)
		offset.x = width / 2 - 1;
	else
		offset.x = width / 2;
	if (height % 2 == 0)
		offset.y = height / 2 - 1;
	else
		offset.y = height / 2;
	rpos.x = pos.x - (SPR_DIM * offset.x);
	rpos.y = pos.y - (SPR_DIM * offset.y);
	snap_to_grid(&rpos);
	size.x = width;
	size.y = height;
	refresh_scenery(game, game->map, rpos, size);
	draw_bg_part(game, game->map, rpos, size);
}
