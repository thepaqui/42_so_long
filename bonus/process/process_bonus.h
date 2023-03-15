/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:56:15 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/15 05:55:07 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_BONUS_H
# define PROCESS_BONUS_H
# include <stdlib.h>
# include <math.h>
# include "../../mlx/mlx.h"
# include "../srcs/game_bonus.h"
# include "../utils/utils_bonus.h"
# include "../parsing/parse_bonus.h"

/* GAME */
char	get_obj_from_pos(t_vector pos, t_map *map);
int		touch_obj(t_vector pos, t_map *map, char obj, int hitbox_size);
int		touch_obj_l(t_vector pos, t_map *map, char obj, int hitbox_size);
int		touch_obj_r(t_vector pos, t_map *map, char obj, int hitbox_size);
int		touch_obj_t(t_vector pos, t_map *map, char obj, int hitbox_size);
int		touch_obj_b(t_vector pos, t_map *map, char obj, int hitbox_size);
void	snap_to_grid(t_vector *pos);
void	get_cursor_pos(t_game *game);
void	get_player_to_cursor_dir(t_game *game, t_player *player);
void	throw(t_game *game);
void	bounce(t_game *game, t_vector pos);
void	destroy_projectile(t_game *game, t_vector pos);
void	update_player(t_game *game, t_player *player);
void	update_map(t_map *map, t_game *game);
void	collect_coin(t_map *map, t_vector pos, int coin);
void	pro_collect_coin(t_map *map, t_vector pos, int coin);
void	update_coins(t_map *map);
void	launch_game(t_game *game);
void	ending_sequence(t_game *game);
void	ft_end(t_game *game, int color);
void	stop_sequence(t_game *game);

/* --- END --- */
# define END_MSG_XL "T'AURAIS PAS 5 EUROS STP ?"
# define END_MSG_L "CONGRATULATIONS!"
# define END_MSG_M "BRAVO!"
# define END_MSG_S "WOW"
// Speed of the rainbow text effect (higher = faster)
# define RAINBOWSPEED 10

/* --- STOP --- */
# define STOP_MSG_FT "DON'T PANIC"
# define STOP_MSG_L "HAVE A NICE DAY!"
# define STOP_MSG_M "GOODBYE"
# define STOP_MSG_S "BYE"

/* --- COLLISION CODES --- */
# define NONE 0
# define CENTER 1
# define TOP_LEFT 2
# define BOT_LEFT 3
# define TOP_RIGHT 4
# define BOT_RIGHT 5
# define LEFT 6
# define RIGHT 7
# define TOP 8
# define BOT 9

/* --- WINDOW --- */
void	open_window(t_game *game);
int		handle_cross(t_game *game);
void	close_window(t_game *game, int code, char *file);
//void	get_window_size(t_game *game);

/* --- INPUT --- */
int		handle_key_press(int key, t_game *game);
int		handle_key_release(int key, t_game *game);
int		handle_click(int key, int x, int y, t_game *game);

/* --- EVENTS --- */
# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17

/* --- KEYS --- */
# define KEY_ESC 53
# define KEY_SPC 49
# define KEY_ARRUP 126
# define KEY_ARRDO 125
# define KEY_ARRLE 123
# define KEY_ARRRI 124
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

/* --- CLICKS --- */
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define MIDDLE_CLICK 3

/* --- RENDER --- */
void	put_pixel_to_img(t_game *game, t_vector pos, int color);
void	put_background_color_to_img(t_game *game, int color);
void	put_t_xpm_to_img(t_xpm *xpm, t_game *game, t_vector pos);
int		get_wall_texture(char **map, t_vector size, t_vector pos);
void	refresh_scenery(t_game *game, t_map *map, t_vector opos, t_vector s);
void	draw_bg_part(t_game *game, t_map *map, t_vector opos, t_vector s);
void	refresh_area(t_game *game, t_vector pos, int width, int height);
int		get_pos_walls_around(char **map, t_vector s, t_vector pos);
void	draw_map(t_game *game);
void	draw_coins(t_game *game);
void	update_cursor(t_game *game);
void	update_projectile(t_game *game, t_player *player, t_map *map);
void	draw_cursor(t_game *game);
void	put_char_to_img(char c, t_vector pos, t_game *game, int color);
void	put_str_to_img(char *s, t_vector pos, t_game *game, int color);
void	put_nbr_to_img(unsigned int n, t_vector pos, t_game *game, int color);
int		print_move_count(t_game *game, int moves, int *last, int coins);
void	print_coin_count(t_game *game, int movsize, int coins, int *last);
void	prepare_new_frame(t_game *game);
void	draw_all_canvas(t_game *game);
void	draw_canvas_part(t_game *game, t_vector opos, int width, int height);

// Text that goes before the move counter
# define MOV_PREFIX "MOVES "

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

// Sprite of the grounded left idle animation
# define PA_GIL 12
// Sprite of the grounded right idle animation
# define PA_GIR 25
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
# define PA_CHEER_LEN 6

/* --- COLOR --- */
int		get_argb(int a, int r, int g, int b);
int		get_alpha(int argb);
int		get_red(int argb);
int		get_green(int argb);
int		get_blue(int argb);

/* --- COLOR PRESETS --- */
# define VOID 0xFF000000
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

#endif
