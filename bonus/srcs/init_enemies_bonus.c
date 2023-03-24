/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemies_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:33:15 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/24 19:18:45 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_bonus.h"

static void	debug_enemies(t_enemy *enemy, int silent) //------------
{ //-----------------
	int	i;

	if (silent)
		return ;
	while (enemy->prev)
		enemy = enemy->prev;
	printf("\n");
	i = 0;
	while (enemy)
	{
		printf("Enemy %d is ", ++i);
		if (enemy->type == E_GROUND)
			printf("grounded\n");
		else if (enemy->type == E_FLY_H)
			printf("flying horizontally\n");
		else if (enemy->type == E_FLY_V)
			printf("flying vertically\n");
		else if (enemy->type == E_DEAD)
			printf("dead\n");
		printf("It is at (%d,%d) going at %d speed\n\n", enemy->pos.x, enemy->pos.y, enemy->speed);
		enemy = enemy->next;
	}
} //-----------------

static int	get_enemy_number(int floorsize)
{
	int	res;

	if (floorsize < 6)
		res = 0;
	else
		res = floorsize / ENEMY_DENSITY;
	if (res > ENEMY_MAX)
		res = ENEMY_MAX;
	//printf("There should be %d enemies on this map with %d floor tiles\n", res, floorsize); //---------
	return (res);
}

static t_enemy	*enemy_init_help(int nb, void *n, int i)
{
	t_enemy	*enemy;

	enemy = ft_calloc(1, sizeof(t_enemy));
	if (!enemy)
		return (NULL);
	enemy->prev = n;
	if (i < nb)
	{
		enemy->next = enemy_init_help(nb, enemy, i + 1);
		if (!enemy->next)
			return (free_enemies(enemy));
	}
	else
		enemy->next = NULL;
	return (enemy);
}

static void	enemy_init_pos(t_enemy *enemy, t_map *map)
{
	int	i;

	while (enemy->prev)
		enemy = enemy->prev;
	//printf("mapsizex %d\n", map->size.x); //----------------
	while (enemy)
	{
		//printf("Start is at (%d,%d)\n", map->start.x, map->start.y); //-------
		i = 0;
		while (map->map[enemy->pos.y][enemy->pos.x] != '0'
			|| enemy->pos.x == map->start.x || enemy->pos.y == map->start.y)
		{
			enemy->pos.x = rand() % map->size.x;
			enemy->pos.y = rand() % map->size.y;
			if (i++ == 20)
			{
				enemy->pos.x = -1;
				break ;
			}
			//printf("Trying to create enemy at (%d,%d)\n", enemy->pos.x, enemy->pos.y); //-------
		}
		//printf("\n"); //-------
		enemy->pos.x *= SPR_DIM;
		enemy->pos.y *= SPR_DIM;
		enemy = enemy->next;
	}
}

static void	enemy_init_state(t_enemy *enemy, t_map *map)
{
	int	i;

	while (enemy->prev)
		enemy = enemy->prev;
	i = 0;
	while (enemy)
	{
		if (enemy->pos.x >= 0)
		{
			enemy->anim_len = -1;
			enemy->alive = 1;
			enemy->type = get_enemy_type(enemy->pos, map->map);
			if (enemy->type == E_GROUND)
				enemy->dir = LEFT + i;
			else if (enemy->type == E_FLY_H)
				enemy->dir = LEFT + i;
			else if (enemy->type == E_FLY_V)
				enemy->dir = TOP + i;
		}
		else
			enemy->type = E_DEAD;
		enemy = enemy->next;
		if (!i)
			i = 1;
		else
			i = 0;
	}
}

t_enemy	*enemy_init(t_game *game, int *err)
{
	t_enemy	*enemy;

	game->nbenemies = get_enemy_number(game->map->floorsize);
	if (!game->nbenemies)
		return (NULL);
	enemy = enemy_init_help(game->nbenemies, NULL, 1);
	if (!enemy)
	{
		*err = MALLOCFAIL;
		return (NULL);
	}
	enemy_init_pos(enemy, game->map);
	enemy_init_state(enemy, game->map); //set type, speed, aliveness
	debug_enemies(enemy, 1); //---------------
	return (enemy);
}
