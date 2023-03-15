/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 05:38:35 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/15 05:54:56 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

static int	get_canvas_spr(t_vector win_size, t_vector pos)
{
	snap_to_grid(&pos);
	if (!pos.x && !pos.y)
		return (0);
	else if (pos.x == win_size.x - SPR_DIM && !pos.y)
		return (2);
	else if (!pos.x && pos.y == win_size.y - SPR_DIM)
		return (6);
	else if (pos.x == win_size.x - SPR_DIM && pos.y == win_size.y - SPR_DIM)
		return (8);
	else if (!pos.y)
		return (1);
	else if (!pos.x)
		return (3);
	else if (pos.x == win_size.x - SPR_DIM)
		return (5);
	else if (pos.y == win_size.y - SPR_DIM)
		return (7);
	else
		return (4);
}

void	draw_canvas_part(t_game *game, t_vector opos, int width, int height)
{
	t_vector	pos;

	snap_to_grid(&opos);
	pos.y = opos.y;
	while (pos.y != opos.y + height * SPR_DIM)
	{
		pos.x = opos.x;
		while (pos.x != opos.x + width * SPR_DIM)
		{
			game->canvas->cur_spr = get_canvas_spr(game->win_size, pos);
			put_t_xpm_to_img(game->canvas, game, pos);
			pos.x += SPR_DIM;
		}
		pos.y += SPR_DIM;
	}
}

void	draw_all_canvas(t_game *game)
{
	t_vector	pos;
	t_vector	size;

	pos.x = 0;
	pos.y = 0;
	size.x = game->win_size.x / SPR_DIM;
	size.y = game->win_size.y / SPR_DIM;
	draw_canvas_part(game, pos, size.x, size.y);
}
