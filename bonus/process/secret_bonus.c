/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secret_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:12:15 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/10 19:43:47 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

static int	ft_end_help(t_map *map)
{
	int	res;

	res = map->size.x * map->size.y;
	return (res);
}

void	ft_end(t_game *game, int color)
{
	char		msg[100000];
	int			nb;
	t_vector	pos;
	int			i;

	nb = ft_end_help(game->map);
	//printf("nb = %d\n", nb); //---
	i = 0;
	while (i != nb)
	{
		msg[i++] = '4';
		if (i == nb)
			break ;
		msg[i++] = '2';
	}
	msg[i] = '\0';
	if (nb > 120)
	{
		msg[nb - (nb / 4)] = '6';
		msg[nb - (nb / 4) + 1] = '9';
	}
	pos.x = 0;
	pos.y = 0;
	put_str_to_img(msg, pos, game, color);
}
