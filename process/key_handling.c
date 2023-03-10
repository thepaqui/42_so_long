/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:44:50 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/24 16:58:10 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

static void	key_move(int key, t_player *player)
{
	player->state = PMOVE;
	if (key == KEY_ARRUP && !player->down)
	{
		player->last_key = key;
		player->up = 1;
	}
	if (key == KEY_ARRDO && !player->up)
	{
		player->last_key = key;
		player->down = 1;
	}
	if (key == KEY_ARRLE && !player->right)
	{
		player->last_key = key;
		player->left = 1;
	}
	if (key == KEY_ARRRI && !player->left)
	{
		player->last_key = key;
		player->right = 1;
	}
}

int	handle_key_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		game->state = GAME_STOP;
	if (key >= KEY_ARRLE && key <= KEY_ARRUP)
		key_move(key, game->player);
	return (0);
}

static void	key_stop_move(int key, t_player *player)
{
	if (key == KEY_ARRUP)
		player->up = 0;
	if (key == KEY_ARRDO)
		player->down = 0;
	if (key == KEY_ARRLE)
		player->left = 0;
	if (key == KEY_ARRRI)
		player->right = 0;
	if (player->up)
		player->last_key = KEY_ARRUP;
	else if (player->down)
		player->last_key = KEY_ARRDO;
	else if (player->left)
		player->last_key = KEY_ARRLE;
	else if (player->right)
		player->last_key = KEY_ARRRI;
	else
		player->state = PIDLE;
	return ;
}

int	handle_key_release(int key, t_game *game)
{
	if (key >= KEY_ARRLE && key <= KEY_ARRUP)
		key_stop_move(key, game->player);
	return (0);
}
