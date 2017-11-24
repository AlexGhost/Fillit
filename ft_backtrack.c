/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:10:31 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/24 09:49:54 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "g_tetris.h"

/*
**		Return 1 if the tetriminos lst can be placed on map at coord x y
*/

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

/*
**		Erase the tetriminos lst on map at coord x y
*/

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

/*
**		Write the tetriminos lst on map at coord x y
*/

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

/*
**		Try to place all tetriminos in lst into the map of size size_map
**		Return 1 if successful
*/

int				ft_recur(t_tlist *lst, char **map, int size_map)
{
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

/*
**		Free the memory for the map of size size_map
*/

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
