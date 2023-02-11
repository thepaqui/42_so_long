/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 13:37:30 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/09 15:16:06 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void	prepare_new_frame(t_game *game)
{
	put_background_color_to_img(game, WHITE);
	draw_player(game);
	mlx_put_image_to_window(MLX, WIN, IMGIMG, 0, 0);
}
