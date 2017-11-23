/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:00:07 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/23 13:07:07 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**		Write error and end the program
*/

void			ft_perror(int *error)
{
	ft_putendl("error");
	*error = 1;
}

/*
**		Draw the matrix tab
*/

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

/*
**			Check if there is any error in the file 
**				if there is any invalid tetriminos
**				if there are an invalid number of tetriminos
**			Execute backtracking if no error detected
*/

void			ft_checkerror(char *filename)
{
	t_tlist *lst_tetri;
	t_tlist *tmp;
	int		error;
	int		fd;

	error = 0;
	if ((fd = open(filename, O_RDONLY)))
	{
		lst_tetri = ft_readfile(fd);
		if (!lst_tetri)
			ft_perror(&error);
		if (ft_tlstsize(lst_tetri) > 26)
			ft_perror(&error);
		tmp = lst_tetri;
		while (tmp && error == 0)
		{
			if (tmp->type <= 0)
				ft_perror(&error);
			tmp = tmp->next;
		}
		close(fd);
		if (error == 0)
			ft_backtrack(lst_tetri);
	}
}
