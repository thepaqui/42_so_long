/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritesheet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:36:59 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/17 18:44:25 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	check_sprites_format(char *sprites)
{
	int	i;

	if (sprites[0] != '\n')
		return (BADXPM);
	i = 0;
	while (sprites[i])
	{
		if (sprites[i] == '\"')
			if (ft_strncmp(&sprites[i], "\",\n\"", 4)
				&& ft_strncmp(&sprites[i], "\"\n};", 4)
				&& ft_strncmp(&sprites[i - 1], "\n\"", 2))
				return (BADXPM);
		i++;
	}
	if (sprites[i - 1] == '\n' && ft_strncmp(&sprites[i - 3], "};\n", 4))
		return (BADXPM);
	else if (sprites[i - 1] != '\n' && ft_strncmp(&sprites[i - 2], "};", 3))
		return (BADXPM);
	if (sprites[i - 1] == '\n')
		sprites[i - 1] = '\0';
	return (0);
}

static int	token_valid(char token, t_xpm *xpm)
{
	int	i;

	i = -1;
	while (++i < xpm->pal_size)
		if (token == xpm->token[i])
			return (1);
	return (0);
}

static int	clean_sprites(char *spr, t_xpm *xpm)
{
	int	i;

	i = ft_strlen(spr);
	if (spr[i - 1] == ';')
		spr[i - 1] = '\"';
	if (spr[i - 2] == '}')
		spr[i - 2] = '\"';
	i = -1;
	while (spr[++i])
	{
		while (spr[i] && spr[i] != '\n')
			i++;
		if (!spr[i])
			break ;
		if (i == 0 && spr[i + 1] == '\"')
			spr[i] = '\"';
		else if (!ft_strncmp(&spr[i - 2], "\",\n\"", 4)
			&& token_valid(spr[i - 3], xpm) && token_valid(spr[i + 2], xpm))
			spr[i - 1] = '\"';
		else if (!ft_strncmp(&spr[i - 1], "\"\n\"\"", 5))
			spr[i] = '\"';
		else
			return (BADXPM);
	}
	return (0);
}

static int	check_spritesheet(t_xpm *xpm)
{
	int	i;
	int	j;

	/*printf("Checking this spritesheet:\n"); //-------------------------------
	print_tab(xpm->spritesheet); //------------------------------------------*/
	i = -1;
	while (xpm->spritesheet[++i])
	{
		j = -1;
		while (xpm->spritesheet[i][++j])
			if (!token_valid(xpm->spritesheet[i][j], xpm))
				return (UNDEFTOKEN);
		if (j != SPR_DIM * xpm->spr_per_line)
			return (MISMATCHSPRDIM);
	}
	if (i != SPR_DIM * xpm->spr_per_column)
		return (MISMATCHSPRDIM);
	return (0);
}

int	get_spritesheet(t_xpm *xpm, char *sprites)
{
	int	err;

	err = check_sprites_format(sprites);
	if (!err)
		err = clean_sprites(sprites, xpm);
	if (!err)
	{
		xpm->spritesheet = ft_split(sprites, "\"\n");
		if (!xpm->spritesheet)
			return (MALLOCFAIL);
	}
	if (!err)
		err = check_spritesheet(xpm);
	return (err);
}