/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:50:32 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/17 22:18:52 by thepaqui         ###   ########.fr       */
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