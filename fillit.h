/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:51:15 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/22 16:11:30 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

int					ft_tetridetector(char *str);
struct s_tlist		*ft_readfile(int fd);
void				ft_checkerror(char *filename);
void				ft_perror(int *error);
char				**ft_map(int size);
void				ft_backtrack(struct s_tlist *lst, char **map);
void				ft_showtab(char **tab);
int					ft_tlstsize(struct s_tlist *lst);

typedef struct		s_forms
{
	int				binary;
	int				form;
}					t_forms;

typedef struct		s_insert
{
	int				form;
	char			*tab[5];
}					t_insert;

typedef struct		s_tlist
{
	int				type;
	char			id;
	struct s_tlist	*next;
}					t_tlist;

#endif
