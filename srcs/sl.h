/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:43:42 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/03 14:36:25 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SL_H
# define SL_H
# include <errno.h>
# include <stdio.h> //---------------------------------------------------------
# include "game.h"
//# include "../mlx/mlx.h"
# include "../checking/check.h"
# include "../parsing/parse.h"
# include "../utils/utils.h"

# define ERRCHECK check_err(err, game)

#endif
