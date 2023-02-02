/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:46:01 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/02 18:44:20 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../sl.h"

static void	puterr(char *s)
{
	ft_putendl_fd(s, 2);
}

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
};

void	ft_error(int code, t_game *game)
{
	puterr("Error");
	if (code < LASTCODE)
		puterr(g_errmsg[code]);
	else
		puterr("Unknown error");
	// free game
	exit(code);
}

void	errno_error(int code, t_game *game)
{
	puterr("Error");
	strerror(code);
	// free game
	exit(code);
}
