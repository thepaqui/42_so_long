/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:27:08 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 18:11:15 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void	close_window(t_game *game, int code, char *file)
{
	mlx_destroy_window(game->mlx, game->win);
	game->win = NULL;
	if (code)
		error_handling(code, game, file);
	free_game(game);
	exit(code);
}

int	handle_cross(t_game *game)
{
	game->state = GAME_STOP;
	return (0);
}

void	open_window(t_game *game)
{
	t_vector	s;

	s.x = game->win_size.x;
	s.y = game->win_size.y;
	game->win = mlx_new_window(game->mlx, s.x, s.y, WINNAME);
	mlx_hook(game->win, ON_DESTROY, 0, handle_cross, game);
}
