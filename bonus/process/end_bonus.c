/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:53:03 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 17:42:19 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

static void	print_stop_message(t_game *game)
{
	t_vector	pos;
	int			offset;
	int			len;

	if (game->map->ft)
		len = ft_strlen(STOP_MSG_FT);
	else if (game->map->size.x > ft_strlen(STOP_MSG_L) + 2)
		len = ft_strlen(STOP_MSG_L);
	else if (game->map->size.x > ft_strlen(STOP_MSG_M) + 2)
		len = ft_strlen(STOP_MSG_M);
	else
		len = ft_strlen(STOP_MSG_S);
	offset = 0;
	if (game->map->size.y % 2 == 0)
		offset = SPR_DIM / 2;
	pos.y = ((game->map->size.y / 2) * SPR_DIM) - offset;
	pos.x = (game->map->size.x * SPR_DIM) / 2 - (len * SPR_DIM / 2);
	if (game->map->ft)
		put_str_to_img(STOP_MSG_FT, pos, game, BLACK);
	else if (len == ft_strlen(STOP_MSG_M))
		put_str_to_img(STOP_MSG_M, pos, game, BLACK);
	else if (len == ft_strlen(STOP_MSG_S))
		put_str_to_img(STOP_MSG_S, pos, game, BLACK);
	else
		put_str_to_img(STOP_MSG_L, pos, game, BLACK);
}

void	stop_sequence(t_game *game)
{
	put_background_color_to_img(game, BLACK);
	print_stop_message(game);
	if (game->stop_frame == 3)
		close_window(game, 0, NULL);
	game->stop_frame++;
}
