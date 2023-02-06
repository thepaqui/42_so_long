/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:39:01 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/06 15:21:41 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GAME_H
# define GAME_H

typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct  s_xpm
{
    int     *palette;
    char    *token;
    char    *spritesheet;
}               t_xpm;

typedef struct	s_img
{
	void	*img;
	char	*add;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}				t_img;

# define PLAYER_SPRITE "./xpm/test.xpm" // change

typedef struct	s_player
{
	t_vector	*pos;
	int			up;
	int			down;
	int			left;
	int			right;
	int			state;
	t_xpm		*sprite;
}				t_player;

typedef struct	s_camera
{
	t_vector	*pos;
	t_vector	size;
}				t_camera;

# define MAP_SPRITE "./xpm/test.xpm" // change

typedef struct	s_map
{
	char		**map;
	t_vector	size;
	t_vector	start;
	t_vector	exit;
	int			nbcoins;
	t_xpm		*sprite;
}				t_map;

typedef struct	s_game
{
	void		*mlx;
	void		*window;
	t_img		*image;
	t_player	*player;
	t_camera	*camera;
	t_map		*map;
}				t_game;

/* MLX AND WINDOW */
# define MLX game->mlx
# define WIN game->window
# define WINWID 1024
# define WINHEI 896
# define WINNAME "thepaqui's so_long!"

/* WINDOW IMAGE */
# define IMG game->image
# define IMGIMG IMG->img
# define IMGADD IMG->add
# define IMGBPP IMG->bits_per_pixel
# define IMGLLEN IMG->line_len
# define IMGENDI IMG->endian

/* PLAYER */
# define PLAYER game->player
# define XPLAYER PLAYER->pos->x
# define YPLAYER PLAYER->pos->y
# define PUP PLAYER->up
# define PDO PLAYER->down
# define PLE PLAYER->left
# define PRI PLAYER->right
# define PSTATE PLAYER->state
# define PSPRITE PLAYER->sprite

/* PLAYER STATES */
# define PIDLE 0
# define PMOVUP 1
# define PMOVDOWN 2
# define PMOVLEFT 3
# define PMOVRIGHT 4

/* CAMERA */
# define CAM game->camera
# define XCAM CAM->pos->x
# define YCAM CAM->pos->y
# define CAMWID CAM->size.x
# define CAMHEI CAM->size.y

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

#endif
