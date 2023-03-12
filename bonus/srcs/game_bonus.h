/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:39:01 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/12 20:47:48 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_BONUS_H
# define GAME_BONUS_H

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct t_dblvector
{
	double	x;
	double	y;
}				t_dblvector;

// Dimensions of game's textures
# define SPR_DIM 32
// Dimensions of detection box for counter refresh (keep bigger than SPR_DIM)
# define CNT_COL 64

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
# define PRO_SPRITE "./textures/bonus/projectile.xpm"

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
	int			throw;
	t_xpm		*pro;
	t_dblvector	pro_pos;
	t_dblvector	pro_dir;
	int			pro_anim_speed;
	int			pro_here;
	int			pro_bounces;
}				t_player;

/* --- PLAYER --- */
// Player speed (in pixels)
# define PLAYER_SPEED 4
// Player diagonal speed (in pixels)
# define PLAYER_DIAG_SPEED 3
// Number of frames the coin collection animation plays for
# define PLAYER_COIN_ANIM_LEN 20
// Size of square player hitbox
# define PLAYER_HITBOX 10
// Cooldown between each projectile throw (in frames)
# define PLAYER_THROW_COOLDOWN 80

/* --- PLAYER STATES --- */
# define PIDLE 0
# define PMOVE 1
# define PCOIN 2
# define PTHROW 3
# define PTHROWEND 4 // might be superfluous
# define PDEATH 5

/* --- PROJECTILE --- */
// Projectile speed (in pixels) (should be kept lower than 10)
# define PRO_SPEED 5
// Number of frames between each projectile animation frame
# define PRO_ANIM_LEN 3
// Max number of projectiles on screen (anything other than 1 or 0 will bug)
# define PRO_LIMIT 1
// Size of square projectile hitbox
# define PRO_HITBOX 16
// Defines if projectiles can go through walls or not (0 NO, 1 YES)
# define PRO_SPECTRAL 0 // !!! ------------- THIS SHOULD ABSOLUTELY BE 0 FOR FINAL PUSH -------------------
// Defines if projectiles can collect coins or not (0 NO, 1 YES)
# define PRO_COLLECT 1
// Defines if projectiles break after PRO_BOUNCE_LIMIT bounces (0 NO, 1 YES)
# define PRO_BOUNCE_BREAK 1
// Defines how many bounces it takes to break a projectile
# define PRO_BOUNCE_LIMIT 15

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
	int			ft;
}				t_map;

/* --- MAP --- */
# define MAP_SPRITE "./textures/bonus/map.xpm"
# define BG_SPRITE "./textures/bonus/bg.xpm"
# define COIN_SPRITE "./textures/bonus/coin.xpm"
// Number of frames between each animation frame of the coins
# define COIN_SPEED 6
// Threshold over which coins stop being animated (for performance)
# define MAXCOINS 60

/* --- MAP OBJECTS --- */
# define EMPTY '0'
# define WALL '1'
# define PLAYER 'P'
# define EXIT_CLOSE 'E'
# define EXIT_OPEN 'G'
# define COIN 'C'

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_vector	win_size;
	t_img		*image;
	t_player	*player;
	t_map		*map;
	t_xpm		*cursor;
	t_vector	last_cpos;
	t_vector	curs_pos;
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
# define CURSOR "./textures/bonus/cursor.xpm"

// Name of the game window
# define WINNAME "thepaqui's amazingly wasteful so_long"

/* --- GAME STATES --- */
# define GAME_ERROR 0
# define GAME_STARTUP 1
# define GAME_RUN 2
# define GAME_STOP 3
# define GAME_WIN 4

#endif
