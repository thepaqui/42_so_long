/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:03:18 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/11 23:10:08 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static char	**clean_split(char *s)
{
	char	**ret;
	char	*tmp;
	int		i;

	ret = ft_split(s, "\n\",");
	if (!ret)
		return (NULL);
	i = -1;
	while (ret[++i])
	{
		if (ret[i][0] == ' ' && ret[i][1] == 'c')
		{
			tmp = ft_calloc(ft_strlen(ret[i]) + 2, sizeof(char));
			if (!tmp)
				return (ft_free_tab(ret, -1));
			tmp[0] = ',';
			ft_strlcat_gnl(tmp, ret[i], (size_t)ft_strlen(ret[i]) + 2);
			free(ret[i]);
			ret[i] = tmp;
			break ;
		}
	}
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
		if (tab[i][0] == 127 || tab[i][0] < 9
			|| (tab[i][0] > 13 && tab[i][0] < 32))
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

int	get_palette(t_xpm *xpm, char *raw_pal)
{
	int		err;
	char	**tab;

	//printf("Raw palette is \"%s\"\n", raw_pal); //--------------------------
	tab = clean_split(raw_pal);
	if (!tab)
		return (MALLOCFAIL);
	/*for (int i = 0;tab[i];i++) { //-----------------------------------------
		if (tab[i][1] != '\0') //---------------------------------------------
			printf("tab[%i] = \"%s\"\n", i, tab[i]); //-----------------------
	} //--------------------------------------------------------------------*/
	err = check_pal_format(tab); // "%c c (%x/%s)" also check keywords
	if (!err)
		err = get_tokens(tab, xpm);
	if (!err)
		err = get_colors(tab, xpm);
	for (int i = 0;i < xpm->pal_size;i++) { //---------------------------------------
		printf("COLOR %i:\t%c - 0x%08X\n", i, xpm->token[i], xpm->palette[i]); //---------
	} //-----------------------------------------------------------------------------
	/*if (!err)
		err = check_palette(tab, xpm);*/
	ft_free_tab(tab, -1);
	return (err);
}
