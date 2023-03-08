/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:03:18 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/24 18:03:20 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

static char	**clean_split(char *s)
{
	char	**ret;
	int		i;

	i = -1;
	while (s[++i])
		if (s[i] == ',' && s[i + 1] == '\n')
			s[i] = '\"';
	ret = ft_split(s, "\n\"");
	if (!ret)
		return (NULL);
	return (ret);
}

static int	check_hex_color(char *hex, int start, int end)
{
	while (hex[++start])
		if (!isinset(hex[start], "0123456789abcdefABCDEF"))
			return (BADPALCOLOR);
	if (start != end)
		return (BADPALCOLOR);
	return (0);
}

static int	check_pal_format(char **tab)
{
	int	i;

	i = 0;
	while (tab[++i])
	{
		if (tab[i][0] == 127 || tab[i][0] == '\n' || tab[i][0] < 9
			|| (tab[i][0] > 13 && tab[i][0] < ' '))
			return (BADPALTOKEN);
		if (tab[i][1] != ' ' || tab[i][2] != 'c' || tab[i][3] != ' ')
			return (BADPALFORM);
		if (tab[i][4] == '0' && (tab[i][5] == 'x' || tab[i][5] == 'X'))
		{
			if (check_hex_color(tab[i], 5, 14))
				return (check_hex_color(tab[i], 5, 14));
		}
		else if (tab[i][4] == '#')
		{
			if (check_hex_color(tab[i], 4, 11))
				return (check_hex_color(tab[i], 4, 11));
		}
		else if (!is_keyword_valid(&tab[i][4]))
			return (BADPALKEYWORD);
	}
	return (0);
}

static int	check_tokens(char *tokens, int pal_size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < pal_size)
	{
		j = i;
		while (++j < pal_size)
			if (tokens[i] == tokens[j])
				return (DOUBLEPALTOKEN);
	}
	return (0);
}

int	get_palette(t_xpm *xpm, char *raw_pal)
{
	int		err;
	char	**tab;

	tab = clean_split(raw_pal);
	if (!tab)
		return (MALLOCFAIL);
	err = check_pal_format(tab);
	if (!err)
		err = get_tokens(tab, xpm);
	if (!err)
		err = get_colors(tab, xpm);
	if (!err)
		err = check_tokens(xpm->token, xpm->pal_size);
	ft_free_tab(tab, -1);
	return (err);
}
