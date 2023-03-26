/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:45:10 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 16:41:42 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

void	get_cursor_pos(t_game *game)
{
	game->last_cpos.x = game->curs_pos.x;
	game->last_cpos.y = game->curs_pos.y;
	mlx_mouse_get_pos(game->win, &game->curs_pos.x, &game->curs_pos.y);
	game->curs_pos.x -= SPR_DIM / 2;
	game->curs_pos.y -= SPR_DIM / 2;
	if (game->curs_pos.x < SPR_DIM / 2)
		game->curs_pos.x = SPR_DIM / 2;
	else if (game->curs_pos.x > game->win_size.x - 1 - SPR_DIM - SPR_DIM / 2)
		game->curs_pos.x = game->win_size.x - 1 - SPR_DIM - SPR_DIM / 2;
	if (game->curs_pos.y < SPR_DIM / 2)
		game->curs_pos.y = SPR_DIM / 2;
	else if (game->curs_pos.y > game->win_size.y - 1 - SPR_DIM - SPR_DIM / 2)
		game->curs_pos.y = game->win_size.y - 1 - SPR_DIM - SPR_DIM / 2;
}

void	get_player_to_cursor_dir(t_game *game, t_player *player)
{
	double	distance;

	player->pro_dir.x = game->curs_pos.x - player->pos.x;
	player->pro_dir.y = game->curs_pos.y - player->pos.y;
	distance = player->pro_dir.x * player->pro_dir.x;
	distance += player->pro_dir.y * player->pro_dir.y;
	distance = sqrt(distance);
	if (distance)
	{
		player->pro_dir.x *= PRO_SPEED / distance;
		player->pro_dir.y *= PRO_SPEED / distance;
	}
	else
	{
		player->pro_dir.x = PRO_SPEED;
		player->pro_dir.y = 0;
	}
}

void	draw_cursor(t_game *game)
{
	t_vector	snap_pos;

	snap_pos.x = nearbyint(game->player->pro_pos.x);
	snap_pos.y = nearbyint(game->player->pro_pos.y);
	if (game->player->pro_here)
		put_t_xpm_to_img(game->player->pro, game, snap_pos);
	put_t_xpm_to_img(game->cursor, game, game->curs_pos);
}

void	update_cursor(t_game *game)
{
	get_cursor_pos(game);
	refresh_area(game, game->last_cpos, 2, 2);
	if (game->player->pro_here)
		update_projectile(game, game->player, game->map);
}

int	handle_click(int key, int x, int y, t_game *game)
{
	t_vector	snap_pos;

	(void)x;
	(void)y;
	if (game->state != GAME_RUN || key != LEFT_CLICK)
		return (0);
	snap_pos.x = nearbyint(game->player->pro_pos.x);
	snap_pos.y = nearbyint(game->player->pro_pos.y);
	if (!game->player->pro_here)
		throw(game);
	else
	{
		game->player->pro_rethrow = 5;
		destroy_projectile(game, snap_pos);
	}
	return (0);
}
