/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:57:00 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/09 15:13:06 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include <stdio.h> //--------------------------------------------------

static void	debug(t_game *game, int silent)
{
	if (silent)
		return ;
	printf("Player position (%d,%d)\n", XPLAYER, YPLAYER);
}

static int	main_loop(t_game *game)
{
	debug(game, 1); //-----------------------------------
	update_player(game);
	prepare_new_frame(game);
	//display_new_frame(game);
	return (0);
}

void	launch_game(t_game *game)
{
	MLX = mlx_init();
	open_window(game);
	IMGIMG = mlx_new_image(MLX, WINWID, WINHEI);
	IMGADD = mlx_get_data_addr(IMGIMG, &IMGBPP, &IMGLLEN, &IMGENDI);
	XPLAYER = WINWID / 2;
	YPLAYER = WINHEI / 2;
	mlx_loop_hook(MLX, main_loop, game);
	mlx_hook(WIN, ON_KEYDOWN, 0, handle_key_press, game);
	mlx_hook(WIN, ON_KEYUP, 0, handle_key_release, game);
	mlx_loop(MLX);
}
