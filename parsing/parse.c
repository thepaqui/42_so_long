/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:18:41 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/02 17:52:17 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parse.h"

static int	open_mapfile(char *file)
{
	int	fd;

	errno = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		errno_error(errno, NULL);
	return (fd);
}

static void	close_mapfile(int fd)
{
	errno = 0;
	if (close(fd) == -1);
		errno_error(errno, NULL);
}

static int	count_lines(int fd)
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
		errno_error(errno, NULL);
	else
		return (cnt);
}

static char	**map(int fd, int lines)
{
	char	**map;
	int		i;
	int		*gnlerr;

	map = ft_calloc(lines + 1, sizeof(char *));
	if (!map)
		ft_error(MALLOCFAIL, NULL);
	i = 0;
	*gnlerr = 0;
	map[i] = get_next_line(fd, gnlerr);
	while (map[i] && ++i < lines)
	{
		*gnlerr = 0;
		map[i] = get_next_line(fd, gnlerr);
	}
	if (i == lines)
		return (map)
	ft_free_tab(map, -1);
	errno_error(*gnlerr, NULL);
	return (NULL);
}

char	**get_map(char *file)
{
	int		fd;
	int		lines;
	char	**map;

	fd = open_mapfile(file);
	lines = count_lines(fd);
	close_mapfile(fd);
	fd = open_mapfile(file);
	map = map(fd, lines);
	if (!map)
		ft_error(MALLOCFAIL, NULL);
	return (map);
}
