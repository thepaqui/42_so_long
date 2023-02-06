/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:27:08 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/05 20:16:41 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "process.h"

void	close_window(t_game *game, int code, char *file)
{
	mlx_destroy_window(MLX, WIN);
	WIN = NULL;
	if (code)
		errno_error(code, game, file);
	free_game(game);
	system("leaks so_long | grep leaks"); //---------------------------------
	exit(code);
}

int	handle_cross(t_game *game)
{
	close_window(game, 0, NULL);
	return (0);
}

void	open_window(t_game *game)
{
	WIN = mlx_new_window(MLX, WINWID, WINHEI, WINNAME);
	mlx_hook(WIN, ON_DESTROY, 0, handle_cross, game);
}
