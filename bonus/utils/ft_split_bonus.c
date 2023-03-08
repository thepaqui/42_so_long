/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:33:54 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/24 18:04:30 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

static int	ft_strcount(char const *str, const char *set)
{
	int	i;
	int	str_len;
	int	str_count;

	str_count = 0;
	str_len = 0;
	i = 0;
	while (str[i])
	{
		if (isinset((int)str[i], set))
		{
			if (str_len > 0)
			{
				str_count++;
				str_len = 0;
			}
		}
		else
			str_len++;
		i++;
	}
	if (str_len > 0)
		str_count++;
	return (str_count);
}

char	**ft_split(const char *s, const char *set)
{
	char	**tab;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	tab = ft_calloc((ft_strcount(s, set) + 1), sizeof(char *));
	if (!tab)
		return (0);
	i = 0;
	j = 0;
	while (i < ft_strcount(s, set) && s[j])
	{
		while (isinset((int)s[j], set))
			j++;
		tab[i] = ft_calloc((ft_strclen(&s[j], set) + 1), sizeof(char));
		if (!tab[i])
			return (ft_free_tab(tab, i));
		ft_strlcpy(tab[i++], &s[j], ft_strclen(&s[j], set) + 1);
		while (s[j] && !isinset(s[j], set))
			j++;
	}
	tab[i] = NULL;
	return (tab);
}
