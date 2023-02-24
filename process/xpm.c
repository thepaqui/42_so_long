/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:10:42 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/22 22:54:58 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

static int	get_xpm_pixel_color(t_xpm *xpm, t_vector pos)
{
	char	token;
	int		i;

	token = xpm->spritesheet[pos.y][pos.x];
	i = -1;
	while (++i < xpm->pal_size)
		if (xpm->token[i] == token)
			return (xpm->palette[i]);
	return (WHITE);
}

void	put_t_xpm_to_img(t_xpm *xpm, t_game *game, t_vector pos)
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
			color = get_xpm_pixel_color(xpm, posxpm);
			put_pixel_to_img(game, posimg, color);
		}
		posimg.x = pos.x - 1;
		posxpm.x = SPR_DIM * (xpm->cur_spr % xpm->spr_per_line) - 1;
	}
}
