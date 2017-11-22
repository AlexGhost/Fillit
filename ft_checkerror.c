/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:00:07 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/22 14:05:32 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include "g_tetris.h"

void			ft_perror(int *error)
{
	ft_putendl("error");
	*error = 1;
}

void			ft_showtab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}

void			ft_checkerror(char *filename)
{
	t_list *lst_tetri;
	int		error;
	int		fd;

	error = 0;
	if ((fd = open(filename, O_RDONLY)))
	{
		lst_tetri = ft_readfile(fd);
		if (!lst_tetri)
			ft_perror(&error);
		if (ft_lstsize(lst_tetri) > 26)
			ft_perror(&error);
		while (lst_tetri && error == 0)
		{
			if (!(ft_atoi(lst_tetri->content) > 0))
				ft_perror(&error);
			//ft_showtab(g_tetris[ft_atoi(lst_tetri->content) - 1].tab);
			lst_tetri = lst_tetri->next;
		}
		close(fd);
	}
	ft_showtab(ft_map(2));
}
