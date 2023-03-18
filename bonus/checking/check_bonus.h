/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:31:28 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/18 18:14:16 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_BONUS_H
# define CHECK_BONUS_H
# include "../utils/utils_bonus.h"
# include "../srcs/game_bonus.h"
# include "../srcs/sprites_bonus.h"

int		is_file_type(char *path, char *ext);
void	check_input(int ac, char **av, int *err);
int		check_map(t_game *game);

int		check_shape(t_game *game);
int		check_path(t_game *game);

int		check_xpm(char **xpm, t_xpm *stru);

#endif
