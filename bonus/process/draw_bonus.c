/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:47:55 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/25 17:40:13 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"
#include <stdio.h>//--------------------------------------

static void	put_pixel_to_img_help(t_img *img, t_vector pos, int color)
{
	char		*dst;

	dst = img->add + (pos.y * img->line_len + pos.x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static int	get_img_pixel_color(t_img *img, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = img->add + (y * img->line_len + x * (img->bpp / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

void	put_pixel_to_img(t_game *game, t_vector pos, int color)
{
	if (pos.x > game->win_size.x - 1 || pos.y > game->win_size.y - 1
		|| get_alpha(color) == 0xFF)
		return ;
	else if (color == get_img_pixel_color(game->image, pos.x, pos.y))
		return ;
	else
		put_pixel_to_img_help(game->image, pos, color);
}

void	put_background_color_to_img(t_game *game, int color)
{
	t_vector	pos;

	pos.y = -1;
	while (++pos.y < game->win_size.y - 1)
	{
		pos.x = -1;
		while (++pos.x < game->win_size.x - 1)
			put_pixel_to_img(game, pos, color);
	}
}
