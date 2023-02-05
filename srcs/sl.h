/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:43:42 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/05 18:10:25 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SL_H
# define SL_H
# include <errno.h>
# include <stdio.h> //---------------------------------------------------------
# include "game.h"
# include "../mlx/mlx.h"
# include "../checking/check.h"
# include "../parsing/parse.h"
# include "../utils/utils.h"
# include "../process/process.h"

t_game	*game_init(int *err);
# define ERRCHECK check_err(err, game)

#endif
