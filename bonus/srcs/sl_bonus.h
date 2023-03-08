/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:43:42 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/24 18:07:45 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_BONUS_H
# define SL_BONUS_H
# include <errno.h>
# include <stdio.h> //---------------------------------------------------------
# include "game_bonus.h"
# include "../../mlx/mlx.h"
# include "../checking/check_bonus.h"
# include "../parsing/parse_bonus.h"
# include "../utils/utils_bonus.h"
# include "../process/process_bonus.h"

t_game	*game_init(int *err);

#endif
