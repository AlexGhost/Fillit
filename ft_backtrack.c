/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:10:31 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/22 21:10:13 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "g_tetris.h"

int				ft_detecttetri(t_tlist *lst, int x, int y, char **map)
{
	int		size;
	int		i;
	int		j;

	if (x < 0 || y < 0)
		return (0);
	size = 0;
	while (map[size])
		size++;
	i = 0;
	while (g_tetris[lst->type - 1].tab[i])
	{
		j = 0;
		while (g_tetris[lst->type - 1].tab[i][j])
		{
			if (g_tetris[lst->type - 1].tab[i][j] == '#')
				if (y + i >= size || x + j >= size || map[y + i][x + j] != '.')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void			ft_erasetetri(t_tlist *lst, int x, int y, char **map)
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
				map[y + i][x + j] = '.';
			j++;
		}
		i++;
	}
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
				map[y + i][x + j] = lst->id;
			j++;
		}
		i++;
	}
}

int				ft_recur(t_tlist *lst, char **map, int size_map)
{
	int		i;
	int		x;
	int		y;

	y = 0;
	if (!lst)
		return (1);
	while (y < size_map)
	{
		x = 0;
		while (x < size_map)
		{
			if (ft_detecttetri(lst, x, y, map))
			{
				ft_inserttetri(lst, x, y, map);
				if (ft_recur(lst->next, map, size_map))
					return (1);
				else
					ft_erasetetri(lst, x, y, map);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void			ft_freemap(char **map, int size_map)
{
	int		i;

	i = 0;
	while (i < size_map)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
