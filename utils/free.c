/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:55:23 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/05 19:06:20 by thepaqui         ###   ########.fr       */
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
	free(player);
	player = NULL;
	return (NULL);
}

static t_camera	*free_camera(t_camera *camera)
{
	if (!camera)
		return (NULL);
	free(camera);
	camera = NULL;
	return (NULL);
}

static t_map	*free_map(t_map *map)
{
	if (!map)
		return (NULL);
	if (map->map)
		map->map = ft_free_tab(map->map, -1);
	free(map);
	map = NULL;
	return (NULL);
}

t_game	*free_game(t_game *game)
{
	if (!game)
		return (NULL);
	if (IMG)
		IMG = free_img(IMG);
	if (BIMG)
		BIMG = free_img(BIMG);
	if (PLAYER)
		PLAYER = free_player(PLAYER);
	if (CAM)
		CAM = free_camera(CAM);
	if (MAP)
		MAP = free_map(MAP);
	free(game);
	game = NULL;
	return (NULL);
}
