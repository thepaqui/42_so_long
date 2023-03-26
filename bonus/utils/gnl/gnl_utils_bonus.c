/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:35:13 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 14:32:29 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils_bonus.h"

static size_t	ft_strlcat_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (!dst && !dstsize)
		return (0);
	i = 0;
	j = 0;
	while (dst[i] && i < dstsize)
		i++;
	if (!src)
		return (i);
	len = i + ft_strlen(src);
	while (src[j] && i + 1 < dstsize)
		dst[i++] = src[j++];
	if (dstsize > i)
		dst[i] = 0;
	return (len);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char	*dst;
	size_t	dst_size;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1)
		return (NULL);
	dst_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = ft_calloc(dst_size, sizeof(char));
	if (!dst)
	{
		free(s1);
		return (dst);
	}
	if (dst_size > 1)
	{
		ft_strlcat_gnl(dst, s1, dst_size);
		ft_strlcat_gnl(dst, s2, dst_size);
	}
	free(s1);
	return (dst);
}
