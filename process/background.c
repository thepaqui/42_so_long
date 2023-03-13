/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:35:04 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/13 01:11:18 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

static int	get_obj_spr(char **map, t_vector map_size, t_vector pos)
{
	char	obj;

	pos.x /= SPR_DIM;
	pos.y /= SPR_DIM;
	obj = map[pos.y][pos.x];
	if (obj == EMPTY || obj == COIN || obj == PLAYER)
		return (0);
	else if (obj == WALL)
		return (get_wall_texture(map, map_size, pos));
	else if (obj == EXIT_CLOSE)
		return (48);
	else if (obj == EXIT_OPEN)
		return (49);
	else
		return (1);
}

/*static void	draw_all_background(t_game *game, t_map *map)
{
	t_vector	pos;

	pos.y = 0;
	while (pos.y < game->win_size.y)
	{
		pos.x = 0;
		while (pos.x < game->win_size.x)
		{
			map->sprite->cur_spr = get_obj_spr(map->map, map->size, pos);
			put_t_xpm_to_img(map->sprite, game, pos);
			pos.x += SPR_DIM;
		}
		pos.y += SPR_DIM;
	}
}*/

void	draw_bg_part(t_game *game, t_map *map, t_vector opos, t_vector s)
{
	t_vector	pos;
	int			lin;
	int			col;

	lin = 0;
	pos.y = SPR_DIM * (opos.y / SPR_DIM);
	while (lin < s.y)
	{
		pos.x = SPR_DIM * (opos.x / SPR_DIM);
		col = 0;
		while (col < s.x)
		{
			map->sprite->cur_spr = get_obj_spr(map->map, map->size, pos);
			if (get_obj_from_pos(pos, map) != 'C')
				put_t_xpm_to_img(map->sprite, game, pos);
			col++;
			pos.x += SPR_DIM;
		}
		lin++;
		pos.y += SPR_DIM;
	}
}

void	draw_map(t_game *game)
{
	t_vector	pos;

	if (game->player->state == PIDLE && game->player->sprite->cur_spr == 5)
		game->player->state = PCOIN;
	if (game->state == GAME_ERROR)
		return ;
	else if (game->state == GAME_STARTUP)
	{
		pos.x = 0;
		pos.y = 0;
		refresh_area(game, pos, game->win_size.x / SPR_DIM, game->win_size.y / SPR_DIM);
		//draw_all_background(game, game->map);
		game->state = GAME_RUN;
	}
	else if (game->player->state != PIDLE)
		refresh_area(game, game->player->pos, 3, 3);
	if (game->map->nbcoins == game->map->totalcoins)
	{
		game->map->sprite->cur_spr = 49;
		pos.x = game->map->exit.x * SPR_DIM;
		pos.y = game->map->exit.y * SPR_DIM;
		refresh_area(game, pos, 1, 1);
		put_t_xpm_to_img(game->map->sprite, game, pos);
	}
}

void	update_map(t_map *map, t_game *game)
{
	t_vector	pos;
	int			coin;

	pos.x = (game->player->pos.x + SPR_DIM / 2) / SPR_DIM;
	pos.y = (game->player->pos.y + SPR_DIM / 2) / SPR_DIM;
	if (pos.x != map->start.x || pos.y != map->start.y)
	{
		map->start.x = pos.x;
		map->start.y = pos.y;
		game->moves++;
	}
	pos.x = game->player->pos.x + SPR_DIM / 2;
	pos.y = game->player->pos.y + SPR_DIM / 2;
	coin = touch_obj(pos, map, COIN, PLAYER_HITBOX);
	if (coin != NONE)
		collect_coin(map, game, pos, coin);
	if (map->map[map->start.y][map->start.x] == EXIT_OPEN)
		game->state = GAME_WIN;
	if (map->nbcoins == map->totalcoins)
		map->map[map->exit.y][map->exit.x] = EXIT_OPEN;
}
