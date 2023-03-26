/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_anim_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:14:02 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 17:38:01 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

static void	enemy_anim_fh(t_game *game, t_enemy *enemy)
{
	if (enemy->anim_len < 0)
		enemy->anim_len = EFHA_LEN;
	if (!enemy->anim_len)
	{
		if (enemy->cur_spr == EHA_ER)
			enemy->cur_spr = EHA_SR;
		else if (enemy->cur_spr == EHA_EL)
			enemy->cur_spr = EHA_SL;
		else
			enemy->cur_spr++;
		if (enemy->cur_spr < EHA_SL && enemy->speed < 0)
			enemy->cur_spr += 4;
		else if (enemy->cur_spr > EHA_ER && enemy->speed > 0)
			enemy->cur_spr -= 4;
	}
	game->spr_efh->cur_spr = enemy->cur_spr;
}

static void	enemy_anim_g(t_game *game, t_enemy *enemy)
{
	if (enemy->anim_len < 0)
		enemy->anim_len = EGHA_LEN;
	if (!enemy->anim_len)
	{
		if (enemy->cur_spr == EHA_ER)
			enemy->cur_spr = EHA_SR;
		else if (enemy->cur_spr == EHA_EL)
			enemy->cur_spr = EHA_SL;
		else
			enemy->cur_spr++;
		if (enemy->cur_spr < EHA_SL && enemy->speed < 0)
			enemy->cur_spr += 4;
		else if (enemy->cur_spr > EHA_ER && enemy->speed > 0)
			enemy->cur_spr -= 4;
	}
	game->spr_eg->cur_spr = enemy->cur_spr;
}

static void	enemy_anim_fv(t_game *game, t_enemy *enemy)
{
	if (!enemy->turn)
	{
		enemy->cur_spr = EVA_SU;
		if (enemy->dir == BOT)
			enemy->cur_spr = EVA_SD;
	}
	else
	{
		if (enemy->anim_len < 0)
			enemy->anim_len = EVA_LEN;
		if (!enemy->anim_len)
		{
			if (enemy->cur_spr == EVA_ED || enemy->cur_spr == EVA_EU)
			{
				enemy->cur_spr = EVA_SD;
				if (enemy->cur_spr == EVA_ED)
					enemy->cur_spr = EVA_SU;
				enemy->turn = 0;
			}
			else
				enemy->cur_spr++;
		}
	}
	game->spr_efv->cur_spr = enemy->cur_spr;
}

void	set_enemy_animations(t_game *game, t_enemy *enemy)
{
	if (enemy->type == E_GROUND)
		enemy_anim_g(game, enemy);
	else if (enemy->type == E_FLY_H)
		enemy_anim_fh(game, enemy);
	else if (enemy->type == E_FLY_V)
		enemy_anim_fv(game, enemy);
	enemy->anim_len--;
}
