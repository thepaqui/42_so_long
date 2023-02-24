/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_detection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:33:25 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/24 16:36:47 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

int	get_pos_walls_around(char **map, t_vector s, t_vector pos)
{
	int	ret;
	int	x;
	int	y;

	x = pos.x;
	y = pos.y;
	ret = 0;
	if (x == s.x - 1 || y == s.y - 1 || map[y + 1][x + 1] == WALL)
		ret = 1;
	if (y == s.y - 1 || map[y + 1][x] == WALL)
		ret += (1 << 1);
	if (!x || y == s.y - 1 || map[y + 1][x - 1] == WALL)
		ret += (1 << 2);
	if (x == s.x - 1 || map[y][x + 1] == WALL)
		ret += (1 << 3);
	if (!x || map[y][x - 1] == WALL)
		ret += (1 << 4);
	if (x == s.x - 1 || !y || map[y - 1][x + 1] == WALL)
		ret += (1 << 5);
	if (!y || map[y - 1][x] == WALL)
		ret += (1 << 6);
	if (!x || !y || map[y - 1][x - 1] == WALL)
		ret += (1 << 7);
	return (ret);
}
