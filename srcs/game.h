/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:39:01 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/03 22:32:01 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GAME_H
# define GAME_H

typedef struct s_game
{
	char	**map;
	int		start[2];
	int		exit[2];
	int		nbcoins;
}	t_game;
# define MAP game->map
# define XSTART game->start[0]
# define YSTART game->start[1]
# define XEXIT game->exit[0]
# define YEXIT game->exit[1]
# define NBCOINS game->nbcoins

#endif
