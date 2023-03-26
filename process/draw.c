/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:47:55 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/25 17:24:50 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

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

static int	get_opacity(int og, int col)
{
	int	a;
	int	r;
	int	g;
	int	b;

	a = get_alpha(col);
	r = get_red(og) - a;
	g = get_green(og) - a;
	b = get_blue(og) - a;
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	return (get_argb(0, r, g, b));
}

void	put_pixel_to_img(t_game *game, t_vector pos, int color)
{
	int	ogcolor;

	ogcolor = get_img_pixel_color(game->image, pos.x, pos.y);
	if ((get_alpha(color) & 0xFF) != 0 && (get_alpha(color) & 0xFF) != 0xFF)
		color = get_opacity(ogcolor, color);
	if (pos.x >= game->win_size.x - 1 || pos.y >= game->win_size.y - 1
		|| get_alpha(color) == 0xFF || color == ogcolor)
		return ;
	else
		put_pixel_to_img_help(game->image, pos, color);
}

void	put_background_color_to_img(t_game *game, int color)
{
	t_vector	pos;

	pos.y = -1;
	while (++pos.y < game->win_size.y)
	{
		pos.x = -1;
		while (++pos.x < game->win_size.x)
			put_pixel_to_img(game, pos, color);
	}
}
