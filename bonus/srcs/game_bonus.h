/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:39:01 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/08 18:58:31 by thepaqui         ###   ########.fr       */
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

# define SPR_DIM 32

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

# define PLAYER_SPRITE "./textures/32/ph32.xpm"
# define PRO_SPRITE "./textures/bonus/pro_ph.xpm"

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
}				t_player; // Add projectile animation

# define PLAYER_SPEED 4
# define PLAYER_DIAG_SPEED 3
# define PLAYER_COIN_ANIM_LEN 20 // number of frames between each coin animation frame
# define PLAYER_HITBOX 10 // size of square player hitbox
# define PLAYER_THROW_COOLDOWN 80 // cooldown between each projectile throw (in frames)

/* PLAYER STATES */
# define PIDLE 0
# define PMOVE 1
# define PCOIN 2
# define PTHROW 3
# define PTHROWEND 4 // might be superfluous
# define PDEATH 5

/* PROJECTILE */
# define PRO_SPEED 5
# define PRO_ANIM_LEN 3 // number of frames between each projectile animation frame
# define PRO_LIMIT 1 // Maximum number of projectiles on screen (anything other than 1 or 0 will glitch)
# define PRO_HITBOX 7 // size of square projectile hitbox

typedef struct s_map
{
	char		**map;
	t_xpm		*sprite;
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

# define MAP_SPRITE "./textures/32/map32.xpm"
# define COIN_SPRITE "./textures/32/coin32.xpm"
# define COIN_SPEED 6
# define MAXCOINS 120

/* MAP OBJECTS */
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
	int			end_frame;
	int			end_color;
	int			stop_frame;
	int			state;
}				t_game;

# define FONT "./textures/32/vfont32.xpm"
# define CURSOR "./textures/bonus/cursor.xpm"

/* GAME STATES */
# define WINNAME "BONUS~~~<3"
# define GAME_ERROR 0
# define GAME_STARTUP 1
# define GAME_RUN 2
# define GAME_STOP 3
# define GAME_WIN 4

#endif
