/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:26:15 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/03 18:49:42 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sl.h"

static t_game	*game_init(int *err)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		*err = MALLOCFAIL;
		return (NULL);
	}
	MAP = NULL;
	NBCOINS = 0;
	return (game);
}

static void	check_err(int err, t_game *game)
{
	if (err)
		ft_error(err, game);
}

int	main(int ac, char **av)
{
	t_game	*game;
	int		err;

	err = 0;
	game = NULL;
	check_input(ac, av, &err);
	ERRCHECK;
	game = game_init(&err);
	ERRCHECK;
	MAP = get_map(av[1]); //leaks here if get_map fails (not freeing game)
	err = check_map(game);
	ERRCHECK;
	for (int i = 0 ; MAP[i] ; i++) //--------------------------------------
		printf("|%s|\n", MAP[i]); //---------------------------------------
	free_game(game); //----------------------------------------------------
	system("leaks so_long | grep leaks"); //-------------------------------
}
