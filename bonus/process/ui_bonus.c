/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:45:30 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 15:23:27 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_bonus.h"

static int	get_magnitude(int n)
{
	int	res;

	res = 1;
	if (n < 0)
		res++;
	while (n / 10)
	{
		res++;
		n /= 10;
	}
	return (res);
}

static int	should_print_move_count(t_game *g, int mov, int last, t_vector size)
{
	if (mov != last || g->player->pro_pos.y < CNT_COL
		|| g->player->pos.y < CNT_COL || g->last_cpos.y < CNT_COL
		|| size.x != g->last_movesize)
		return (1);
	else
		return (0);
}

int	print_move_count(t_game *game, int mov, int *last, int coins)
{
	t_vector	pos;
	t_vector	size;

	size.x = ft_strlen(MOV_PREFIX) + get_magnitude(mov);
	if (size.x + get_magnitude(coins) + 2 > game->map->size.x)
		size.x -= ft_strlen(MOV_PREFIX);
	if (should_print_move_count(game, mov, *last, size))
	{
		size.y = 1;
		pos.y = 0;
		pos.x = 0;
		if (size.x != game->last_movesize)
			refresh_area(game, pos, game->last_movesize, size.y);
		else
			refresh_area(game, pos, size.x, size.y);
		if (size.x == ft_strlen(MOV_PREFIX) + get_magnitude(mov))
		{
			put_str_to_img(MOV_PREFIX, pos, game, 0x002ba295);
			pos.x = ft_strlen(MOV_PREFIX) * SPR_DIM;
		}
		put_nbr_to_img(mov, pos, game, 0x00d45d6a);
		*last = mov;
	}
	return (size.x);
}

void	print_coin_count(t_game *game, int movsize, int coins, int *last)
{
	t_vector	pos;
	t_vector	size;

	size.x = 2 + get_magnitude(coins);
	size.y = 1;
	pos.x = SPR_DIM * (game->map->size.x - size.x + 1);
	pos.y = 0;
	if (movsize != game->last_movesize)
		refresh_area(game, pos, size.x - 1, size.y);
	if (game->map->size.x >= movsize + size.x
		&& (coins != *last || game->player->pos.y < CNT_COL
			|| movsize != game->last_movesize
			|| game->player->pro_pos.y < CNT_COL
			|| game->last_cpos.y < CNT_COL))
	{
		size.x--;
		refresh_area(game, pos, size.x, size.y);
		put_nbr_to_img(coins, pos, game, 0x006db93f);
		pos.x += SPR_DIM * (size.x - 1);
		put_str_to_img("$", pos, game, 0x006db93f);
		*last = coins;
	}
}
