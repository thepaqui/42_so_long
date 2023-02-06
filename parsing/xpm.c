/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:10:42 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/06 17:11:01 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parse.h"
#define XPMBUFFER 6000 //works for 64 x 64 textures only!

/*static void	get_palette(t_xpm *xpm)
{

}*/

static t_xpm	*parse_xpm_text_to_struct(char *xpm, int *err)
{
	t_xpm	*ret;
	char	**split;

	ret = ft_calloc(1, sizeof(t_xpm));
	if (!ret)
	{
		*err = MALLOCFAIL;
		return (NULL);
	}
	split = ft_split(xpm, "/");
	if (!split)
	{
		*err = MALLOCFAIL;
		free(ret);
		return (NULL);
	}
	for(int i = 0;split[i];i++) //----------------------------------
	{ //------------------------------------------------------------
		printf("split[%i] = { \"%s\" }\n", i, split[i]); //-------------
	} //------------------------------------------------------------
	//get_palette(ret);
	ft_free_tab(split, -1); // ?
	return (ret);
}

t_xpm	*parse_xpm(char *file, int *err)
{
    int		fd;
	int		read_ret;
	char	text[XPMBUFFER];
	t_xpm	*xpm;

	errno = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		*err = errno;
		return (NULL);
	}
	errno = 0;
	read_ret = read(fd, text, XPMBUFFER - 1);
	if (read_ret <= 0)
	{
		*err = errno;
		close(fd);
		return (NULL);
	}
	text[read_ret] = '\0';
	close(fd);
	xpm = parse_xpm_text_to_struct(text, err);
	if (!xpm)
		return (NULL);
	return (xpm);
}