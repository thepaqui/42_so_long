/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:14:06 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/03 18:58:19 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strndup(const char *str, int n)
{
	char	*copy;
	int		i;

	if (!str)
		return (NULL);
	copy = ft_calloc(n + 1, sizeof(char));
	if (!copy)
		return (NULL);
	i = -1;
	while (str[++i] && i < n)
		copy[i] = str[i];
	copy[i] = '\0';
	return (copy);
}
