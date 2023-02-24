/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:40:01 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/22 22:55:23 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

static int	get_text_xpm_pixel_color(t_xpm *xpm, t_vector pos, int color)
{
	char	token;
	int		i;

	token = xpm->spritesheet[pos.y][pos.x];
	i = -1;
	while (++i < xpm->pal_size)
	{
		if (xpm->token[i] == token)
		{
			if (xpm->palette[i] == BLACK)
				return (color);
			else
				return (xpm->palette[i]);
		}
	}
	return (WHITE);
}

static void	put_text_xpm_to_img(t_xpm *xpm, t_game *game, t_vector pos, int c)
{
	t_vector	posimg;
	t_vector	posxpm;
	int			color;

	posxpm.x = SPR_DIM * (xpm->cur_spr % xpm->spr_per_line) - 1;
	posxpm.y = SPR_DIM * (xpm->cur_spr / xpm->spr_per_line) - 1;
	if (posxpm.x + 1 > (SPR_DIM * (xpm->spr_per_line - 1))
		|| posxpm.y + 1 > (SPR_DIM * (xpm->spr_per_column - 1)))
		return ;
	posimg.x = pos.x - 1;
	posimg.y = pos.y - 1;
	while (++posimg.y < pos.y + SPR_DIM)
	{
		posxpm.y++;
		while (++posimg.x < pos.x + SPR_DIM)
		{
			posxpm.x++;
			if (posimg.x >= game->win_size.x)
				break ;
			color = get_text_xpm_pixel_color(xpm, posxpm, c);
			put_pixel_to_img(game, posimg, color);
		}
		posimg.x = pos.x - 1;
		posxpm.x = SPR_DIM * (xpm->cur_spr % xpm->spr_per_line) - 1;
	}
}

const static char	g_font[13] = ".,:\'\"!?()&$-"; // placement ?

void	put_char_to_img(char c, t_vector pos, t_game *game, int color)
{
	int		i;
	int		index;

	index = -1;
	if (c >= 'a' && c <= 'z')
		c -= 32;
	if (c >= 'A' && c <= 'Z')
		index = (int)c - 65;
	else if (c >= '0' && c <= '9')
		index = (int)c - 22;
	i = -1;
	if (index == -1)
		while (g_font[++i])
			if (c == g_font[i])
				index = i + 36;
	game->font->cur_spr = index;
	if (game->font->cur_spr > -1 && game->font->cur_spr < 48)
		put_text_xpm_to_img(game->font, game, pos, color);
}

void	put_str_to_img(char *s, t_vector pos, t_game *game, int color)
{
	int	ogx;
	int	i;

	ogx = pos.x;
	i = 0;
	while (s[i] && pos.y < game->win_size.y)
	{
		pos.x = ogx;
		while (s[i] && pos.x < game->win_size.x)
		{
			put_char_to_img(s[i++], pos, game, color);
			pos.x += SPR_DIM;
		}
		pos.y += SPR_DIM;
	}
}
