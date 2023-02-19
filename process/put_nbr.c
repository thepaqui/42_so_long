/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:33:43 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/19 22:42:16 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

static int	get_number_offset(unsigned int n)
{
	int	offset;

	offset = 0;
	while (n > 9)
	{
		offset++;
		n /= 10;
	}
	return (offset);
}

void	put_nbr_to_img(unsigned int n, t_vector pos, t_game *game, int color)
{
	int	offset;

	offset = get_number_offset(n);
	pos.x += offset * SPR_DIM;
	if (n > 9)
	{
		pos.x -= SPR_DIM * offset;
		put_nbr_to_img(n / 10, pos, game, color);
		pos.x += SPR_DIM * offset;
		put_nbr_to_img(n % 10, pos, game, color);
	}
	else
		put_char_to_img(n + 48, pos, game, color);
}
