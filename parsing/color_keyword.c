/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_keyword.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:56:32 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/11 21:53:40 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

const static char	*g_color_keyword[KEYWORD_NB] = {
	"None",
	"white",
	"black",
	"red",
	"green",
	"lime",
	"blue",
	"yellow",
	"cyan",
	"aqua",
	"fuschia",
	"magenta",
	"gray",
	"grey",
	"gold",
	"silver",
	"brown",
	"beige",
	"pink",
	"purple",
	"violet",
	"orange",
	"teal"
};

const static int	g_color_keyword_values[KEYWORD_NB] = {
	0xFF000000,
	0x00FFFFFF,
	0x00000000,
	0x00FF0000,
	0x0000FF00,
	0x0000FF00,
	0x000000FF,
	0x00FFFF00,
	0x0000FFFF,
	0x0000FFFF,
	0x00FF00FF,
	0x00FF00FF,
	0x00BEBEBE,
	0x00BEBEBE,
	0x00FFD700,
	0x00C0C0C0,
	0x00A52A2A,
	0x00F5F5DC,
	0x00FFC0CB,
	0x00A020F0,
	0x00EE82EE,
	0x00FFA500,
	0x00008080
};

int	is_keyword_valid(char *word)
{
	int	i;

	i = -1;
	while (++i < KEYWORD_NB)
		if (!ft_strncmp(word, g_color_keyword[i], ft_strlen(word)))
			return (1);
	return (0);
}

int	get_argb_from_keyword(char *word, int *err)
{
	int	i;

	i = -1;
	while (++i < KEYWORD_NB)
		if (!ft_strncmp(word, g_color_keyword[i], ft_strlen(word)))
			return (g_color_keyword_values[i]);
	*err = BADPALKEYWORD;
	return (0x00FFFFFF);
}
