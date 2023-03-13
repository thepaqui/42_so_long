/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:21:36 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/13 01:26:07 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

static t_img	*image_init(void)
{
	t_img	*image;

	image = ft_calloc(1, sizeof(t_img));
	return (image);
}

static t_player	*player_init(int *err, char *file)
{
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
	if (!player)
		return (NULL);
	player->sprite = parse_xpm(file, err);
	if (!player->sprite || *err)
	{
		if (player->sprite)
			player->sprite = free_xpm(player->sprite);
		free(player);
		return (NULL);
	}
	player->speed = PLAYER_SPEED;
	return (player);
}

static t_map	*map_init(int *err, char *fmap, char *fcoin, char *fbg)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		*err = MALLOCFAIL;
		return (NULL);
	}
	map->sprite = parse_xpm(fmap, err);
	if (!map->sprite)
	{
		free(map);
		return (NULL);
	}
	map->coin_spr = parse_xpm(fcoin, err);
	if (!map->coin_spr)
	{
		map->sprite = free_xpm(map->sprite);
		free(map);
		return (NULL);
	}
	map->bg = parse_xpm(fbg, err);
	if (!map->bg)
	{
		map->sprite = free_xpm(map->sprite);
		map->coin_spr = free_xpm(map->coin_spr);
		free(map);
		return (NULL);
	}
	map->last = -1;
	return (map);
}

t_game	*game_init(int *err)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		*err = MALLOCFAIL;
		return (NULL);
	}
	game->image = image_init();
	if (!game->image)
	{
		*err = MALLOCFAIL;
		return (free_game(game));
	}
	game->map = map_init(err, MAP_SPRITE, COIN_SPRITE, BG_SPRITE);
	if (!game->map)
		error_handling(*err, game, "Map structure");
	game->player = player_init(err, PLAYER_SPRITE);
	if (!game->player)
		error_handling(*err, game, "Player structure");
	game->font = parse_xpm(FONT, err);
	if (!game->font)
		error_handling(*err, game, FONT);
	game->last_moves = -1;
	return (game);
}
