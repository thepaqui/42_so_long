/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:31:28 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/03 22:14:10 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECK_H
# define CHECK_H
# include "../utils/utils.h"
# include "../srcs/game.h"

void	check_input(int ac, char **av, int *err);
int		check_map(t_game *game);

int	check_shape(char **map);
int	check_path(t_game *game);

#endif
