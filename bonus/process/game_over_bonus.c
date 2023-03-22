/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:42:58 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/22 15:42:33 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

void	refresh_bg_color(t_game *game, t_vector opos, int width, int height)
{
	t_vector	pos;

	pos.y = opos.y - 1;
	while (++pos.y < opos.y + (SPR_DIM * height))
	{
		pos.x = opos.x - 1;
		while (++pos.x < opos.x + (SPR_DIM * width))
			put_pixel_to_img(game, pos, GAME_OVER_BG);
	}
}

static void	print_game_over(t_game *game, int color)
{
	t_vector	pos;
	int			offset;
	int			len;

	if (game->map->size.x > ft_strlen(DIE_MSG_XL) + 2)
		len = ft_strlen(DIE_MSG_XL);
	else if (game->map->size.x > ft_strlen(DIE_MSG_L) + 2)
		len = ft_strlen(DIE_MSG_L);
	else if (game->map->size.x > ft_strlen(DIE_MSG_M) + 2)
		len = ft_strlen(DIE_MSG_M);
	else
		len = ft_strlen(DIE_MSG_S);
	offset = 0;
	if (game->map->size.y % 2 == 0)
		offset = SPR_DIM / 2;
	pos.y = ((game->map->size.y / 2) * SPR_DIM) - offset;
	pos.x = (game->map->size.x * SPR_DIM) / 2 - (len * SPR_DIM / 2);
	if (game->map->ft)
		ft_end(game, color);
	else if (len == ft_strlen(DIE_MSG_M))
		put_str_to_img(DIE_MSG_M, pos, game, color);
	else if (len == ft_strlen(DIE_MSG_S))
		put_str_to_img(DIE_MSG_S, pos, game, color);
	else if (len == ft_strlen(DIE_MSG_XL))
		put_str_to_img(DIE_MSG_XL, pos, game, color);
	else
		put_str_to_img(DIE_MSG_L, pos, game, color);
}

void	game_over_sequence(t_game *game, t_player *p)
{
	if (p->state == PDEATH)
		player_anim_death(game, p);
	else if (p->state == PSPIN)
		player_anim_spin(game, p);
	else if (p->state == PFAINT)
	{
		player_anim_faint(game, p);
		if (p->sprite->cur_spr >= PA_FAINT_S && p->sprite->cur_spr <= PA_FAINT_E)
			print_game_over(game, RED);
	}
	else if (game->player->state == PWAKE)
	{
		player_anim_wake(game, game->player);
	}
}
