/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:26:15 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/02 18:44:23 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sl.h"

static t_game	*game_init(int *err)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		*err = MALLOCFAIL;
		return (NULL);
	}
	game.map = NULL;
	return (game);
}

static void	check_err(int *err)
{
	if (*err)
		error(*err, NULL);
}

int	main(int ac, char **av)
{
	t_game	*game;
	int		*err;

	*err = 0;
	check_input(ac, av, err);
	check_err(err);
	game = game_init(err);
	check_err(err);
	game.map = get_map(av[1]); //leaks here if get_map fails (not freeing game)
	*err = check_map(game.map);
	check_err();
}
