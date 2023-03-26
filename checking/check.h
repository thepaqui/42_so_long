/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:31:28 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/25 17:00:42 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H
# include "../utils/utils.h"

int		is_file_type(char *path, char *ext);
void	check_input(int ac, char **av, int *err);
int		check_map(t_game *game);
int		check_shape(t_game *game);
int		check_path(t_game *game);
int		check_xpm(char **xpm, t_xpm *stru);

#endif
