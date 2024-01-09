/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:13:25 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/09 18:38:05 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>

int	check_input(int ac, char **av)
{
	int		*int_array;
	char	**str_array;
	int		i;

	i = 0;
	if (ac == 2)
	{
		if (av[1][0] == '\0')
			return (0);
		str_array = ft_split(av[1], ' ');
		while (str_array[i])
			i++;
		int_array = malloc(i * sizeof(int));
		if (!int_array)
			return (free_n_0(NULL, str_array));
		return (input_two(ac, str_array, int_array));
	}
	else
	{
		int_array = malloc((ac - 1) * sizeof(int));
		if (!int_array)
			return (0);
		str_array = malloc((ac) * sizeof(char *));
		return (input_many(ac, av, str_array, int_array));
	}
}

int	input_two(int ac, char **str_array, int *int_array)
{
	int		i;
	int		j;

	i = 0;
	while (str_array[i])
	{
		j = 0;
		while (str_array[i][j])
		{
			if (!check_input_character(str_array, ac, i, j))
				return (free_n_0(&int_array, str_array));
			j++;
		}
		int_array[i] = ft_atoi(str_array[i]);
		i ++;
	}
	if (!check_input_array(int_array, i, str_array))
		return (free_n_0(&int_array, str_array));
	return (free_n_0(&int_array, str_array) + 1);
}

int	input_many(int ac, char **av, char **str_array, int *int_array)
{
	int		i;
	int		j;

	i = 0;
	while (i < ac - 1)
	{
		str_array[i] = ft_substr(av[i + 1], 0, -1);
		i ++;
	}
	str_array[i] = NULL;
	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!check_input_character(av, ac, i, j))
				return (free_n_0(&int_array, str_array));
			j++;
		}
		int_array[i - 1] = ft_atoi(av[i]);
	}
	if (!check_input_array(int_array, ac - 1, str_array))
		return (free_n_0(&int_array, str_array));
	return (free_n_0(&int_array, str_array) + 1);
}

int	check_input_character(char **av, int ac, int i, int j)
{
	if (ac > 2 && !ft_isdigit(av[i][j]) && av[i][j] != '-')
		return (0);
	if (av[i][j] == '-')
	{
		if (!ft_isdigit(av[i][j + 1]) || av[i][j + 1] == 0)
			return (0);
		else if (j != 0 && av[i][j - 1] != ' ')
			return (0);
	}
	else if (!ft_isdigit(av[i][j]) && av[i][j] != ' ')
		return (0);
	else if (j == 0 && av[i][j] == '0' && ft_isdigit(av[i][j + 1]))
		return (0);
	else if (j != 0 && av[i][j] == '0' )
		if (!ft_isdigit(av[i][j - 1]) && ft_isdigit(av[i][j + 1]))
			return (0);
	return (1);
}

int	check_input_array(int *array, int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (array[i] == array[j])
				return (0);
			j++;
		}
		if (array[i] == 0 && av[i][0] != '0')
			return (0);
		if (array[i] == -1 && av[i][0] != '-')
			return (0);
		i++;
	}
	return (1);
}
