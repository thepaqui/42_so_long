/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:56:15 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 18:04:44 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_BONUS_H
# define PROCESS_BONUS_H
# include <math.h>
# include "../../mlx/mlx.h"
# include "../parsing/parse_bonus.h"

/* GAME */
int		get_manhattan_dist(t_vector pos1, t_vector pos2);
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

void	update_enemies(t_game *game, t_enemy *enemies);
void	update_enemy_distances(t_player *player, t_enemy *enemy);
int		check_enemy_collisions(t_game *game, t_player *player, t_enemy *enemy);
void	unclip_enemy(t_enemy *enemy, int tmpdir);
void	update_enemy_speed(t_enemy *enemy);
void	update_enemy_pos(t_enemy *enemy, t_map *map);
void	destroy_enemy(t_game *game, t_enemy *enemy);

void	update_map(t_map *map, t_game *game);
void	collect_coin(t_map *map, t_vector pos, int coin);
void	pro_collect_coin(t_map *map, t_vector pos, int coin);
void	update_coins(t_map *map);

void	launch_game(t_game *game);
int		ending_sequence(t_game *game);
void	game_over_sequence(t_game *game, t_player *p);
void	ft_end(t_game *game, int color);
void	stop_sequence(t_game *game);

/* --- GAME OVER --- */
# define DIE_MSG_XL "YOU'VE MET WITH A TERRIBLE FATE, HAVEN'T YOU?"
# define DIE_MSG_L "YOUR GAME IS OVER..."
# define DIE_MSG_M "GAME OVER"
# define DIE_MSG_S "DED"

/* --- END --- */
# define END_MSG_XL "NINTENDO PLEASE DON'T SEND YOUR LAWYERS..."
# define END_MSG_L "CONGRATULATIONS!"
# define END_MSG_M "BRAVO!"
# define END_MSG_S "WOW"

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
void	draw_enemies(t_game *game, t_enemy *enemies);
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
