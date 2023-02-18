/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:31:14 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/17 22:20:30 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

static void update_player_position(t_player *player, t_camera *camera)
{
    if (player->up)
        player->pos.y -= player->speed;
    else if (player->down)
        player->pos.y += player->speed;
    if (player->left)
        player->pos.x -= player->speed;
    else if (player->right)
        player->pos.x += player->speed;
    if (player->pos.y < 0)
        player->pos.y = 0;
    if (player->pos.x < 0)
        player->pos.x = 0;
    if (player->pos.x > camera->size.x - SPR_DIM - 1)
        player->pos.x = camera->size.x - SPR_DIM - 1;
    if (player->pos.y > camera->size.y - SPR_DIM - 1)
        player->pos.y = camera->size.y - SPR_DIM - 1;
}

static void set_player_animations(t_player *player)
{
    if (player->state == PIDLE)
        player->sprite->cur_spr = 0;
}

static void set_player_speed(t_player *player)
{
    if ((player->up || player->down) && (player->left || player->right))
        player->speed = PLAYER_DIAG_SPEED;
    else
        player->speed = PLAYER_SPEED;
}

void	update_player(t_game *game)
{
    set_player_animations(game->player);
    set_player_speed(game->player);
    update_player_position(game->player, game->camera);
}