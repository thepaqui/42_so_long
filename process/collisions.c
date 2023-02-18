/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:50:32 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/18 18:35:30 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

char	get_obj_from_pos(t_vector pos, t_map *map)
{
	t_vector	mpos;

	mpos.x = pos.x / SPR_DIM;
	mpos.y = pos.y / SPR_DIM;
	if (mpos.x >= map->size.x || mpos.y >= map->size.y)
		return ('1');
	else
		return (map->map[mpos.y][mpos.x]);
}

int	touch_obj(t_vector pos, t_map *map, char obj, int hitbox_size)
{
	t_vector	hitbox_point;

	//printf("\n"); //---------------
	hitbox_point.x = pos.x;
	hitbox_point.y = pos.y;
	if (get_obj_from_pos(hitbox_point, map) == obj) // x  y
		return (CENTER);
	//printf("Center is not on a \'%c\' cell.\n", obj); //-------------
	hitbox_point.x = pos.x - hitbox_size / 2;
	hitbox_point.y = pos.y - hitbox_size / 2;
	if (get_obj_from_pos(hitbox_point, map) == obj) // x- y-
		return (TOP_LEFT);
	//printf("Top Left corner is not on a \'%c\' cell.\n", obj); //-------------
	hitbox_point.y = pos.y + hitbox_size / 2;
	if (get_obj_from_pos(hitbox_point, map) == obj) // x- y+
		return (BOT_LEFT);
	//printf("Bottom Left corner is not on a \'%c\' cell.\n", obj); //-------------
	hitbox_point.x = pos.x + hitbox_size / 2;
	if (get_obj_from_pos(hitbox_point, map) == obj) // x+ y+
		return (BOT_RIGHT);
	//printf("Bottom Right corner is not on a \'%c\' cell.\n", obj); //-------------
	hitbox_point.y = pos.y - hitbox_size / 2;
	if (get_obj_from_pos(hitbox_point, map) == obj) // x+ y-
		return (TOP_RIGHT);
	//printf("Top Right corner is not on a \'%c\' cell.\n", obj); //-------------
	return (NONE);
}
