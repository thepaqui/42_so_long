/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:46:01 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/03 21:31:43 by thepaqui         ###   ########.fr       */
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
	"Can't collect all collectibles"
};

static void	puterr(const char *s)
{
	ft_putendl_fd(s, 2);
}

void	ft_error(int code, t_game *game)
{
	puterr("Error");
	if (code < LASTCODE)
		puterr(g_errmsg[code]);
	else
		puterr("Unknown error");
	free_game(game);
	exit(code);
}

void	errno_error(int code, t_game *game, char *file)
{
	puterr("Error");
	if (file)
	{
		ft_putendl_fd(file, 2);
		ft_putendl_fd(": ", 2);
	}
	puterr(strerror(code));
	free_game(game);
	exit(code);
}