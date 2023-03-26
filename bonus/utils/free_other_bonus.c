/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_other_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:55:23 by thepaqui          #+#    #+#             */
/*   Updated: 2023/03/26 14:38:15 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

t_xpm	*free_xpm(t_xpm *xpm)
{
	if (!xpm)
		return (NULL);
	if (xpm->palette)
	{
		free(xpm->palette);
		xpm->palette = NULL;
	}
	if (xpm->token)
	{
		free(xpm->token);
		xpm->token = NULL;
	}
	if (xpm->spritesheet)
		xpm->spritesheet = ft_free_tab(xpm->spritesheet, -1);
	free(xpm);
	xpm = NULL;
	return (NULL);
}

static t_enemy	*clean_enemy(t_enemy *enemy)
{
	t_enemy	*tmp;

	if (enemy->next)
		tmp = enemy->next;
	else
		tmp = enemy->prev;
	if (enemy->prev)
		enemy->prev->next = enemy->next;
	if (enemy->next)
		enemy->next->prev = enemy->prev;
	free(enemy);
	return (tmp);
}

t_enemy	*clean_enemy_list(t_game *game, t_enemy *enemies)
{
	game->need_enemy_refresh = 0;
	while (enemies->prev)
		enemies = enemies->prev;
	while (enemies)
	{
		if (!enemies->alive)
		{
			if (!enemies->next && !enemies->prev)
				return (enemies);
			enemies = clean_enemy(enemies);
		}
		else
		{
			if (!enemies->next)
				break ;
			enemies = enemies->next;
		}
	}
	while (enemies->prev)
		enemies = enemies->prev;
	return (enemies);
}
