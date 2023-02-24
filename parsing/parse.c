/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:18:41 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/22 23:00:19 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdio.h> //---------------------------------------------------------

static int	open_mapfile(char *file, t_game *game)
{
	int	fd;

	errno = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		errno_error(errno, game, file);
	return (fd);
}

static void	close_mapfile(int fd, t_game *game, char *file)
{
	errno = 0;
	if (close(fd) == -1)
		errno_error(errno, game, file);
}

static int	count_lines(int fd, t_game *game, char *file)
{
	int		cnt;
	int		bytes;
	char	buf[1];

	cnt = 1;
	errno = 0;
	bytes = read(fd, buf, 1);
	while (bytes == 1)
	{
		if (buf[0] == '\n')
			cnt++;
		errno = 0;
		bytes = read(fd, buf, 1);
	}
	if (bytes == -1)
		errno_error(errno, game, file);
	return (cnt);
}

static void	take_map(int fd, int lines, t_game *game, char *file)
{
	int	i;
	int	gnlerr;

	game->map->map = ft_calloc(lines + 1, sizeof(char *));
	if (!game->map->map)
		ft_error(MALLOCFAIL, game, NULL);
	i = 0;
	gnlerr = 0;
	game->map->map[i] = get_next_line(fd, &gnlerr);
	while (game->map->map[i] && ++i < lines)
	{
		gnlerr = 0;
		game->map->map[i] = get_next_line(fd, &gnlerr);
	}
	if (gnlerr)
		errno_error(gnlerr, game, file);
}

void	get_map(char *file, t_game *game)
{
	int	fd;
	int	lines;

	fd = open_mapfile(file, game);
	lines = count_lines(fd, game, file);
	close_mapfile(fd, game, file);
	fd = open_mapfile(file, game);
	take_map(fd, lines, game, file);
	if (!game->map->map)
		ft_error(MALLOCFAIL, game, NULL);
}
