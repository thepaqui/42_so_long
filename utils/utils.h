/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:47:33 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/11 17:43:07 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include "../srcs/game.h"

/* TEXT */
void	ft_putchar_fd(const char c, int fd);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putendl_fd(const char *s, int fd);
int		isinset(char c, const char *s);
int		ft_atoi(const char *str);

/* MEMORY */
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	**ft_free_tab(char **tab, int index);
t_xpm	*free_xpm(t_xpm *xpm);
t_game	*free_game(t_game *game);

/* STRINGS */
int		ft_strlen(const char *s);
int		ft_strclen(const char *str, const char *set);
char	*ft_strndup(const char *str, int n);
int		ft_strlcpy(char *dst, const char *src, int dstsize);
int		ft_strncmp(const char *s1, const char *s2, int n);
char	**ft_split(const char *s, const char *set);

/* GNL */
size_t	ft_strlcat_gnl(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin_gnl(char *s1, char const *s2);
char	*get_next_line(int fd, int *err);
# define BUFFER_SIZE 10

/* ERROR */
void	ft_error(int code, t_game *game, char *file);
void	errno_error(int code, t_game *game, char *file);
void	error_handling(int code, t_game *game, char *file);
# define TOOFEWARGS -1
# define TOOMANYARGS -2
# define NOPATH -3
# define NOEXT -4
# define NOTBER -5
# define MALLOCFAIL -6
# define WRONGCHAR -7
# define NOSTART -8
# define TOOMANYSTART -9
# define NOEXIT -10
# define TOOMANYEXIT -11
# define NOCOLLECT -12
# define NOTRECT -13
# define BADWALLS -14
# define NOWAY -15
# define NOMONEY -16
# define NOTXPM -17
# define BADXPM -18
# define NOTENOUGHXPMINFO -19
# define TOOMUCHXPMINFO -20
# define BADXPMDIM -21
# define BADXPMCPP -22
# define BADPALSIZE -23
# define BADPALTOKEN -24
# define BADPALFORM -25
# define BADPALCOLOR -26
# define BADPALKEYWORD -27
# define LASTCODE 28

#endif
