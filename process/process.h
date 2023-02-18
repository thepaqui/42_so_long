/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:56:15 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/17 22:22:14 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H
# include <stdlib.h>
# include "../mlx/mlx.h"
# include "../srcs/game.h"
# include "../utils/utils.h"
# include "../parsing/parse.h"

/* GAME */
char	get_obj_from_pos(t_vector pos, t_map *map);
void	update_player(t_game *game);
void	update_map(t_map *map, t_game *game);
void	update_coins(t_map *map);
void	launch_game(t_game *game);

/* WINDOW */
void	open_window(t_game *game);
int		handle_cross(t_game *game);
void	close_window(t_game *game, int code, char *file);

/* INPUT */
int		handle_key_press(int key, t_game *game);
int		handle_key_release(int key, t_game *game);

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

/* RENDER */
void	put_pixel_to_img(t_game *game, t_vector pos, int color);
void	put_background_color_to_img(t_game *game, int color);
void	put_t_xpm_to_img(t_xpm *xpm, t_game *game, t_vector pos);
void	draw_map(t_game *game);
void	draw_coins(t_game *game);
void	draw_player(t_game *game);
void	prepare_new_frame(t_game *game);

/* COLOR */
int		get_argb(int a, int r, int g, int b);
int		get_alpha(int argb);
int		get_red(int argb);
int		get_green(int argb);
int		get_blue(int argb);
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

#endif
