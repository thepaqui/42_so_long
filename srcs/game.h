/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:39:01 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/05 21:49:49 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GAME_H
# define GAME_H

typedef struct	s_img
{
	void	*img;
	char	*add;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}				t_img;

typedef struct	s_player
{
	int	pos_x;
	int	pos_y;
	int	up;
	int	down;
	int	left;
	int	right;
}				t_player;

typedef struct	s_camera
{
	int	pos_x;
	int	pos_y;
	int	width;
	int	height;
}				t_camera;

typedef struct	s_map
{
	char	**map;
	int		width;
	int		height;
	int		start[2];
	int		exit[2];
	int		nbcoins;
}				t_map;

typedef struct	s_game
{
	void		*mlx;
	void		*window;
	t_img		*image;
	t_img		*imgbuf;
	t_player	*player;
	t_camera	*camera;
	t_map		*map;
}				t_game;

/* MLX AND WINDOW */
# define MLX game->mlx
# define WIN game->window
# define WINWID 256
# define WINHEI 224
# define WINNAME "thepaqui's so_long!"

/* WINDOW IMAGE */
# define IMG game->image
# define IMGIMG IMG->img
# define IMGADD IMG->add
# define IMGBPP IMG->bits_per_pixel
# define IMGLLEN IMG->line_len
# define IMGENDI IMG->endian

/* BUFFER IMAGE */
# define BIMG game->imgbuf
# define BIMGIMG BIMG->img
# define BIMGADD BIMG->add
# define BIMGBPP BIMG->bits_per_pixel
# define BIMGLLEN BIMG->line_len
# define BIMGENDI BIMG->endian

/* PLAYER */
# define PLAYER game->player
# define XPLAYER PLAYER->pos_x
# define YPLAYER PLAYER->pos_y
# define PUP PLAYER->up
# define PDO PLAYER->down
# define PLE PLAYER->left
# define PRI PLAYER->right

/* CAMERA */
# define CAM game->camera
# define XCAM CAM->pos_x
# define YCAM CAM->pos_y
# define CAMWID CAM->width
# define CAMHEI CAM->height

/* MAP */
# define MAP game->map
# define MAPMAP MAP->map
# define MAPWID MAP->width
# define MAPHEI MAP->height
# define XSTART MAP->start[0]
# define YSTART MAP->start[1]
# define XEXIT MAP->exit[0]
# define YEXIT MAP->exit[1]
# define NBCOINS MAP->nbcoins

#endif
