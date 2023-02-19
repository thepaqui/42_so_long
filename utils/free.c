/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:55:23 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/19 18:31:23 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static t_img	*free_img(t_img *image)
{
	if (!image)
		return (NULL);
	if (image->img)
	{
		free(image->img);
		image->img = NULL;
	}
	if (image->add)
	{
		free(image->add);
		image->add = NULL;
	}
	free(image);
	image = NULL;
	return (NULL);
}

static t_player	*free_player(t_player *player)
{
	if (!player)
		return (NULL);
	if (player->sprite)
		player->sprite = free_xpm(player->sprite);
	free(player);
	player = NULL;
	return (NULL);
}

static t_map	*free_map(t_map *map)
{
	if (!map)
		return (NULL);
	if (map->map)
		map->map = ft_free_tab(map->map, -1);
	if (map->sprite)
		map->sprite = free_xpm(map->sprite);
	if (map->coin_spr)
		map->coin_spr = free_xpm(map->coin_spr);
	if (map->coin_pos)
	{
		free(map->coin_pos);
		map->coin_pos = NULL;
	}
	free(map);
	map = NULL;
	return (NULL);
}

t_game	*free_game(t_game *game)
{
	if (!game)
		return (NULL);
	if (game->image)
		free_img(game->image);
	if (game->player)
		free_player(game->player);
	if (game->map)
		free_map(game->map);
	if (game->font)
		free_xpm(game->font);
	free(game);
	game = NULL;
	return (NULL);
}
