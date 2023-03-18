/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemies_pos_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:44:06 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/18 20:44:52 by thepaqui         ###   ########.fr       */
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
	while (map[m.y][m.x - 1] != '1' && map[m.y + 1][m.x - 1] == '1')
		m.x--;
	while (map[m.y][m.x] != '1' && map[m.y + 1][m.x] == '1')
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
	/*printf("\nEnemy is at (%d,%d)\n", m.x, m.y); //-----------
	for (int i = 0; map[i]; i++) {//-----------
		for (int j = 0; map[i][j]; j++) {//-----------
			if (i == m.y || j == m.x)
				printf("\033[1;31m""%c", map[i][j]); //---------
			else
				printf("\033[0m""%c", map[i][j]); //---------
		} //---------------
		printf("\n"); //-------------
	} //---------------
	printf("\n"); //-------------*/
	widg = get_enemy_grounded_zone(pos, map);
	//printf("Enemy walking line has width = %d\n", widg); //-------------
	wid = 0;
	while (map[m.y][m.x - 1] != '1')
		m.x--;
	while (map[m.y][m.x++] != '1')
		wid++;
	//printf("Enemy flying line has width = %d\n", wid); //-------------
	m.x = pos.x / SPR_DIM;
	hei = 0;
	while (map[m.y - 1][m.x] != '1')
		m.y--;
	while (map[m.y++][m.x] != '1')
		hei++;
	//printf("Enemy flying column has height = %d\n", hei); //-------------
	if (widg >= 4 && widg >= wid / 2)
		return (E_GROUND);
	else if (hei >= wid)
		return (E_FLY_V);
	return (E_FLY_H);
}
