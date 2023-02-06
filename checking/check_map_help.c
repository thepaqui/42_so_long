/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:19:58 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/05 20:05:55 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "check.h"

static int	check_walls(char **map, int lines, int last)
{
	int	i;

	i = -1;
	while (map[0][++i])
		if (map[0][i] != '1')
			return (BADWALLS);
	lines--;
	i = -1;
	while (map[lines][++i])
		if (map[lines][i] != '1')
			return (BADWALLS);
	i = -1;
	while (map[++i])
		if (map[i][0] != '1' || map[i][last] != '1')
			return (BADWALLS);
	return (0);
}

int	check_shape(t_game *game)
{
	int	len;
	int	i;
	int	lines;

	len = ft_strlen(MAPMAP[0]);
	MAPWID = len;
	i = 0;
	while (MAPMAP[++i])
		if (ft_strlen(MAPMAP[i]) != len)
			return (NOTRECT);
	MAPHEI = i;
	lines = 0;
	while (MAPMAP[lines])
		lines++;
	return (check_walls(MAPMAP, lines, len - 1));
}

static char	**duplicate_map(char **map)
{
	int		size;
	char	**new;
	int		i;

	size = 0;
	while (map[size])
		size++;
	new = ft_calloc(size + 1, sizeof(char *));
	if (!new)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		new[i] = ft_strndup(map[i], ft_strlen(map[i]));
		if (!new[i])
			return (ft_free_tab(new, -1));
	}
	return (new);
}

static int	flood_fill(char **map, int x, int y, int *requirements)
{
	if (map[y][x] == '1')
		return (0);
	else if (map[y][x] == 'C')
		requirements[1]++;
	else if (map[y][x] == 'E')
		requirements[0] = 1;
	map[y][x] = '1';
	flood_fill(map, x + 1, y, requirements);
	flood_fill(map, x - 1, y, requirements);
	flood_fill(map, x, y + 1, requirements);
	flood_fill(map, x, y - 1, requirements);
	return (0);
}

int	check_path(t_game *game)
{
	char	**flood_map;
	int		x;
	int		y;
	int		requirements[2];

	flood_map = duplicate_map(MAPMAP);
	if (!flood_map)
		return (MALLOCFAIL);
	x = XSTART;
	y = YSTART;
	requirements[0] = 0;
	requirements[1] = 0;
	flood_fill(flood_map, x, y, requirements);
	ft_free_tab(flood_map, -1);
	if (!requirements[0])
		return (NOWAY);
	if (requirements[1] != NBCOINS)
		return (NOMONEY);
	return (0);
}
