/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:21:36 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/18 21:57:27 by thepaqui         ###   ########.fr       */
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

static t_map	*map_init(int *err, char *filemap, char *filecoin)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		*err = MALLOCFAIL;
		return (NULL);
	}
	map->sprite = parse_xpm(filemap, err);
	if (!map->sprite)
	{
		free(map);
		return (NULL);
	}
	map->coin_spr = parse_xpm(filecoin, err);
	if (!map->coin_spr)
	{
		map->sprite = free_xpm(map->sprite);
		free(map);
		return (NULL);
	}
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
	IMG = image_init();
	if (!IMG)
	{
		*err = MALLOCFAIL;
		return (free_game(game));
	}
	MAP = map_init(err, MAP_SPRITE, COIN_SPRITE);
	if (!MAP)
		error_handling(*err, game, NULL);
	game->player = player_init(err, PLAYER_SPRITE);
	if (!game->player)
		error_handling(*err, game, PLAYER_SPRITE);
	return (game);
}
