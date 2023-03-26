/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:51:11 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 17:11:36 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	ft_putchar_fd(const char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(const char *s, int fd)
{
	while (*s)
		ft_putchar_fd(*s++, fd);
}

void	ft_putendl_fd(const char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

int	isinset(char c, const char *set)
{
	if (!set)
		return (0);
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strdup(const char *str)
{
	char	*copy;
	size_t	size;

	if (!str)
		return (NULL);
	size = ft_strlen(str) + 1;
	copy = malloc(sizeof(*copy) * size);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, str, size);
	return (copy);
}
