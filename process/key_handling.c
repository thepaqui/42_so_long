/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:44:50 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/05 21:53:13 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "process.h"

static void	key_move(int key, t_game *game)
{
	if (key == KEY_ARRUP && !PDO)
		PUP = 1;
	if (key == KEY_ARRDO && !PUP)
		PDO = 1;
	if (key == KEY_ARRRI && !PLE)
		PRI = 1;
	if (key == KEY_ARRLE && !PRI)
		PLE = 1;
}

int	handle_key_press(int key, t_game *game)
{
	printf("KEY %i IS PRESSED\n", key); //-
	if (key == KEY_ESC)
		close_window(game, 0, NULL);
	if (key >= KEY_ARRLE && key <= KEY_ARRUP)
		key_move(key, game);
	return (0);
}

static void	key_stop_move(int key, t_game *game)
{
	if (key == KEY_ARRUP)
		PUP = 0;
	if (key == KEY_ARRDO)
		PDO = 0;
	if (key == KEY_ARRRI)
		PRI = 0;
	if (key == KEY_ARRLE)
		PLE = 0;
}

int	handle_key_release(int key, t_game *game)
{
	printf("KEY %i IS RELEASED\n", key); //-
	if (key >= KEY_ARRLE && key <= KEY_ARRUP)
		key_stop_move(key, game);
	return (0);
}