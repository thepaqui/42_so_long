/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:30:40 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/05 20:01:18 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "check.h"

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

static void	obj_counter(int i, int j, int *io, t_game *game)
{
	if (MAPMAP[i][j] == 'C')
		NBCOINS++;
	else if (MAPMAP[i][j] == 'P')
	{
		io[0]++;
		XSTART = j;
		YSTART = i;
	}
	else if (MAPMAP[i][j] == 'E')
	{
		io[1]++;
		XEXIT = j;
		YEXIT = i;
	}
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
	while (MAPMAP[++i])
	{
		j = -1;
		while (MAPMAP[i][++j])
		{
			if (!isinset(MAPMAP[i][j], "01CEP"))
				return (WRONGCHAR);
			obj_counter(i, j, io, game);
		}
	}
	return (obj_check(io[0], io[1], NBCOINS));
}

int	check_map(t_game *game)
{
	int	err;

	if (!MAPMAP)
		return (MALLOCFAIL);
	clean_map(MAPMAP);
	NBCOINS = 0;
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
