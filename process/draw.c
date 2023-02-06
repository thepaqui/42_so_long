/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:47:55 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/06 15:21:43 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "process.h"
#include <stdio.h>//--------------------------------------

void	put_pixel_to_img(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->add + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	put_background_color_to_img(t_img *img, int color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WINHEI - 1)
	{
		x = -1;
		while (++x < WINWID - 1)
			put_pixel_to_img(img, x, y, color);
	}
}

void	draw_player(t_game *game)
{
	put_pixel_to_img(IMG, XPLAYER, YPLAYER, BLACK);
}
