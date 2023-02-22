/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_linking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:54:53 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/22 16:44:11 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

static int	get_pos_walls_around(char **map, t_vector s, t_vector pos)
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

int	get_wall_texture(char **map, t_vector size, t_vector pos)
{
	int	ar;

	//printf("Starting detection at (%d,%d)\n", pos.x, pos.y); //-------------
	//printf("Map has a size of (%d,%d)\n", size.x, size.y); //------------
	ar = get_pos_walls_around(map, size, pos);
	//printf("Detection results are %d\n\n", ar); //------------
	if (ar == 255)
		return (25);
	else if ((ar & 254) == 254)
		return (28);
	else if ((ar & 251) == 251)
		return (29);
	else if ((ar & 223) == 223)
		return (38);
	else if ((ar & 127) == 127)
		return (39);
	else if ((ar & 219) == 219)
		return (27);
	else if ((ar & 126) == 126)
		return (37);
	else if ((ar & 95) == 95)
		return (46);
	else if ((ar & 222) == 222)
		return (44);
	else if ((ar & 250) == 250)
		return (45);
	else if ((ar & 123) == 123)
		return (47);
	else if ((ar & 248) == 248)
		return (35);
	else if ((ar & 214) == 214)
		return (26);
	else if ((ar & 107) == 107)
		return (24);
	else if ((ar & 31) == 31)
		return (15);
	else if ((ar & 218) == 218)
		return (40);
	else if ((ar & 122) == 122)
		return (41);
	else if ((ar & 94) == 94)
		return (42);
	else if ((ar & 91) == 91)
		return (43);
	else if ((ar & 216) == 216)
		return (5);
	else if ((ar & 120) == 120)
		return (4);
	else if ((ar & 30) == 30)
		return (7);
	else if ((ar & 27) == 27)
		return (6);
	else if ((ar & 210) == 210)
		return (17);
	else if ((ar & 106) == 106)
		return (9);
	else if ((ar & 86) == 86)
		return (18);
	else if ((ar & 75) == 75)
		return (19);
	else if ((ar & 90) == 90)
		return (22);
	else if ((ar & 208) == 208)
		return (36);
	else if ((ar & 104) == 104)
		return (34);
	else if ((ar & 22) == 22)
		return (16);
	else if ((ar & 11) == 11)
		return (14);
	else if ((ar & 88) == 88)
		return (32);
	else if ((ar & 82) == 82)
		return (23);
	else if ((ar & 74) == 74)
		return (21);
	else if ((ar & 26) == 26)
		return (12);
	else if ((ar & 80) == 80)
		return (33);
	else if ((ar & 72) == 72)
		return (31);
	else if ((ar & 18) == 18)
		return (13);
	else if ((ar & 10) == 10)
		return (11);
	else if ((ar & 66) == 66)
		return (20);
	else if ((ar & 24) == 24)
		return (3);
	else if ((ar & 64) == 64)
		return (30);
	else if ((ar & 2) == 2)
		return (10);
	else if ((ar & 8) == 8)
		return (2);
	else if ((ar & 16) == 16)
		return (8);
	else
		return (1);
}
