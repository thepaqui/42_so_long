/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:20:37 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/12 15:57:31 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	color_code_to_argb(char *code, int *err)
{
	if (code[0] == '0')
	{
		str_toupper(&code[2]);
		return (ft_atoi_base(&code[2], "0123456789ABCDEF"));
	}
	else if (code[0] == '#')
	{
		str_toupper(&code[1]);
		return (ft_atoi_base(&code[1], "0123456789ABCDEF"));
	}
	else
	{
		str_toupper(code);
		return (get_argb_from_keyword(code, err));
	}
}

int	get_colors(char **tab, t_xpm *xpm)
{
	int	i;
	int	err;

	xpm->palette = ft_calloc(xpm->pal_size, sizeof(int));
	if (!xpm->palette)
		return (MALLOCFAIL);
	i = 0;
	err = 0;
	while (tab[++i])
	{
		xpm->palette[i - 1] = color_code_to_argb(&tab[i][4], &err);
		if (err)
			return (err);
	}
	return (0);
}

int	get_tokens(char **tab, t_xpm *xpm)
{
	int	i;

	xpm->token = ft_calloc(xpm->pal_size, sizeof(char));
	if (!xpm->token)
		return (MALLOCFAIL);
	i = 0;
	while (tab[++i])
		xpm->token[i - 1] = tab[i][0];
	return (0);
}