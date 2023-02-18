/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:36:36 by thepaqui          #+#    #+#             */
/*   Updated: 2023/02/17 18:44:25 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

static int	check_palette_basic(char *pal_info, int pal_size)
{
	char	**tab;
	char	**subtab;
	int		err;

	tab = ft_split(pal_info, ",\n\"");
	if (!tab)
		return (MALLOCFAIL);
	err = 0;
	subtab = ft_split(tab[0], " ");
	if (!subtab)
	{
		ft_free_tab(tab, -1);
		return (MALLOCFAIL);
	}
	if (!subtab[3])
		err = NOTENOUGHXPMINFO;
	else if (subtab[4])
		err = TOOMUCHXPMINFO;
	ft_free_tab(subtab, -1);
	if (!err)
		if (!tab[pal_size] || tab[pal_size + 1])
			err = BADPALSIZE;
	ft_free_tab(tab, -1);
	return (err);
}

static int	check_properties(char *is, int should, t_xpm *xpm)
{
	char	**tab;
	int		err;

	tab = ft_split(is, " ,\"\n");
	if (!tab)
		return (MALLOCFAIL);
	xpm->spr_per_line = ft_atoi(tab[0]) / SPR_DIM;
	xpm->spr_per_column = ft_atoi(tab[1]) / SPR_DIM;
	err = 0;
	if (xpm->spr_per_line <= 0 || xpm->spr_per_column <= 0
		|| ft_atoi(tab[0]) % should || ft_atoi(tab[1]) % should)
		err = BADXPMDIM;
	if (!err)
		if (ft_atoi(tab[3]) != 1)
			err = BADXPMCPP;
	if (!err)
	{
		xpm->pal_size = ft_atoi(tab[2]);
		err = check_palette_basic(is, xpm->pal_size);
	}
	ft_free_tab(tab, -1);
	return (err);
}

int	check_xpm(char **xpm, t_xpm *structure)
{
	int	err;

	if (ft_strncmp(xpm[0], "* XPM *", 7))
		return (BADXPM);
	if (ft_strncmp(xpm[2], "* columns rows colors chars-per-pixel *", 39))
		return (BADXPM);
	if (ft_strncmp(xpm[4], "* pixels *", 10))
		return (BADXPM);
	err = check_properties(xpm[3], SPR_DIM, structure);
	return (err);
}