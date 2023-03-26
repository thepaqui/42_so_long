/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:24:03 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/25 17:10:44 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include <fcntl.h>
# include "../checking/check.h"

/* MAP */
void	get_map(char *file, t_game *game);
int		get_coins_pos(t_map *map);

/* XPM */
int		get_tokens(char **tab, t_xpm *xpm);
int		get_colors(char **tab, t_xpm *xpm);
int		get_palette(t_xpm *xpm, char *raw_pal);
int		get_spritesheet(t_xpm *xpm, char *sprites);
t_xpm	*parse_xpm(char *file, int *err);
# define BUFSIZE 1000

/* COLOR */
int		is_keyword_valid(char *word);
int		get_argb_from_keyword(char *word, int *err);
# define KEYWORD_NB 23
# define WHITE 0x00FFFFFF

#endif
