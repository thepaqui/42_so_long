/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:53:03 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/22 22:24:24 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

static int	newcol(int color, char op)
{
	int	ret;

	ret = color;
	if (op == '-')
		ret -= RAINBOWSPEED;
	else if (op == '+')
		ret += RAINBOWSPEED;
	if (ret < 0)
		ret = 0;
	else if (ret > 255)
		ret = 255;
	return (ret);
}

static void	print_end_message(t_game *game, int color)
{
	t_vector	pos;
	int			offset;
	int			len;

	if (game->map->size.x > ft_strlen(END_MSG_XL) + 2)
		len = ft_strlen(END_MSG_XL);
	else if (game->map->size.x > ft_strlen(END_MSG_L) + 2)
		len = ft_strlen(END_MSG_L);
	else if (game->map->size.x > ft_strlen(END_MSG_M) + 2)
		len = ft_strlen(END_MSG_M);
	else
		len = ft_strlen(END_MSG_S);
	offset = 0;
	if (game->map->size.y % 2 == 0)
		offset = SPR_DIM / 2;
	pos.y = ((game->map->size.y / 2) * SPR_DIM) - offset;
	pos.x = (game->map->size.x * SPR_DIM) / 2 - (len * SPR_DIM / 2);
	if (len == ft_strlen(END_MSG_M))
		put_str_to_img(END_MSG_M, pos, game, color);
	else if (len == ft_strlen(END_MSG_S))
		put_str_to_img(END_MSG_S, pos, game, color);
	else if (len == ft_strlen(END_MSG_XL))
		put_str_to_img(END_MSG_XL, pos, game, color);
	else
		put_str_to_img(END_MSG_L, pos, game, color);
}

void	ending_sequence(t_game *game)
{
	int	red;
	int	blue;
	int	green;

	red = get_red(game->end_color);
	blue = get_blue(game->end_color);
	green = get_green(game->end_color);
	//printf("RGB %d %d %d\n", red, green, blue); //---------------------------------
	if (red == 255 && blue != 255 && green == 0)
		game->end_color = get_argb(0, 255, 0, newcol(blue, '+')); //  red stays blue comes
	else if (blue == 255 && red != 0)
		game->end_color = get_argb(0, newcol(red, '-'), 0, 255); //   blue stays red goes
	else if (blue == 255 && green != 255)
		game->end_color = get_argb(0, 0, newcol(green, '+'), 255); // blue stays green comes
	else if (green == 255 && blue != 0)
		game->end_color = get_argb(0, 0, 255, newcol(blue, '-')); //  green stays blue goes
	else if (green == 255 && red != 255)
		game->end_color = get_argb(0, newcol(red, '+'), 255, 0); //   green stays red comes
	else if (red == 255 && green != 0)
		game->end_color = get_argb(0, 255, newcol(green, '-'), 0); // red stays green goes
	print_end_message(game, game->end_color);
}

static void	print_stop_message(t_game *game)
{
	t_vector	pos;
	int			offset;
	int			len;

	if (game->map->size.x > ft_strlen(STOP_MSG_L) + 2)
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
	if (len == ft_strlen(STOP_MSG_M))
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
