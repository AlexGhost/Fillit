/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:51:15 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/23 12:53:59 by acourtin         ###   ########.fr       */
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
void				ft_backtrack(struct s_tlist *lst);
void				ft_showtab(char **tab);
int					ft_tlstsize(struct s_tlist *lst);
struct s_tlist		*ft_tlstnew(int n, char c);
int					ft_sqrt(int n);
int					ft_recur(struct s_tlist *lst, char **map, int size_map);
void				ft_freemap(char **map, int size_map);

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
