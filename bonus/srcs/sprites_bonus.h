/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:00:04 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 18:05:26 by thepaqui         ###   ########.fr       */
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
# define PRO_SPRITE "./textures/bonus2/projectile.xpm"
// Number of frames between each projectile animation frame
# define PRO_ANIM_LEN 3
// Defines how many frames the breaking animation will play for (/4)
// So if you input 2, the break animation will play for 8 frames
// Do not input negative numbers here
# define PRO_BREAK_ANIM_LEN 3

/* --- MAP --- */
# define MAP_SPRITE "./textures/bonus2/map.xpm"
# define BG_SPRITE "./textures/bonus/bg.xpm"
# define COIN_SPRITE "./textures/bonus2/coin.xpm"
// Number of frames between each animation frame of the coins
# define COIN_SPEED 6
// Threshold over which coins stop being animated (for performance)
# define MAXCOINS 60

/* --- UI --- */
# define FONT "./textures/bonus2/font.xpm"
# define CURSOR "./textures/bonus2/cursor.xpm"
# define CANVAS "./textures/bonus2/end_bg.xpm"
// Speed of the rainbow text effect (higher = faster)
# define RAINBOWSPEED 10

/* --- ENEMIES --- */
# define ENEMY_G_SPRITE "./textures/bonus2/enemy_ground.xpm"
# define ENEMY_FH_SPRITE "./textures/bonus2/enemy_fly_h.xpm"
# define ENEMY_FV_SPRITE "./textures/bonus2/enemy_fly_v.xpm"

/* --- ENEMY ANIMATIONS --- */
void	set_enemy_animations(t_game *game, t_enemy *enemy);

// Starting sprite of the left animation
# define EHA_SR 0
// Ending sprite of the left animation
# define EHA_ER 3
// Starting sprite of the right animation
# define EHA_SL 4
// Ending sprite of the right animation
# define EHA_EL 7
// Number of frames each frame of the grounded animation plays for
// Should be more than 0
# define EGHA_LEN 6
// Number of frames each frame of the flying horizontally animation plays for
// Should be more than 0
# define EFHA_LEN 2

// Starting sprite of the down animation
# define EVA_SD 0
// Ending sprite of the down animation
# define EVA_ED 5
// Starting sprite of the up animation
# define EVA_SU 6
// Ending sprite of the up animation
# define EVA_EU 11
// Number of frames each frame of the turn around animation plays for
// Should be more than 0
# define EVA_LEN 3

/* --- PLAYER --- */
# define PLAYER_SPRITE "./textures/bonus2/player_bonus.xpm"

/* --- PLAYER ANIMATIONS --- */
void	player_anim_move(t_player *player, t_xpm *psp);
void	player_anim_throw(t_player *player);
void	player_anim_move_ground(t_player *p);
void	player_anim_ground_idle(t_player *p);

void	player_anim_end_init(t_game *game, t_player *player);
int		player_anim_end(t_game *game, t_player *player);
void	player_anim_cheer(t_game *game, t_player *player);

void	refresh_bg_color(t_game *game, t_vector opos, int width, int height);
void	player_anim_death_init(t_game *game, t_player *player);
void	player_anim_death(t_game *game, t_player *player);
void	player_anim_move_die(t_player *p);
void	player_anim_spin(t_game *g, t_player *p);
void	player_anim_faint(t_game *g, t_player *p);
void	player_anim_wake(t_game *g, t_player *p);
void	player_anim_wake_startup(t_player *p);
void	player_anim_wake_look(t_player *p);
void	player_anim_wake_scratch(t_player *p);
void	player_anim_wake_jump(t_game *g, t_player *p);
void	player_anim_wake_fall(t_game *g, t_player *p);

/* --- PLAYER ANIMATIONS --- */
/* ! FLYING ! */
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

/* ! GROUNDED ! */
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

/* ! THROWING ! */
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

/* ! CHEERING ! */
// Starting sprite of the cheering animation
# define PA_CHEER_S 55
// Ending sprite of the cheering animation
# define PA_CHEER_E 77
// Number of frames each frame of the cheering animation plays for
// Should be more than 0
# define PA_CHEER_LEN 5

/* ! DYING ! */
// Background color of death sequence
# define GAME_OVER_BG 0x00200000
// Starting sprite of the dying left animation
# define PA_DIE_SL 71
// Ending sprite of the dying left animation
# define PA_DIE_EL 76
// Starting sprite of the dying right animation
# define PA_DIE_SR 78
// Ending sprite of the dying right animation
# define PA_DIE_ER 83
// Number of frames each frame of the dying animation plays for
// Should be more than 0
# define PA_DIE_LEN 3

/* ! SPINNING ! */
// Number of spins the player does
# define PA_SPIN_NB 4
// Frame the last spin should end on
# define PA_SPIN_LS 53
// Starting sprite of the spinning animation loop
# define PA_SPIN_S 49
// Ending sprite of the spinning animation loop
# define PA_SPIN_E 54
// Number of frames each frame of the spinning animation plays for
// Should be more than 0
# define PA_SPIN_LEN 2

/* ! FAINTING ! */
// Starting sprite of the fainting transition animation
# define PA_FAINT_T 36
// Number of frames each frame of the fainting transition animation plays for
// Should be more than 0
# define PA_FAINT_T_LEN 25
// Starting sprite of the fainting animation loop
# define PA_FAINT_S 38
// Ending sprite of the fainting animation loop
# define PA_FAINT_E 40
// Number of frames each frame of the fainting animation plays for
// Should be more than 0
# define PA_FAINT_LEN 10

/* ! WAKING ! */
// Background color of waking sequence
# define WAKING_BG 0x00002300

// PAS_ are the different waking animation states

# define PAS_STARTUP 0
// Starting sprite of the waking startup animation
# define PA_WSU_S 37
// Ending sprite of the waking startup animation
# define PA_WSU_E 36
// Number of frames each frame of the waking startup animation plays for
// Should be more than 0
# define PA_WSU_LEN 8

# define PAS_LOOK 1
// Starting sprite of the waking looking animation
# define PA_WLO_S 84
// Ending sprite of the waking looking animation
# define PA_WLO_E 88
// Number of times the animation will play
# define PA_WLO_NB 2
// Number of frames the player will look in each direction
# define PA_WLO_CD 30
// Number of frames each frame of the waking looking animation plays for
// Should be more than 0
# define PA_WLO_LEN 6

# define PAS_SCRATCH 2
// Starting sprite of the waking scratching animation
# define PA_WSC_S 89
// Ending sprite of the waking scratching animation
# define PA_WSC_E 97
// Number of times the animation will play
# define PA_WSC_NB 4
// Number of frames each frame of the waking scratching animation plays for
// Should be more than 0
# define PA_WSC_LEN 8

# define PAS_JUMP 3
// Starting sprite of the jumping animation
# define PA_WJU_S 55
// Ending sprite of the jumping animation
# define PA_WJU_E 66
# define INITIAL_JUMP_SPEED 5
# define GRAVITY 0.1
// Number of frames each frame of the waking jumping animation plays for
// Should be more than 0
# define PA_WJU_LEN 6

# define PAS_FALL 4
// Sprite of the waking falling animation
# define PA_WFA_S 72

# define PAS_END 5

#endif