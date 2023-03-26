/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_message_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:40:16 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 17:52:13 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

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

static int	get_end_msg_len(int mwid, char *xl)
{
	if (xl && mwid > ft_strlen(xl) + 2)
		return (ft_strlen(xl));
	else if (mwid > ft_strlen(END_MSG_L) + 2)
		return (ft_strlen(END_MSG_L));
	else if (mwid > ft_strlen(END_MSG_M) + 2)
		return (ft_strlen(END_MSG_M));
	else
		return (ft_strlen(END_MSG_S));
}

static void	print_end_message(t_game *game, int color)
{
	t_vector	pos;
	int			offset;
	int			len;
	char		*xl;

	xl = ft_strdup(END_MSG_XL);
	len = get_end_msg_len(game->map->size.x, xl);
	offset = 0;
	if (game->map->size.y % 2 == 0)
		offset = SPR_DIM / 2;
	pos.y = ((game->map->size.y / 2) * SPR_DIM) - offset;
	pos.x = (game->map->size.x * SPR_DIM) / 2 - (len * SPR_DIM / 2);
	if (game->map->ft)
		ft_end(game, color);
	else if (len == ft_strlen(END_MSG_M))
		put_str_to_img(END_MSG_M, pos, game, color);
	else if (len == ft_strlen(END_MSG_S))
		put_str_to_img(END_MSG_S, pos, game, color);
	else if (xl && len == ft_strlen(xl))
		put_str_to_img(xl, pos, game, color);
	else
		put_str_to_img(END_MSG_L, pos, game, color);
	if (xl)
		free(xl);
}

int	ending_sequence(t_game *game)
{
	int	red;
	int	blue;
	int	green;

	if (game->player->state != PCHEER)
		return (player_anim_end(game, game->player));
	red = get_red(game->end_color);
	blue = get_blue(game->end_color);
	green = get_green(game->end_color);
	if (red == 255 && blue != 255 && green == 0)
		game->end_color = get_argb(0, 255, 0, newcol(blue, '+'));
	else if (blue == 255 && red != 0)
		game->end_color = get_argb(0, newcol(red, '-'), 0, 255);
	else if (blue == 255 && green != 255)
		game->end_color = get_argb(0, 0, newcol(green, '+'), 255);
	else if (green == 255 && blue != 0)
		game->end_color = get_argb(0, 0, 255, newcol(blue, '-'));
	else if (green == 255 && red != 255)
		game->end_color = get_argb(0, newcol(red, '+'), 255, 0);
	else if (red == 255 && green != 0)
		game->end_color = get_argb(0, 255, newcol(green, '-'), 0);
	player_anim_cheer(game, game->player);
	print_end_message(game, game->end_color);
	return (0);
}
