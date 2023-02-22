/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:04:55 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/22 17:07:36 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parse.h"

int	get_coins_pos(t_map *map)
{
	int	lin;
	int	col;
	int	coin;

	map->coin_pos = ft_calloc(map->totalcoins, sizeof(t_vector));
	if (!map->coin_pos)
		return (MALLOCFAIL);
	coin = 0;
	lin = -1;
	while (map->map[++lin])
	{
		col = -1;
		while (map->map[lin][++col])
		{
			if (map->map[lin][col] == 'C')
			{
				map->coin_pos[coin].y = lin;
				map->coin_pos[coin].x = col;
				coin++;
			}
		}
	}
	return (0);
}
