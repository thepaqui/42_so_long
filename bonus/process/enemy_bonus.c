/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:09:56 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/17 01:16:32 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

int	get_enemy_number(t_vector mapsize)
{
	return (mapsize.x * mapsize.y / ENEMY_DENSITY);
}
