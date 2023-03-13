/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenery_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:34:33 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/13 04:20:44 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

static int	get_scn_spr(t_xpm *bg, t_vector pos, int hei)
{
	int	res;

	res = (pos.y / SPR_DIM) * bg->spr_per_line;
	res += (pos.x / SPR_DIM) % bg->spr_per_line;
	res -= (hei - bg->spr_per_column) * bg->spr_per_line;
	if (res < 0)
		res = 0;
	return (res);
}

void	refresh_scenery(t_game *game, t_map *map, t_vector opos, t_vector s)
{
	t_vector	pos;
	int			lin;
	int			col;

	lin = 0;
	pos.y = SPR_DIM * (opos.y / SPR_DIM);
	while (lin < s.y)
	{
		pos.x = SPR_DIM * (opos.x / SPR_DIM);
		col = 0;
		while (col < s.x)
		{
			map->bg->cur_spr = get_scn_spr(map->bg, pos, map->size.y);
			put_t_xpm_to_img(map->bg, game, pos);
			col++;
			pos.x += SPR_DIM;
		}
		lin++;
		pos.y += SPR_DIM;
	}
}
