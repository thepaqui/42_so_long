/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_collisions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:20:06 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/21 16:02:25 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

void	update_enemy_distances(t_player *player, t_enemy *enemy)
{
	t_vector	ppos;
	t_vector	epos;
	t_vector	prpos;

	ppos.x = (player->pos.x + (SPR_DIM / 2)) / SPR_DIM;
	ppos.y = (player->pos.y + (SPR_DIM / 2)) / SPR_DIM;
	epos.x = (enemy->pos.x + (SPR_DIM / 2)) / SPR_DIM;
	epos.y = (enemy->pos.y + (SPR_DIM / 2)) / SPR_DIM;
	enemy->dist_to_player = get_manhattan_dist(ppos, epos);
	if (player->pro_here)
	{
		prpos.x = (player->pro_pos.x + (SPR_DIM / 2)) / SPR_DIM;
		prpos.y = (player->pro_pos.y + (SPR_DIM / 2)) / SPR_DIM;
		enemy->dist_to_proj = get_manhattan_dist(prpos, epos);
	}
	else
		enemy->dist_to_proj = -1;
}

static int	check_enemy_collide_projectile(t_game *g, t_player *p, t_enemy *e)
{
	t_vector	prpos;
	t_vector	epos;
	t_vector	dist;
	double		d;

	prpos.x = nearbyint(p->pro_pos.x + (SPR_DIM / 2));
	prpos.y = nearbyint(p->pro_pos.y + (SPR_DIM / 2));
	epos.x = e->pos.x + (SPR_DIM / 2);
	epos.y = e->pos.y + (SPR_DIM / 2);
	dist.x = epos.x - prpos.x;
	if (dist.x < 0)
		dist.x *= -1;
	dist.y = epos.y - prpos.y;
	if (dist.y < 0)
		dist.y *= -1;
	d = sqrt((dist.x * dist.x) + (dist.y * dist.y));
	if (d < ENEMY_HITBOX + (PRO_HITBOX / 2))
	{
		prpos.x = nearbyint(p->pro_pos.x);
		prpos.y = nearbyint(p->pro_pos.y);
		destroy_enemy(g, e);
		destroy_projectile(g, prpos);
		return (1);
	}
	return (0);
}

static int	check_enemy_collide_player(t_game *g, t_player *p, t_enemy *e)
{
	t_vector	plpos;
	t_vector	epos;
	t_vector	dist;
	double		d;

	plpos.x = p->pos.x + (SPR_DIM / 2);
	plpos.y = p->pos.y + (SPR_DIM / 2);
	epos.x = e->pos.x + (SPR_DIM / 2);
	epos.y = e->pos.y + (SPR_DIM / 2);
	dist.x = epos.x - plpos.x;
	if (dist.x < 0)
		dist.x *= -1;
	dist.y = epos.y - plpos.y;
	if (dist.y < 0)
		dist.y *= -1;
	d = sqrt((dist.x * dist.x) + (dist.y * dist.y));
	if (d < ENEMY_HITBOX + (PLAYER_HITBOX / 2))
	{
		destroy_enemy(g, e);
		return (1);
	}
	return (0);
}

int	check_enemy_collisions(t_game *game, t_player *player, t_enemy *enemy)
{
	int	hit;

	hit = 0;
	if (enemy->dist_to_proj >= 0 && enemy->dist_to_proj <= 2)
		hit = check_enemy_collide_projectile(game, player, enemy);
	if (hit)
		return (1);
	if (enemy->dist_to_player <= 2)
		hit = check_enemy_collide_player(game, player, enemy);
	if (hit)
		game->state = GAME_LOSE;
	return (hit);
}
