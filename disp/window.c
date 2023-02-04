/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:57:00 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/04 16:06:53 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "disp.h"

void	start_mlx(t_game *game)
{
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WINWID, WINHEI, WINNAME);
	IMGIMG = mlx_new_image(MLX, WINWID, WINHEI);
	IMGADD = mlx_get_data_addr(IMGIMG, &IMGBPP, &IMGLINLEN, &IMGENDIAN);
	mlx_loop(MLX);
}
