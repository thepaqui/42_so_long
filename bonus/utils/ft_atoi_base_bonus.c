/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:00:42 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/24 18:04:28 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

static char	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

void	str_toupper(char *s)
{
	while (*s)
	{
		*s = ft_toupper(*s);
		s++;
	}
}

static int	ft_is_base_valid(char *base)
{
	int	i;
	int	j;
	int	base_len;

	i = 0;
	j = 1;
	base_len = ft_strlen(base);
	if (base_len <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
			if (base[j++] == base[i])
				return (0);
		i++;
	}
	return (1);
}

static int	ft_is_char_in_base(char nb, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == nb)
			return (i);
		else
			i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	i;
	int	sign;
	int	base_len;

	if (ft_is_base_valid(base) == 0)
		return (0);
	i = 0;
	res = 0;
	sign = 0;
	base_len = ft_strlen(base);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign++;
	}
	while (str[i] && isinset(str[i], base))
		res = res * base_len + ft_is_char_in_base(str[i++], base);
	if (sign % 2 == 1)
		res = -res;
	return (res);
}
