/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:14:06 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/09 15:32:13 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "utils.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

int	ft_strclen(const char *str, const char *set)
{
	int	i;

	if (!str)
		return (0);
	if (!set || !*set)
		return (ft_strlen(str));
	i = 0;
	while (str[i] && !isinset((int)str[i], set))
		i++;
	return (i);
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

int	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int	i;
	int	j;

	if (!dst && !dstsize)
		return (0);
	if (!src)
		return (dstsize);
	i = ft_strlen(src);
	if (!dst)
		return (i);
	j = 0;
	if (i + 1 < dstsize)
	{
		while (j < i + 1)
		{
			dst[j] = src[j];
			j++;
		}
	}
	else if (dstsize > 0)
	{
		while (j < dstsize - 1)
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = '\0';
	}
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	if ((!s1 && !s2) || !n)
		return (0);
	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
	}
	return (0);
}
