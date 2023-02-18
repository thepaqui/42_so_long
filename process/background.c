/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:35:04 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/18 22:34:50 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

static int	get_obj_spr(char **map, t_vector pos)
{
	char	obj;

	obj = map[pos.y / SPR_DIM][pos.x / SPR_DIM];
	if (obj == EMPTY || obj == COIN || obj == PLAYER)
		return (0);
	else if (obj == WALL)
		return (1);
	else if (obj == EXIT_CLOSE)
		return (2);
	else if (obj == EXIT_OPEN)
		return (3);
	else
		return (1);
}

static void	draw_all_background(t_game *game, t_map *map)
{
	t_vector	pos;

	pos.y = 0;
	while (pos.y < game->win_size.y)
	{
		pos.x = 0;
		while (pos.x < game->win_size.x)
		{
			map->sprite->cur_spr = get_obj_spr(map->map, pos);
			//printf("Drawing map tile at (%i,%i)\n", pos.x, pos.y); //-------------
			put_t_xpm_to_img(map->sprite, game, pos);
			pos.x += SPR_DIM;
		}
		pos.y += SPR_DIM;
	}
}

static void	draw_background_part(t_game *game)
{
	t_vector	pos;
	int			lin;
	int			col;

	lin = 0;
	pos.y = SPR_DIM * (game->player->pos.y / SPR_DIM);
	while (lin < 2)
	{
		pos.x = SPR_DIM * (game->player->pos.x / SPR_DIM);
		col = 0;
		while (col < 2)
		{
			game->map->sprite->cur_spr = get_obj_spr(game->map->map, pos);
			//printf("Drawing map tile at (%i,%i)\n", pos.x, pos.y); //-------------
			if (get_obj_from_pos(pos, game->map) != 'C')
				put_t_xpm_to_img(game->map->sprite, game, pos);
			col++;
			pos.x += SPR_DIM;
		}
		lin++;
		pos.y += SPR_DIM;
	}
}

void	draw_map(t_game *game)
{
	t_vector	exitpos;

	if (game->player->state == PIDLE && game->player->sprite->cur_spr == 5)
		game->player->state = PCOIN;
	if (game->state == GAME_ERROR)
		return ;
	else if (game->state == GAME_STARTUP)
	{
		draw_all_background(game, game->map);
		game->state = GAME_RUN;
	}
	else if (game->player->state != PIDLE)
		draw_background_part(game);
	if (!game->map->nbcoins)
	{
		game->map->sprite->cur_spr = 3;
		exitpos.x = game->map->exit.x * SPR_DIM;
		exitpos.y = game->map->exit.y * SPR_DIM;
		put_t_xpm_to_img(game->map->sprite, game, exitpos);
		game->map->nbcoins--;
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
		game->state = GAME_STOP;
	if (!map->nbcoins)
		map->map[map->exit.y][map->exit.x] = EXIT_OPEN;
}
