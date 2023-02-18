/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:24:03 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/18 23:14:46 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include <fcntl.h>
# include <unistd.h>
# include "../utils/utils.h"
# include "../checking/check.h"
# include "../srcs/game.h"

/* MAP */
void	get_map(char *file, t_game *game);
int		get_coins_pos(t_map *map);

/* XPM */
int		get_tokens(char **tab, t_xpm *xpm);
int		get_colors(char **tab, t_xpm *xpm);
int		get_palette(t_xpm *xpm, char *raw_pal);
int		get_spritesheet(t_xpm *xpm, char *sprites);
t_xpm   *parse_xpm(char *file, int *err);

/* COLOR */
int		is_keyword_valid(char *word);
int		get_argb_from_keyword(char *word, int *err);
# define KEYWORD_NB 23
# define WHITE 0x00FFFFFF

#endif
