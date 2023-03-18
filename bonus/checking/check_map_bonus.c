/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:30:40 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/18 16:54:58 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_bonus.h"

static void	clean_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = '\0';
		i++;
	}
	while (map[--i][0] == '\0')
	{
		free(map[i]);
		map[i] = NULL;
	}
}

static void	obj_counter(int i, int j, int *io, t_map *map)
{
	if (map->map[i][j] == 'C')
	{
		map->totalcoins++;
		map->floorsize++;
	}
	else if (map->map[i][j] == 'P')
	{
		io[0]++;
		map->start.x = j;
		map->start.y = i;
	}
	else if (map->map[i][j] == 'E')
	{
		io[1]++;
		map->exit.x = j;
		map->exit.y = i;
	}
	else if (map->map[i][j] == '0')
		map->floorsize++;
}

static int	obj_check(int start, int end, int collect)
{
	if (!start)
		return (NOSTART);
	if (start > 1)
		return (TOOMANYSTART);
	if (!end)
		return (NOEXIT);
	if (end > 1)
		return (TOOMANYEXIT);
	if (!collect)
		return (NOCOLLECT);
	return (0);
}

static int	check_chars(t_game *game)
{
	int	i;
	int	j;
	int	io[2];

	io[0] = 0;
	io[1] = 0;
	i = -1;
	while (game->map->map[++i])
	{
		j = -1;
		while (game->map->map[i][++j])
		{
			if (!isinset(game->map->map[i][j], "01CEP"))
				return (WRONGCHAR);
			obj_counter(i, j, io, game->map);
		}
	}
	return (obj_check(io[0], io[1], game->map->totalcoins));
}

int	check_map(t_game *game)
{
	int	err;

	if (!game->map->map)
		return (MALLOCFAIL);
	clean_map(game->map->map);
	game->map->nbcoins = 0;
	err = check_chars(game);
	if (err)
		return (err);
	err = check_shape(game);
	if (err)
		return (err);
	err = check_path(game);
	if (err)
		return (err);
	return (0);
}
