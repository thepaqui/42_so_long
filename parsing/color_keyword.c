/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_keyword.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:56:32 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/11 19:27:00 by thepaqui         ###   ########.fr       */
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

enum	e_color_keyword {
	None = 0xFF000000,
	white = 0x00FFFFFF,
	black = 0x00000000,
	red = 0x00FF0000,
	green = 0x0000FF00,
	lime = 0x0000FF00,
	blue = 0x000000FF,
	yellow = 0x00FFFF00,
	cyan = 0x0000FFFF,
	aqua = 0x0000FFFF,
	fuschia = 0x00FF00FF,
	magenta = 0x00FF00FF,
	gray = 0x00BEBEBE,
	grey = 0x00BEBEBE,
	gold = 0x00FFD700,
	silver = 0x00C0C0C0,
	brown = 0x00A52A2A,
	beige = 0x00F5F5DC,
	pink = 0x00FFC0CB,
	purple = 0x00A020F0,
	violet = 0x00EE82EE,
	orange = 0x00FFA500,
	teal = 0x00008080
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
