/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrifile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:50:34 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/19 21:22:50 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

/*
** Open filename and return the tetriminos into a list of int
*/

t_list			*ft_readfile(int fd)
{
	t_list	*lst;
	char	c[21];
	int		lastread;
	int		r;

	lst = ft_lstnew(NULL, 0);
	while ((r = read(fd, c, 21)))
	{
		c[20] = '\0';
		ft_lsttail(&lst, ft_lstnew(ft_itoa(ft_tetridetector(c)), 21));
		lastread = r;
	}
	if (lastread == 21 || r != 0)
		return (NULL);
	close(fd);
	return (lst->next);
}
