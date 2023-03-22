/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:09:56 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/22 22:25:17 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

void	destroy_enemy(t_game *game, t_enemy *enemy)
{
	enemy->type = E_DEAD;
	enemy->alive = 0;
	enemy->speed = 0;
	enemy->dir = NONE;
	enemy->turn = 0;
	enemy->anim_len = 0;
	enemy->dist_to_player = 100;
	enemy->dist_to_proj = 100;
	enemy->pos.x = -1;
	enemy->pos.y = -1;
	game->need_enemy_refresh = 1;
}

static void update_enemy(t_game *game, t_enemy *enemy)
{
	if (enemy->type == E_FLY_V)
		refresh_area(game, enemy->pos, 1, 2);
	else
		refresh_area(game, enemy->pos, 2, 1);
	update_enemy_distances(game->player, enemy);
	if (check_enemy_collisions(game, game->player, enemy))
		return ;
	update_enemy_speed(enemy);
	update_enemy_pos(enemy, game->map);
}

void	update_enemies(t_game *game, t_enemy *enemies)
{
	while (enemies->prev)
		enemies = enemies->prev;
	//int i = 0; //-----------------
	while (enemies)
	{
		/*i++; //-----------------
		if (enemies->alive) //-----------------
			printf("Enemy %d is alive!\n", i); //-----------------
		else //-----------------
			printf("Enemy %d is dead...\n", i); //-----------------*/
		if (enemies->alive)
			update_enemy(game, enemies);
		if (game->state == GAME_LOSE)
			return ;
		if (!enemies->next)
			break ;
		enemies = enemies->next;
	}
	//printf("\n"); //-----------------
	while (enemies->prev)
		enemies = enemies->prev;
	if (game->need_enemy_refresh)
	{
		enemies = clean_enemy_list(game, enemies);
		game->enemies = enemies;
	}
}

static void draw_enemy(t_game *game, t_enemy *enemy)
{
	set_enemy_animations(game, enemy);
	if (enemy->type == E_GROUND)
		put_t_xpm_to_img(game->spr_eg, game, enemy->pos);
	else if (enemy->type == E_FLY_H)
		put_t_xpm_to_img(game->spr_efh, game, enemy->pos);
	else if (enemy->type == E_FLY_V)
		put_t_xpm_to_img(game->spr_efv, game, enemy->pos);
}

void	draw_enemies(t_game *game, t_enemy *enemies)
{
	while (enemies->prev)
		enemies = enemies->prev;
	//int i = 0; //------
	while (enemies)
	{
		//i++; //-----
		//printf("enemy %i is type %i\n", i, enemies->type); //--
		//if (i == 50) //---
			//printf("enemy %d has dir = %d and speed = %d\n", i, enemies->dir, enemies->speed); //---
		draw_enemy(game, enemies);
		if (!enemies->next)
			break ;
		enemies = enemies->next;
	}
}
