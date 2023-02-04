/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:26:15 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/04 16:06:57 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sl.h"

static t_img	*image_init(void)
{
	t_img	*image;

	image = ft_calloc(1, sizeof(t_img));
	if (!image)
		return (NULL);
	image->img = NULL;
	image->add = NULL;
	image->bits_per_pixel = 0;
	image->line_len = 0;
	image->endian = 0;
	return (image);
}

static t_game	*game_init(int *err)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		*err = MALLOCFAIL;
		return (NULL);
	}
	IMG = image_init();
	if (!IMG)
	{
		free_game(game);
		*err = MALLOCFAIL;
		return (NULL);
	}
	MLX = NULL;
	WIN = NULL;
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
	get_map(av[1], game);
	err = check_map(game);
	ERRCHECK;
	//for (int i = 0 ; MAP[i] ; i++) //--------------------------------------
	//	printf("|%s|\n", MAP[i]); //---------------------------------------
	start_mlx(game);
	free_game(game); //----------------------------------------------------
	system("leaks so_long | grep leaks"); //-------------------------------
}
