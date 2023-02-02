/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:47:33 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/02 18:44:25 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include <unistd.h>
# include "../game.h"

/* TEXT */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		isinset(char c, const char *s);

/* MEMORY */
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	**ft_free_tab(char **tab, int index);

/* STRINGS */
int		ft_strlen(char *s);
char	*ft_strndup(const char *str, int n);

/* GNL */
size_t	ft_strlcat_gnl(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin_gnl(char *s1, char const *s2);
char	*get_next_line(int fd, int *err);
# define BUFFER_SIZE 10

/* ERROR */
void	errno_error(int code, t_game *game);
void	ft_error(int code, t_game *game);
# define TOOFEWARGS 1
# define TOOMANYARGS 2
# define NOPATH 3
# define NOEXT 4
# define NOTBER 5
# define MALLOCFAIL 6
# define WRONGCHAR 7
# define NOSTART 8
# define TOOMANYSTART 9
# define NOEXIT 10
# define TOOMANYEXIT 11
# define NOCOLLECT 12
# define LASTCODE 13

#endif
