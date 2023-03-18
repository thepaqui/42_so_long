/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:43:42 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/18 20:45:24 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_BONUS_H
# define SL_BONUS_H
# include <errno.h>
# include <stdio.h> //---------------------------------------------------------
# include "game_bonus.h"
# include "sprites_bonus.h"
# include "../../mlx/mlx.h"
# include "../checking/check_bonus.h"
# include "../parsing/parse_bonus.h"
# include "../utils/utils_bonus.h"
# include "../process/process_bonus.h"

t_game	*game_init(int *err);
t_enemy	*enemy_init(t_game *game, int *err);
int		get_enemy_type(t_vector pos, char **map);

#endif
