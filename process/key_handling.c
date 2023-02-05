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
	if (key == KEY_ARRUP && YPLAYER > 0)
		YPLAYER--;
	else if (key == KEY_ARRDO && YPLAYER < WINHEI - 1)
		YPLAYER++;
	else if (key == KEY_ARRRI && XPLAYER < WINWID - 1)
		XPLAYER++;
	else if (key == KEY_ARRLE && XPLAYER > 0)
		XPLAYER--;
}

int	handle_key_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		close_window(game, 0);
	if (key >= KEY_ARRLE && key <= KEY_ARRUP)
		key_move(key, game);
	return (0);
}
