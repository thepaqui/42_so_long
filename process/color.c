/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:14:04 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/12 23:00:06 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	get_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

int	get_alpha(int argb)
{
	return ((argb >> 24) & 0xFF);
}

int	get_red(int argb)
{
	return ((argb >> 16) & 0xFF);
}

int	get_green(int argb)
{
	return ((argb >> 8) & 0xFF);
}

int	get_blue(int argb)
{
	return (argb & 0xFF);
}
