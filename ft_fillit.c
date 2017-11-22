/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:39:27 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/22 21:10:04 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_backtrack(t_tlist *lst)
{
	char	**map;
	int		size_map;

	size_map = ft_sqrt(ft_tlstsize(lst) * 4);
	map = ft_map(size_map);
	while (!ft_recur(lst, map, size_map))
	{
		ft_freemap(map, size_map);
		size_map++;
		map = ft_map(size_map);
	}
	ft_showtab(map);
}

int				main(int ac, char **av)
{
	int			error;
	int			fd;

	error = 0;
	if (ac != 2 || (fd = open(av[1], O_RDONLY)) <= 0)
		ft_perror(&error);
	else
	{
		ft_checkerror(av[1]);
	}
	return (0);
}
