/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:21:13 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/09 18:50:27 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int	is_file_type(char *path, char *ext)
{
	int	len;
	int	dot;
	int	i;

	len = ft_strlen(path);
	if (!len)
		return (NOPATH);
	dot = len;
	while (dot && path[dot] != '.' && path[dot] != '/')
		dot--;
	if (path[dot] != '.' || dot == 0)
		return (NOEXT);
	i = -1;
	while (ext[++i])
		if (ext[i] != path[dot + 1 + i])
		{
			if (!ft_strncmp(ext, "ber", 3))
				return (NOTBER);
			else
				return (NOTXPM);
		}
	return (0);
}

void	check_input(int ac, char **av, int *err)
{
	if (ac < 2)
		*err = TOOFEWARGS;
	else if (ac > 2)
		*err = TOOMANYARGS;
	if (!*err)
		*err = is_file_type(av[1], "ber");
}
