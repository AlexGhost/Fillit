/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetridetector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:20:30 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/22 20:34:20 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "g_forms.h"

/*
** 2 ^ n
*/

static int		ft_pow(int n)
{
	if (n == 0)
		return (1);
	return (2 * ft_pow(n - 1));
}

/*
** Return the decimal from the binary map str (. is 0 and # is 1)
*/

static int		ft_tetri_binary(char *str)
{
	int i;
	int j;
	int res;

	i = 0;
	j = 15;
	res = 0;
	while (str[i])
	{
		if (str[i] == '#')
			res += ft_pow(j--);
		else if (str[i] == '.')
			j--;
		else if (str[i] != '\n')
			return (-1);
		else if (i % 5 != 4)
			return (-1);
		i++;
	}
	return (res);
}

/*
** Return the number of the tetriminos detected in str
*/

static int		ft_bincmp(char *str)
{
	int		bin;
	int		i;

	i = 0;
	bin = ft_tetri_binary(str);
	while (g_forms[i].binary != 0)
	{
		if (bin == g_forms[i].binary)
			return (g_forms[i].form);
		i++;
	}
	return (0);
}

/*
** Read the str and search for error
**
** Return -1 if it detects a wrong character
** Return -2 if length of str is not correct (not 20)
** Return -3 if there are more or less than 4 #
**
** Return the number of the tetriminos if no error
*/

int				ft_tetridetector(char *str)
{
	int i;
	int res;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (-1);
		if (str[i] == '#')
			count++;
		i++;
	}
	if (count != 4)
		return (-3);
	if (i != 20)
		return (-2);
	res = ft_bincmp(str);
	return (res);
}
