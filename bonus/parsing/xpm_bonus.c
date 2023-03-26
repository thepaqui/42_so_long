/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:10:42 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/25 20:40:04 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

static t_xpm	*parse_xpm_text_to_struct(char *xpm, int *err)
{
	t_xpm	*ret;
	char	**split;

	split = NULL;
	ret = ft_calloc(1, sizeof(t_xpm));
	if (!ret)
		*err = MALLOCFAIL;
	if (!*err)
		split = ft_split(xpm, "/");
	if (!split)
		*err = MALLOCFAIL;
	if (!*err)
		*err = check_xpm(split, ret);
	if (!*err)
		*err = get_palette(ret, split[3]);
	if (!*err)
		*err = get_spritesheet(ret, split[5]);
	if (split)
		split = ft_free_tab(split, -1);
	if (*err && ret)
		ret = free_xpm(ret);
	return (ret);
}

static char	*error_open_xpm(int *err, int errcode, int fd, char *text)
{
	*err = errcode;
	if (fd != -1)
		close(fd);
	if (text)
	{
		free(text);
		text = NULL;
	}
	return (NULL);
}

static int	get_xpm_buffer_size(char *file)
{
	int		fd;
	int		ret;
	int		res;
	char	buf[BUFSIZE];

	errno = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	errno = 0;
	res = 0;
	ret = read(fd, buf, BUFSIZE);
	while (ret > 0)
	{
		res += ret;
		ret = read(fd, buf, BUFSIZE);
	}
	close(fd);
	if (!res || ret == -1)
		return (-1);
	else
		return (res + 5);
}

static char	*open_xpm_file(char *file, int *err)
{
	int		fd;
	int		read_ret;
	char	*text;
	int		size;

	size = get_xpm_buffer_size(file);
	if (size == -1)
		return (error_open_xpm(err, errno, -1, NULL));
	text = ft_calloc(size, sizeof(char));
	if (!text)
		return (error_open_xpm(err, MALLOCFAIL, -1, NULL));
	errno = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (error_open_xpm(err, errno, -1, text));
	errno = 0;
	read_ret = read(fd, text, size);
	if (read_ret <= 0)
		return (error_open_xpm(err, errno, fd, text));
	text[read_ret] = '\0';
	close(fd);
	return (text);
}

t_xpm	*parse_xpm(char *file, int *err)
{
	char		*text;
	t_xpm		*xpm;

	*err = is_file_type(file, "xpm");
	if (*err)
		return (NULL);
	text = open_xpm_file(file, err);
	if (!text)
		return (NULL);
	xpm = parse_xpm_text_to_struct(text, err);
	free(text);
	return (xpm);
}
