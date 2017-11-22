/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:39:27 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/22 12:49:17 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
