/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:00:04 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/18 18:13:20 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_BONUS_H
# define SPRITES_BONUS_H
# include "game_bonus.h"

/* --- GENERAL --- */
// Dimensions of game's textures
# define SPR_DIM 32
// Dimensions of detection box for counter refresh (keep bigger than SPR_DIM)
# define CNT_COL 64

/* --- PROJECTILE --- */
# define PRO_SPRITE "./textures/bonus/projectile.xpm"
// Number of frames between each projectile animation frame
# define PRO_ANIM_LEN 3
// Defines how many frames the breaking animation will play for (/4)
// So if you input 2, the break animation will play for 8 frames
// Do not input negative numbers here
# define PRO_BREAK_ANIM_LEN 3

/* --- ENEMIES --- */
# define ENEMY_G_SPRITE "./textures/bonus/enemy_ground.xpm"
# define ENEMY_FH_SPRITE "./textures/bonus/enemy_fly_h.xpm"
# define ENEMY_FV_SPRITE "./textures/bonus/enemy_fly_v.xpm"

/* --- MAP --- */
# define MAP_SPRITE "./textures/bonus/map.xpm"
# define BG_SPRITE "./textures/bonus/bg.xpm"
# define COIN_SPRITE "./textures/bonus/coin.xpm"
// Number of frames between each animation frame of the coins
# define COIN_SPEED 6
// Threshold over which coins stop being animated (for performance)
# define MAXCOINS 60

/* --- UI --- */
# define FONT "./textures/bonus/font.xpm"
# define CURSOR "./textures/bonus/cursor.xpm"
# define CANVAS "./textures/bonus/end_bg.xpm"
// Speed of the rainbow text effect (higher = faster)
# define RAINBOWSPEED 10

/* --- PLAYER --- */
# define PLAYER_SPRITE "./textures/bonus/player.xpm"

/* --- PLAYER ANIMATIONS --- */
void	player_anim_move(t_player *player);
void	player_anim_move_help(t_player *p, int ls, int le, int rs, int re);
void	player_anim_throw(t_player *player);
void	player_anim_end_init(t_game *game, t_player *player);
void	player_anim_end(t_game *game, t_player *player);
void	player_anim_cheer(t_game *game, t_player *player);

/* --- PLAYER ANIMATIONS --- */
// Starting sprite of the flying left animation
# define PA_FL_S 0
// Ending sprite of the flying left animation
# define PA_FL_E 1
// Starting sprite of the flying right animation
# define PA_FR_S 5
// Ending sprite of the flying right animation
# define PA_FR_E 6
// Number of frames each frame of the flying animation plays for
// Should be more than 0
# define PA_FLY_LEN 7

// Starting sprite of the grounded left idle animation
# define PA_GIL_S 84
// Ending sprite of the grounded left idle animation
# define PA_GIL_E 88
// Starting sprite of the grounded right idle animation
# define PA_GIR_S 91
// Ending sprite of the grounded right idle animation
# define PA_GIR_E 95
// Number of frames each frame of the grounded idle animation plays for
// Should be more than 0
# define PA_GI_LEN 5
// Cooldown (in frames) between each play of the grounded idle animation
# define PA_GI_CD 100
// Starting sprite of the left walking animation
# define PA_GL_S 10
// Ending sprite of the left walking animation
# define PA_GL_E 19
// Starting sprite of the right walking animation
# define PA_GR_S 23
// Ending sprite of the right walking animation
# define PA_GR_E 32
// Number of frames each frame of the grounded animation plays for
// Should be more than 0
# define PA_GROUND_LEN 4

// The 4 throwing animations all have 3 frames of animation
// Starting sprite of the flying left throwing animation
# define PA_THROW_FL 2
// Starting sprite of the flying right throwing animation
# define PA_THROW_FR 7
// Starting sprite of the grounded left throwing animation
# define PA_THROW_GL 20
// Starting sprite of the grounded right throwing animation
# define PA_THROW_GR 33
// Number of frames the throwing animation plays for
// Should be more than 10
# define PA_THROW_LEN 20

// Starting sprite of the cheering animation
# define PA_CHEER_S 55
// Ending sprite of the cheering animation
# define PA_CHEER_E 77
// Number of frames each frame of the cheering animation plays for
// Should be more than 0
# define PA_CHEER_LEN 5

#endif