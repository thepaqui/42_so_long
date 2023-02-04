/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:17:13 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/04 16:07:02 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = b;
	i = -1;
	while (++i < len)
		*str++ = (unsigned char)c;
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	ft_memset(mem, 0, count * size);
	return (mem);
}

char	**ft_free_tab(char **tab, int index)
{
	if (index == -1)
	{
		while (tab[++index])
			free(tab[index]);
		index = -1;
	}
	while (index >= 0)
	{
		if (tab[index])
			free(tab[index]);
		index--;
	}
	if (tab)
		free(tab);
	return (NULL);
}

t_img	*free_img(t_img *image)
{
	if (!image)
		return (NULL);
	if (image->img)
	{
		free(image->img);
		image->img = NULL;
	}
	if (image->add)
	{
		free(image->add);
		image->add = NULL;
	}
	free(image);
	image = NULL;
	return (NULL):
}

t_game	*free_game(t_game *game)
{
	if (!game)
		return (NULL);
	if (MLX)
	{
		free(MLX);
		MLX = NULL;
	}
	if (WIN)
	{
		free(WIN);
		WIN = NULL;
	}
	if (IMG)
		IMG = free_image(IMG);
	if (MAP)
		MAP = ft_free_tab(MAP, -1);
	free(game);
	game = NULL;
	return (NULL);
}
