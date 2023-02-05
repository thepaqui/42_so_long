/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 13:37:30 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/05 21:53:15 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "process.h"

static void	put_pixel_to_img(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->add + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void	solid_color_img(t_img *img, int color)
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

static void	push_buffer_to_img(t_game *game)
{
	t_img	*tmp;

	tmp = IMG;
	IMG = BIMG;
	BIMG = tmp;
}

void	prepare_new_frame(t_game *game)
{
	int	x;
	int	y;

	x = XPLAYER;
	y = YPLAYER;
	solid_color_img(BIMG, BLACK);
	put_pixel_to_img(BIMG, x, y, WHITE);
	push_buffer_to_img(game);
	mlx_put_image_to_window(MLX, WIN, IMGIMG, 0, 0);
}
