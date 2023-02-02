/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:30:40 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/02 18:44:22 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "check.h"

static void	clean_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	while (map[--i][0] == '\0')
	{
		free(map[i]);
		map[i] = NULL;
	}
}

static void	obj_counter(char c, int *start, int *end, int *collect)
{
	if (c == 'C')
		*collect++;
	else if (c == 'E')
		*end++;
	else if (c == 'P')
		*start++;
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

static int	check_chars(char **map)
{
	int	i;
	int	j;
	int	start;
	int	end;
	int	collect;

	start = 0;
	end = 0;
	collect = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!isinset(map[i][j], "01CEP"))
				return (WRONGCHAR);
			obj_counter(map[i][j], &start, &end, &collect);
		}
	}
	return (obj_check(start, end, collect));
}

int	check_map(char **map)
{
	int	err;

	if (!map)
		return (MALLOCFAIL);
	clean_map(map);
	err = check_chars(map); // should retrieve collectibles count here
	if (err)
		return (err);
	// check rectangle
	// check walls
	// check valid path
	return (0);
}
