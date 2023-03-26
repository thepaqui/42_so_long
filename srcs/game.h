/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:39:01 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 14:22:03 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

// Dimensions of game's textures
# define SPR_DIM 32
// Dimensions of detection box for counter refresh (keep bigger than SPR_DIM)
# define CNT_COL 80

typedef struct s_xpm
{
	int		*palette;
	char	*token;
	int		pal_size;
	char	**spritesheet;
	int		cur_spr;
	int		spr_per_line;
	int		spr_per_column;
}				t_xpm;

typedef struct s_img
{
	void	*img;
	char	*add;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

# define PLAYER_SPRITE "./textures/basic/player.xpm"

typedef struct s_player
{
	t_vector	pos;
	int			speed;
	int			last_key;
	int			up;
	int			down;
	int			left;
	int			right;
	int			state;
	t_xpm		*sprite;
	int			coin_anim_len;
}				t_player;

# define PLAYER_SPEED 4
# define PLAYER_DIAG_SPEED 3
# define PLAYER_COIN_ANIM_LEN 20
# define PLAYER_HITBOX 10

/* PLAYER STATES */
# define PIDLE 0
# define PMOVE 1
# define PCOIN 2

typedef struct s_map
{
	char		**map;
	t_xpm		*sprite;
	t_xpm		*bg;
	t_vector	size;
	t_vector	start;
	t_vector	exit;
	int			nbcoins;
	int			last;
	int			totalcoins;
	t_xpm		*coin_spr;
	t_vector	*coin_pos;
	int			coin_speed;
}				t_map;

# define MAP_SPRITE "./textures/basic/map.xpm"
# define BG_SPRITE "./textures/basic/bg.xpm"
# define COIN_SPRITE "./textures/basic/coin.xpm"
# define COIN_SPEED 6
# define MAXCOINS 70

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_vector	win_size;
	t_img		*image;
	t_player	*player;
	t_map		*map;
	t_xpm		*font;
	int			last_moves;
	int			moves;
	int			movesize;
	int			last_movesize;
	int			end_frame;
	int			end_color;
	int			stop_frame;
	int			state;
}				t_game;

# define FONT "./textures/basic/font.xpm"

/* GAME STATES */
# define GAME_ERROR 0
# define GAME_STARTUP 1
# define GAME_RUN 2
# define GAME_STOP 3
# define GAME_WIN 4

/* WINDOW */
# define WINNAME "BIG BUCKS!!!"

/* MAP OBJECTS */
# define EMPTY '0'
# define WALL '1'
# define PLAYER 'P'
# define EXIT_CLOSE 'E'
# define EXIT_OPEN 'G'
# define COIN 'C'

#endif
