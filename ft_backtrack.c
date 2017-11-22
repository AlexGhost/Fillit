/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:10:31 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/22 16:44:43 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "g_tetris.h"

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
	ft_inserttetri(lst->next, 8, 1, map);
	ft_inserttetri(lst, 0, 0, map);
	ft_showtab(map);
}
