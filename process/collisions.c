/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:50:32 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/25 17:22:37 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

char	get_obj_from_pos(t_vector pos, t_map *map)
{
	t_vector	mpos;

	mpos.x = pos.x / SPR_DIM;
	mpos.y = pos.y / SPR_DIM;
	if (mpos.x >= map->size.x || mpos.y >= map->size.y)
		return (WALL);
	else
		return (map->map[mpos.y][mpos.x]);
}

int	touch_obj(t_vector pos, t_map *map, char obj, int hitbox_size)
{
	t_vector	hitbox_point;

	hitbox_point.x = pos.x;
	hitbox_point.y = pos.y;
	if (get_obj_from_pos(hitbox_point, map) == obj)
		return (CENTER);
	hitbox_point.x = pos.x - hitbox_size / 2;
	hitbox_point.y = pos.y - hitbox_size / 2;
	if (get_obj_from_pos(hitbox_point, map) == obj)
		return (TOP_LEFT);
	hitbox_point.y = pos.y + hitbox_size / 2;
	if (get_obj_from_pos(hitbox_point, map) == obj)
		return (BOT_LEFT);
	hitbox_point.x = pos.x + hitbox_size / 2;
	if (get_obj_from_pos(hitbox_point, map) == obj)
		return (BOT_RIGHT);
	hitbox_point.y = pos.y - hitbox_size / 2;
	if (get_obj_from_pos(hitbox_point, map) == obj)
		return (TOP_RIGHT);
	return (NONE);
}
