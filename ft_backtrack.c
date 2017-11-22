/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:10:31 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/22 17:29:07 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "g_tetris.h"

int				ft_detecttetri(t_tlist *lst, int x, int y, char **map)
{
	int size;
	int i;
	int j;
	int n;

	if (x < 0 || y < 0)
		return (0);
	size = 0;
	while (map[size])
		size++;
	i = 0;
	n = lst->type;
	while (g_tetris[n - 1].tab[i])
	{
		j = 0;
		while (g_tetris[n - 1].tab[i][j])
		{
			if (g_tetris[n - 1].tab[i][j] == '#')
			{
				if (y + j >= (size + j))
					return (0);
				if (x + i >= (size + i))
					return (0);
				if (map[y + i][x + j] != '.')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void			ft_inserttetri(t_tlist *lst, int x, int y, char **map)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	n = lst->type;
	while (g_tetris[n - 1].tab[i])
	{
		j = 0;
		while (g_tetris[n - 1].tab[i][j])
		{
			if (g_tetris[n - 1].tab[i][j] == '#')
			{
				map[y + i][x + j] = lst->id;
			}
			j++;
		}
		i++;
	}
}

void			ft_backtrack(t_tlist *lst, char **map)
{
	ft_showtab(map);
	ft_putchar('\n');
	if (ft_detecttetri(lst->next, 0, 6, map))
		ft_inserttetri(lst->next, 0, 6, map);
	ft_putchar('\n');
	if (ft_detecttetri(lst, 1, 6, map))
		ft_inserttetri(lst, 1, 6, map);
	ft_putchar('\n');
	ft_showtab(map);
}
