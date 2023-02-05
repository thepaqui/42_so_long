/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:21:36 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/05 21:40:22 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sl.h"

static t_img	*image_init(void)
{
	t_img	*image;

	image = ft_calloc(1, sizeof(t_img));
	if (!image)
		return (NULL);
	image->img = NULL;
	image->add = NULL;
	image->bits_per_pixel = 0;
	image->line_len = 0;
	image->endian = 0;
	return (image);
}

static t_player	*player_init(void)
{
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
	if (!player)
		return (NULL);
	player->pos_x = 0;
	player->pos_y = 0;
	player->up = 0;
	player->down = 0;
	player->left = 0;
	player->right = 0;
	return (player);
}

static t_camera	*camera_init(void)
{
	t_camera	*camera;

	camera = ft_calloc(1, sizeof(t_camera));
	if (!camera)
		return (NULL);
	camera->pos_x = 0;
	camera->pos_y = 0;
	camera->width = 0;
	camera->height = 0;
	return (camera);
}

static t_map	*map_init(void)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = NULL;
	map->width = 0;
	map->height = 0;
	map->start[0] = 0;
	map->start[1] = 0;
	map->exit[0] = 0;
	map->exit[1] = 0;
	map->nbcoins = 0;
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
	BIMG = image_init();
	MAP = map_init();
	PLAYER = player_init();
	CAM = camera_init();
	if (!IMG || !BIMG || !MAP || !PLAYER || !CAM)
	{
		free_game(game);
		*err = MALLOCFAIL;
		return (NULL);
	}
	MLX = NULL;
	WIN = NULL;
	return (game);
}
