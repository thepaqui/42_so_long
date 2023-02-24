/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:55:23 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/22 23:08:21 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_xpm	*free_xpm(t_xpm *xpm)
{
	if (!xpm)
		return (NULL);
	if (xpm->palette)
		free(xpm->palette);
	if (xpm->token)
		free(xpm->token);
	if (xpm->spritesheet)
		ft_free_tab(xpm->spritesheet, -1);
	free(xpm);
	xpm = NULL;
	return (NULL);
}
