/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:44:50 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/17 22:47:29 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

static void	key_move(int key, t_player *player)
{
	player->state = PMOVE;
	if (key == KEY_ARRUP && !player->down)
	{
		player->up = 1;
        player->sprite->cur_spr = 1;
	}
	if (key == KEY_ARRDO && !player->up)
	{
		player->down = 1;
        player->sprite->cur_spr = 2;
	}
	if (key == KEY_ARRLE && !player->right)
	{
		player->left = 1;
        player->sprite->cur_spr = 3;
	}
	if (key == KEY_ARRRI && !player->left)
	{
		player->right = 1;
        player->sprite->cur_spr = 4;
	}
}

int	handle_key_press(int key, t_game *game)
{
	//printf("KEY %i IS PRESSED\n", key); //-----------------------------------
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
        player->sprite->cur_spr = 1;
	else if (player->down)
        player->sprite->cur_spr = 2;
	else if (player->left)
        player->sprite->cur_spr = 3;
	else if (player->right)
        player->sprite->cur_spr = 4;
	else
		player->state = PIDLE;
	return ;
}

int	handle_key_release(int key, t_game *game)
{
	//printf("KEY %i IS RELEASED\n", key); //------------------------------------
	if (key >= KEY_ARRLE && key <= KEY_ARRUP)
		key_stop_move(key, game->player);
	return (0);
}