/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:39:01 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/04 16:07:00 by thepaqui         ###   ########.fr       */
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

typedef struct	s_game
{
	void	*mlx;
	void	*window;
	t_img	*image;
	char	**map;
	int		start[2];
	int		exit[2];
	int		nbcoins;
}				t_game;
# define MLX game->mlx

# define WIN game->window
# define WINWID 720
# define WINHEI 480
# define WINNAME "thepaqui's so_long!"

# define IMG game->image
# define IMGIMG IMG->img
# define IMGADD IMG->add
# define IMGBPP IMG->bits_per_pixel
# define IMGLINLEN IMG->line_len
# define IMGENDIAN IMG->endian

# define MAP game->map
# define XSTART game->start[0]
# define YSTART game->start[1]
# define XEXIT game->exit[0]
# define YEXIT game->exit[1]
# define NBCOINS game->nbcoins

#endif
