/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:26:15 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/05 20:19:33 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sl.h"

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
	get_map(av[1], game);
	err = check_map(game);
	ERRCHECK;
/*	for (int i = 0 ; MAPMAP[i] ; i++) //--------------------------------------
		printf("%s\n", MAPMAP[i]); //-----------------------------------------
	printf("\nWidth %d\nHeight %d\n", MAPWID, MAPHEI); //---------------------
	printf("Start at (%d,%d)\n", XSTART, YSTART); //--------------------------
	printf("Exit at (%d,%d)\n", XEXIT, YEXIT); //-----------------------------
	printf("%d coins\n", NBCOINS); //---------------------------------------*/
	launch_game(game);
	free_game(game);
	system("leaks so_long | leaks"); //---------------------------------------
	return (0);
}
