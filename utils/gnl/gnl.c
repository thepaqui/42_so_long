/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:08:51 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/03 15:21:20 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../utils.h"

static int	ft_str_has_nl(char *s)
{
	if (!s)
		return (0);
	while (*s)
		if (*s++ == '\n')
			return (1);
	return (0);
}

static char	*ft_ret_line(char *buf, char *leftover, int nb_bytes)
{
	if (buf)
		free(buf);
	if (nb_bytes == -1)
	{
		if (leftover)
		{
			free(leftover);
			leftover = NULL;
		}
		return (NULL);
	}
	if (!nb_bytes && leftover && !leftover[0])
	{
		free(leftover);
		leftover = NULL;
		return (NULL);
	}
	return (leftover);
}

static char	*ft_read_fd(int fd, char *leftover)
{
	char	*buf;
	int		nb_bytes;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	nb_bytes = read(fd, buf, BUFFER_SIZE);
	if (nb_bytes <= 0)
		return (ft_ret_line(buf, leftover, nb_bytes));
	buf[nb_bytes] = '\0';
	leftover = ft_strjoin_gnl(leftover, buf);
	if (!leftover)
		return (ft_ret_line(buf, leftover, nb_bytes));
	while (nb_bytes && leftover && !ft_str_has_nl(leftover))
	{
		nb_bytes = read(fd, buf, BUFFER_SIZE);
		if (nb_bytes == -1)
			return (ft_ret_line(buf, leftover, nb_bytes));
		buf[nb_bytes] = '\0';
		leftover = ft_strjoin_gnl(leftover, buf);
		if (!leftover)
			return (ft_ret_line(buf, leftover, nb_bytes));
	}
	return (ft_ret_line(buf, leftover, nb_bytes));
}

static char	*ft_split_leftover(char **leftover)
{
	char	*tmp;
	char	*ret;
	int		i;

	if (!ft_str_has_nl(*leftover))
	{
		ret = ft_strndup(*leftover, ft_strlen(*leftover));
		free(*leftover);
		*leftover = ft_strndup("\0", 1);
		return (ret);
	}
	tmp = *leftover;
	i = 0;
	while (tmp[i] != '\n')
		i++;
	ret = ft_strndup(tmp, i + 1);
	if (!ret)
		return (ft_ret_line(tmp, ret, -1));
	*leftover = ft_strndup(tmp + i + 1, ft_strlen(tmp + i + 1));
	if (!*leftover)
		return (ft_ret_line(tmp, ret, -1));
	return (ft_ret_line(tmp, ret, 1));
}

char	*get_next_line(int fd, int *err)
{
	static char	*leftover[FD_SETSIZE];
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) == -1)
	{
		*err = errno;
		if (leftover[fd])
		{
			free(leftover[fd]);
			leftover[fd] = NULL;
		}
		return (NULL);
	}
	leftover[fd] = ft_read_fd(fd, leftover[fd]);
	if (!leftover[fd])
		return (NULL);
	ret = ft_split_leftover(&leftover[fd]);
	return (ret);
}
