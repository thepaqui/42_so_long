/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:56:15 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/08 18:07:04 by thepaqui         ###   ########.fr       */
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
void	snap_to_grid(t_vector pos);
void	get_cursor_pos(t_game *game);
void	get_player_to_cursor_dir(t_game *game, t_player *player);
void	throw(t_game *game);
void	update_player(t_game *game);
void	update_map(t_map *map, t_game *game);
void	collect_coin(t_map *map, t_game *game, t_vector pos, int coin);
void	update_coins(t_map *map);
void	launch_game(t_game *game);
void	ending_sequence(t_game *game);
void	stop_sequence(t_game *game);

/* END */
# define END_MSG_XL "UN PETIT OUTSTANDING SVP ?"
# define END_MSG_L "CONGRATULATIONS!"
# define END_MSG_M "BRAVO!"
# define END_MSG_S "WOW"
# define RAINBOWSPEED 10

/* STOP */
# define STOP_MSG_L "HAVE A NICE DAY!"
# define STOP_MSG_M "GOODBYE"
# define STOP_MSG_S "BYE"

/* COLLISION CODES */
# define NONE 0
# define CENTER 1
# define TOP_LEFT 2
# define BOT_LEFT 3
# define TOP_RIGHT 4
# define BOT_RIGHT 5

/* WINDOW */
void	open_window(t_game *game);
int		handle_cross(t_game *game);
void	close_window(t_game *game, int code, char *file);
void	get_window_size(t_game *game);

/* INPUT */
int		handle_key_press(int key, t_game *game);
int		handle_key_release(int key, t_game *game);
int		handle_click(int key, int x, int y, t_game *game);

/* EVENTS */
# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17

/* KEYS */
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

/* CLICKS */
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define MIDDLE_CLICK 3

/* RENDER */
void	put_pixel_to_img(t_game *game, t_vector pos, int color);
void	put_background_color_to_img(t_game *game, int color);
void	put_t_xpm_to_img(t_xpm *xpm, t_game *game, t_vector pos);
int		get_wall_texture(char **map, t_vector size, t_vector pos);
void	draw_bg_part(t_game *game, t_map *map, t_vector opos, t_vector s);
void	refresh_area(t_game *game, t_vector pos, int width, int height);
int		get_pos_walls_around(char **map, t_vector s, t_vector pos);
void	draw_map(t_game *game);
void	draw_coins(t_game *game);
void	update_cursor(t_game *game);
void	update_projectile(t_game *game, t_player *player, t_map *map);
void	put_char_to_img(char c, t_vector pos, t_game *game, int color);
void	put_str_to_img(char *s, t_vector pos, t_game *game, int color);
void	put_nbr_to_img(unsigned int n, t_vector pos, t_game *game, int color);
int		print_move_count(t_game *game, int moves, int *last);
void	print_coin_count(t_game *game, int movsize, int coins, int *last);
void	prepare_new_frame(t_game *game);

# define MOV_MAX_DIGITS 5
# define MOV_PREFIX "MOVES "

/* COLOR */
int		get_argb(int a, int r, int g, int b);
int		get_alpha(int argb);
int		get_red(int argb);
int		get_green(int argb);
int		get_blue(int argb);

/* COLOR PRESETS */
# define VOID 0xFF000000
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

#endif
