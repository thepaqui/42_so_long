/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:39:01 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 15:11:35 by thepaqui         ###   ########.fr       */
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

typedef struct s_enemy
{
	int				type;
	int				alive;
	t_vector		pos;
	int				dist_to_player;
	int				dist_to_proj;
	int				speed;
	int				turn;
	int				dir;
	int				anim_len;
	int				cur_spr;
	struct s_enemy	*prev;
	struct s_enemy	*next;
}				t_enemy;

// Enemy density = 100 means there will be 1 enemy for every 100 FLOOR tiles
// In short, higher density means less enemies (weird i know)
# define ENEMY_DENSITY 15
// Defines maximum number of enemies
# define ENEMY_MAX 50
# define E_DEAD 0
# define E_GROUND 1
# define E_FLY_H 2
# define E_FLY_V 3
// Enemy speed for each enemy type (in pixels)
# define EG_SPEED 1
# define EFH_SPEED 2
# define EFV_SPEED 2
// Radius of circle enemy hitbox
# define ENEMY_HITBOX 10

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
	int			grounded;
	t_xpm		*sprite;
	int			anim_len;
	int			anim_state;
	int			anim_loops;
	int			throw;
	t_xpm		*pro;
	t_dblvector	pro_pos;
	t_dblvector	pro_dir;
	int			pro_anim_speed;
	int			pro_break_anim;
	int			pro_here;
	int			pro_bounces;
	int			pro_rethrow;
}				t_player;

/* --- PLAYER --- */
// Player speed (in pixels)
# define PLAYER_SPEED 4
// Player diagonal speed (in pixels)
# define PLAYER_DIAG_SPEED 3
// Size of square player hitbox
# define PLAYER_HITBOX 10

/* --- PLAYER STATES --- */
# define PIDLE 0
# define PMOVE 1
# define PCOIN 2
# define PTHROW 3
# define PTHROWEND 4
# define PWIN 5
# define PCHEER 6
# define PDEATH 7
# define PSPIN 8
# define PFAINT 9
# define PWAKE 10

/* --- PROJECTILE --- */
// Projectile speed (in pixels) (should be kept lower than 10)
# define PRO_SPEED 5
// Max number of projectiles on screen (anything other than 1 or 0 will bug)
# define PRO_LIMIT 1
// Size of square projectile hitbox
# define PRO_HITBOX 16
// Defines if projectiles can go through walls or not (0 NO, 1 YES)
// ------------- THIS SHOULD ABSOLUTELY BE 0 FOR FINAL PUSH -------------------
# define PRO_SPECTRAL 0
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
	int			floorsize;
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
	int			nbenemies;
	t_enemy		*enemies;
	int			need_enemy_refresh;
	t_xpm		*spr_eg;
	t_xpm		*spr_efh;
	t_xpm		*spr_efv;
	t_xpm		*cursor;
	t_vector	last_cpos;
	t_vector	curs_pos;
	t_xpm		*canvas;
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

// Name of the game window
# define WINNAME "SMW 42: Yoshi's Isolong"

/* --- GAME STATES --- */
# define GAME_ERROR 0
# define GAME_STARTUP 1
# define GAME_RUN 2
# define GAME_STOP 3
# define GAME_WIN 4
# define GAME_LOSE 5

#endif
