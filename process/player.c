/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:31:14 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/06 21:53:19 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "process.h"

void	update_player(t_game *game)
{
    if (PUP && YPLAYER > 0)
        YPLAYER--;
    else if (PDO && YPLAYER < WINHEI - 1)
        YPLAYER++;
    if (PLE && XPLAYER > 0)
        XPLAYER--;
    else if (PRI && XPLAYER < WINWID - 1)
        XPLAYER++;
}