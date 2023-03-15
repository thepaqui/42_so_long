/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:44:50 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/15 06:01:06 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

static void	key_move(int key, t_player *player)
{
	if (player->state != PTHROW)
		player->state = PMOVE;
	if (key == KEY_W && !player->down)
		player->up = 1;
	if (key == KEY_S && !player->up)
		player->down = 1;
	if (key == KEY_A && !player->right)
	{
		player->last_key = key;
		player->left = 1;
	}
	if (key == KEY_D && !player->left)
	{
		player->last_key = key;
		player->right = 1;
	}
}

int	handle_key_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		game->state = GAME_STOP;
	else if (game->state != GAME_RUN)
		return (0);
	else if ((key >= KEY_A && key <= KEY_D) || key == KEY_W)
		key_move(key, game->player);
	return (0);
}

static void	key_stop_move(int key, t_player *player)
{
	if (key == KEY_W)
		player->up = 0;
	if (key == KEY_S)
		player->down = 0;
	if (key == KEY_A)
		player->left = 0;
	if (key == KEY_D)
		player->right = 0;
	else if (player->left)
		player->last_key = KEY_A;
	else if (player->right)
		player->last_key = KEY_D;
	else if (player->state != PTHROW)
		player->state = PIDLE;
	return ;
}

int	handle_key_release(int key, t_game *game)
{
	if (game->state != GAME_RUN)
		return (0);
	if ((key >= KEY_A && key <= KEY_D) || key == KEY_W)
		key_stop_move(key, game->player);
	return (0);
}
