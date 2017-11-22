/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:51:15 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/22 13:59:30 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

int					ft_tetridetector(char *str);
t_list				*ft_readfile(int fd);
void				ft_checkerror(char *filename);
void				ft_perror(int *error);
char				**ft_map(int size);

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

#endif
