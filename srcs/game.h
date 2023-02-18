/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:39:01 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/18 23:20:15 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

# define SPR_DIM 32

typedef struct  s_xpm
{
    int     *palette;
    char    *token;
	int		pal_size;
    char    **spritesheet;
	int		cur_spr;
	int		spr_per_line;
	int		spr_per_column;
}               t_xpm;

typedef struct	s_img
{
	void	*img;
	char	*add;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

# define PLAYER_SPRITE "./textures/32/ph_full32.xpm"

typedef struct	s_player
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

# define PLAYER_SPEED 3
# define PLAYER_DIAG_SPEED 2
# define PLAYER_COIN_ANIM_LEN 20
# define PLAYER_HITBOX 10

typedef struct	s_map
{
	char		**map;
	t_xpm		*sprite;
	t_vector	size;
	t_vector	start;
	t_vector	exit;
	int			nbcoins;
	int			totalcoins;
	t_xpm		*coin_spr;
	t_vector	*coin_pos;
	int			coin_speed;
}				t_map;

# define MAP_SPRITE "./textures/32/map_full32.xpm"
# define COIN_SPRITE "./textures/32/coin_full32.xpm"
# define COIN_SPEED 7

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_vector	win_size;
	t_img		*image;
	t_player	*player;
	t_map		*map;
	int			last_moves;
	int			moves;
	int			state;
}				t_game;

/* GAME STATES */
# define GAME_ERROR 0
# define GAME_STARTUP 1
# define GAME_RUN 2
# define GAME_STOP 3

/* MLX AND WINDOW */
# define MLX game->mlx
# define WIN game->win
# define WINWID game->win_size.x
# define WINHEI game->win_size.y
# define WINNAME "thepaqui's so_long!"

/* WINDOW IMAGE */
# define IMG game->image
# define IMGIMG IMG->img
# define IMGADD IMG->add
# define IMGBPP IMG->bpp
# define IMGLLEN IMG->line_len
# define IMGENDI IMG->endian

/* PLAYER */
# define XPLAYER game->player->pos.x
# define YPLAYER game->player->pos.y
# define PUP game->player->up
# define PDO game->player->down
# define PLE game->player->left
# define PRI game->player->right
# define PSTATE game->player->state
# define PSPRITE game->player->sprite

/* PLAYER STATES */
# define PIDLE 0
# define PMOVE 1
# define PCOIN 2

/* CAMERA */
# define CAMWID game->win_size.x
# define CAMHEI game->win_size.y

/* MAP */
# define MAP game->map
# define MAPMAP MAP->map
# define MAPWID MAP->size.x
# define MAPHEI MAP->size.y
# define XSTART MAP->start.x
# define YSTART MAP->start.y
# define XEXIT MAP->exit.x
# define YEXIT MAP->exit.y
# define NBCOINS MAP->nbcoins

/* MAP OBJECTS */
# define EMPTY '0'
# define WALL '1'
# define PLAYER 'P'
# define EXIT_CLOSE 'E'
# define EXIT_OPEN 'G'
# define COIN 'C'

#endif
