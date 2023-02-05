/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:18:41 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/05 18:11:41 by thepaqui         ###   ########.fr       */
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
		errno_error(errno, game);
	return (fd);
}

static void	close_mapfile(int fd, t_game *game)
{
	errno = 0;
	if (close(fd) == -1)
		errno_error(errno, game);
}

static int	count_lines(int fd, t_game *game)
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
		errno_error(errno, game);
	return (cnt);
}

static void	take_map(int fd, int lines, t_game *game)
{
	int	i;
	int	gnlerr;

	MAPMAP = ft_calloc(lines + 1, sizeof(char *));
	if (!MAPMAP)
		ft_error(MALLOCFAIL, game);
	i = 0;
	gnlerr = 0;
	MAPMAP[i] = get_next_line(fd, &gnlerr);
	while (MAPMAP[i] && ++i < lines)
	{
		gnlerr = 0;
		MAPMAP[i] = get_next_line(fd, &gnlerr);
	}
	if (gnlerr)
		errno_error(gnlerr, game);
}

void	get_map(char *file, t_game *game)
{
	int	fd;
	int	lines;

	fd = open_mapfile(file, game);
	lines = count_lines(fd, game);
	close_mapfile(fd, game);
	fd = open_mapfile(file, game);
	take_map(fd, lines, game);
	if (!MAPMAP)
		ft_error(MALLOCFAIL, game);
}
