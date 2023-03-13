/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 01:21:15 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/13 01:33:16 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

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

int	print_move_count(t_game *game, int mov, int *last, int coins)
{
	t_vector	pos;
	t_vector	size;

	size.x = ft_strlen(MOV_PREFIX) + get_magnitude(mov);
	if (size.x + get_magnitude(coins) + 2 > game->map->size.x)
		size.x -= ft_strlen(MOV_PREFIX);
	if (mov != *last || game->player->pos.y < CNT_COL
		|| size.x != game->last_movesize)
	{
		size.y = 1;
		pos.y = 0;
		pos.x = 0;
		if (size.x != game->last_movesize) {
			//printf("moves case 1\n"); //---
			//printf("\nRefreshing a %d by %d rectangle at (%d,%d)\n\n", game->last_movesize, size.y, pos.x, pos.y); //----------
			refresh_area(game, pos, game->last_movesize, size.y);
		}
		else {
			//printf("moves case 2\n"); //---
			refresh_area(game, pos, size.x, size.y);
		}
		if (size.x == ft_strlen(MOV_PREFIX) + get_magnitude(mov))
		{
			put_str_to_img(MOV_PREFIX, pos, game, RED);
			pos.x = ft_strlen(MOV_PREFIX) * SPR_DIM;
		}
		put_nbr_to_img(mov, pos, game, BLUE);
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
	if (movsize != game->last_movesize) {
		//printf("\nRefreshing a %d by %d rectangle at x = %d\n\n", size.x - 1, size.y, pos.x/SPR_DIM); //----------
		refresh_area(game, pos, size.x - 1, size.y);
	}
	if (game->map->size.x >= movsize + size.x
		&& (coins != *last || game->player->pos.y < CNT_COL))
	{
		size.x--;
		refresh_area(game, pos, size.x, size.y);
		put_nbr_to_img(coins, pos, game, 0x00FFD700);
		pos.x += SPR_DIM * (size.x - 1);
		put_str_to_img("$", pos, game, 0x00FFD700);
		*last = coins;
	}
}
