/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:46:01 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/11 20:16:01 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

const static char	*g_errmsg[LASTCODE] = {
	"Invalid error code 0 shouldn't be printed",
	"No arguments",
	"Too many arguments",
	"Path is empty",
	"Map has no extension",
	"Map doesn't have .ber extension",
	"Memory allocation failed",
	"Invalid character(s) in map",
	"No start in map",
	"Too many starts in map",
	"No exit in map",
	"Too many exits in map",
	"No collectibles in map",
	"Map is not a rectangle",
	"Map is not surrounded by walls",
	"Exit is not reachable",
	"Can't collect all collectibles",
	"Not a .xpm file",
	"Invalid XPM file",
	"Not enough XPM info",
	"Too much XPM info ^^\'",
	"Invalid sprite dimensions, see SPRITE_DIM in srcs/game.h",
	"Wrong chars-per-pixel value (should be 1)",
	"Inconsistent palette size",
	"Invalid palette color token",
	"Invalid palette formatting",
	"Invalid palette color (hex code)",
	"Invalid palette color (keyword)"
};

static void	puterr(const char *s)
{
	ft_putendl_fd(s, 2);
}

void	ft_error(int code, t_game *game, char *file)
{
	puterr("Error");
	code *= -1;
	if (file)
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": ", 2);
	}
	if (code < LASTCODE)
		puterr(g_errmsg[code]);
	else
		puterr("Unknown error");
	free_game(game);
	system("leaks so_long | grep leak"); //-----------------------------------
	exit(code);
}

void	errno_error(int code, t_game *game, char *file)
{
	puterr("Error");
	if (file)
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": ", 2);
	}
	puterr(strerror(code));
	free_game(game);
	system("leaks so_long | grep leak"); //-----------------------------------
	exit(code);
}

void	error_handling(int code, t_game *game, char *file)
{
	if (code < 0)
		ft_error(code, game, file);
	else if (code > 0)
		errno_error(code, game, file);
	else
		ft_error(0, game, file);
}