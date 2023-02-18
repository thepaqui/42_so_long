/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 13:37:30 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/17 22:06:42 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void	prepare_new_frame(t_game *game)
{
	//put_background_color_to_img(game, BLACK);
	draw_map(game);
	draw_coins(game);
	draw_player(game);
}
