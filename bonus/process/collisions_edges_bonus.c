/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions_edges_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:23:29 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/13 02:25:53 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

int	touch_obj_l(t_vector pos, t_map *map, char obj, int hitbox_size)
{
	t_vector	hitbox_point;

	hitbox_point.x = pos.x - hitbox_size / 2;
	hitbox_point.y = pos.y;
	if (get_obj_from_pos(hitbox_point, map) == obj)
		return (LEFT);
	return (NONE);
}

int	touch_obj_r(t_vector pos, t_map *map, char obj, int hitbox_size)
{
	t_vector	hitbox_point;

	hitbox_point.x = pos.x + hitbox_size / 2;
	hitbox_point.y = pos.y;
	if (get_obj_from_pos(hitbox_point, map) == obj)
		return (RIGHT);
	return (NONE);
}

int	touch_obj_t(t_vector pos, t_map *map, char obj, int hitbox_size)
{
	t_vector	hitbox_point;

	hitbox_point.x = pos.x;
	hitbox_point.y = pos.y - hitbox_size / 2;
	if (get_obj_from_pos(hitbox_point, map) == obj)
		return (TOP);
	return (NONE);
}

int	touch_obj_b(t_vector pos, t_map *map, char obj, int hitbox_size)
{
	t_vector	hitbox_point;

	hitbox_point.x = pos.x;
	hitbox_point.y = pos.y + hitbox_size / 2;
	if (get_obj_from_pos(hitbox_point, map) == obj)
		return (BOT);
	return (NONE);
}
