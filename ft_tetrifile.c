/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrifile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:50:34 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/23 13:11:34 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

/*
**		Return size of lst
*/

int				ft_tlstsize(t_tlist *lst)
{
	int			count;
	t_tlist		*curlist;

	count = 0;
	curlist = lst;
	if (!curlist)
		return (0);
	while (curlist->next)
	{
		curlist = curlist->next;
		count++;
	}
	count++;
	return (count);
}

/*
**		Return a new tlist with n for type and c for id
*/

t_tlist			*ft_tlstnew(int n, char c)
{
	t_tlist *list;

	list = (t_tlist*)malloc(sizeof(t_tlist));
	if (!list)
		return (NULL);
	if (n > 0 && c != 0)
	{
		list->type = n;
		list->id = c;
	}
	else
	{
		list->type = 0;
		list->id = 0;
	}
	list->next = NULL;
	return (list);
}

/*
**		Add new_elem at the end of alst
*/

void			ft_tlsttail(t_tlist **alst, t_tlist *new_elem)
{
	t_tlist		*curlist;

	curlist = *alst;
	if (curlist)
	{
		while (curlist->next)
			curlist = curlist->next;
		curlist->next = new_elem;
	}
	else
		*alst = new_elem;
}

/*
** Open filename and return the tetriminos into a list of int
*/

t_tlist			*ft_readfile(int fd)
{
	t_tlist	*lst;
	char	c[21];
	int		lastread;
	int		buffer;
	int		i;

	lst = ft_tlstnew(0, 0);
	i = 0;
	while ((buffer = read(fd, c, 21)))
	{
		if (buffer == 21)
			c[20] = '\0';
		else
			c[buffer] = '\0';
		ft_tlsttail(&lst, ft_tlstnew(ft_tetridetector(c), 'A' + i));
		lastread = buffer;
		i++;
	}
	if (lastread == 21 || buffer != 0)
		return (NULL);
	close(fd);
	return (lst->next);
}
