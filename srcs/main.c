/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:26:15 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/25 19:37:57 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

static void	check_err(int err, t_game *game)
{
	if (err)
		ft_error(err, game, NULL);
}

int	main(int ac, char **av)
{
	t_game	*game;
	int		err;

	err = 0;
	game = NULL;
	check_input(ac, av, &err);
	check_err(err, game);
	game = game_init(&err);
	check_err(err, game);
	get_map(av[1], game);
	err = check_map(game);
	check_err(err, game);
	err = get_coins_pos(game->map);
	check_err(err, game);
	launch_game(game);
	free_game(game);
	return (0);
}
