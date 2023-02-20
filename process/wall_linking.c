/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_linking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:54:53 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/20 23:09:26 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

static int	get_nb_walls_around(char **map, t_vector s, t_vector pos)
{
	int	ret;
	int	x;
	int	y;

	x = pos.x;
	y = pos.y;
	ret = 0;
	if (x != s.x - 1 && y != s.y - 1 && map[y + 1][x + 1] == WALL)
		ret = 1;
	printf("1\n"); //-------------
	if (x != s.x - 1 && map[y][x + 1] == WALL)
		ret += (1 << 1);
	printf("2\n"); //-------------
	if (y && x != s.x - 1 && map[y - 1][x + 1] == WALL)
		ret += (1 << 2);
	printf("3\n"); //-------------
	if (y != s.y - 1 && map[y + 1][x] == WALL)
		ret += (1 << 3);
	printf("4\n"); //-------------
	if (y && map[y - 1][x] == WALL)
		ret += (1 << 4);
	printf("5\n"); //-------------
	if (y != s.y - 1 && x && map[y + 1][x - 1] == WALL)
		ret += (1 << 5);
	printf("6\n"); //-------------
	if (x && map[y][x - 1] == WALL)
		ret += (1 << 6);
	printf("7\n"); //-------------
	if (x && y && map[y - 1][x - 1] == WALL)
		ret += (1 << 7);
	printf("8\n"); //-------------
	return (ret);
}

int	get_wall_texture(char **map, t_vector size, t_vector pos)
{
	int	around;

	printf("Starting detection at (%d,%d)\n", pos.x, pos.y); //-------------
	printf("Map has a size of (%d,%d)\n", size.x, size.y); //-------
	around = get_nb_walls_around(map, size, pos);
	printf("Detection results are %d\n\n", around); //------------
	return (1); //--------------
}
