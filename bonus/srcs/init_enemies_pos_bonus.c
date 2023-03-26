/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemies_pos_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:44:06 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/25 21:16:25 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_bonus.h"

static int	get_enemy_grounded_zone(t_vector pos, char **map)
{
	t_vector	m;
	int			widg;

	m.x = pos.x / SPR_DIM;
	m.y = pos.y / SPR_DIM;
	widg = 0;
	while (map[m.y][m.x - 1] != WALL && map[m.y + 1][m.x - 1] == WALL)
		m.x--;
	while (map[m.y][m.x] != WALL && map[m.y + 1][m.x] == WALL)
	{
		m.x++;
		widg++;
	}
	return (widg);
}

int	get_enemy_type(t_vector pos, char **map)
{
	t_vector	m;
	int			wid;
	int			widg;
	int			hei;

	m.x = pos.x / SPR_DIM;
	m.y = pos.y / SPR_DIM;
	widg = get_enemy_grounded_zone(pos, map);
	wid = 0;
	while (map[m.y][m.x - 1] != WALL)
		m.x--;
	while (map[m.y][m.x++] != WALL)
		wid++;
	m.x = pos.x / SPR_DIM;
	hei = 0;
	while (map[m.y - 1][m.x] != WALL)
		m.y--;
	while (map[m.y++][m.x] != WALL)
		hei++;
	if (widg >= 4 && widg >= wid / 2)
		return (E_GROUND);
	else if (hei >= wid)
		return (E_FLY_V);
	return (E_FLY_H);
}
