/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:26:15 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/25 21:16:39 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_bonus.h"

static void	check_err(int err, t_game *game, char *msg)
{
	if (err)
		ft_error(err, game, msg);
}

int	main(int ac, char **av)
{
	t_game	*game;
	int		err;

	err = 0;
	game = NULL;
	srand(time(NULL));
	check_input(ac, av, &err);
	check_err(err, game, "Input checking");
	game = game_init(&err);
	check_err(err, game, "Game initialization");
	get_map(av[1], game);
	err = check_map(game);
	check_err(err, game, "Map checking");
	err = get_coins_pos(game->map);
	check_err(err, game, "Coin positioning");
	game->enemies = enemy_init(game, &err);
	check_err(err, game, "Enemies initialization");
	launch_game(game);
	free_game(game);
	return (0);
}
