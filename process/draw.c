/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:47:55 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/17 19:07:03 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include <stdio.h>//--------------------------------------

static void	put_pixel_to_img_help(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->add + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static int	get_img_pixel_color(t_img *img, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = img->add + (y * img->line_len + x * (img->bits_per_pixel / 8));
	color = *(unsigned int*)pixel;
	return (color);
}

void	put_pixel_to_img(t_game *game, t_vector pos, int color)
{
	if (pos.x > WINWID - 1 || pos.y > WINHEI - 1 || get_alpha(color) == 0xFF)
		return ;
	else if (color == get_img_pixel_color(game->image, pos.x, pos.y))
		return ;
	else
		put_pixel_to_img_help(game->image, pos.x, pos.y, color);
}

void	put_background_color_to_img(t_game *game, int color)
{
	t_vector	pos;

	pos.y = -1;
	while (++pos.y < WINHEI - 1)
	{
		pos.x = -1;
		while (++pos.x < WINWID - 1)
			put_pixel_to_img(game, pos, color);
	}
}

void	draw_player(t_game *game)
{
	put_t_xpm_to_img(game->player->sprite, game, game->player->pos);
}
