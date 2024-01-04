/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:13:25 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/04 16:34:54 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>

int	is_sorted(t_list *stack_a)
{
	t_list	*ptr;

	ptr = stack_a;
	while (ptr->next)
	{
		if (ptr->number > ptr->next->number)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	is_sorted_reverse(t_list *stack_b)
{
	t_list	*ptr;

	if (!stack_b)
		return (1);
	ptr = stack_b;
	while (ptr->next)
	{
		if (ptr->number < ptr->next->number)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	check_input_array(int *array, int ac, char **av)
{
	int i;
	int j;

	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (array[i] == array[j])
				return (0);
			j++;
		}
		if (array[i] == 0 && av[i + 1][0] != '0')
			return (0);
		if (array[i] == -1 && av[i + 1][0] != '-')
			return (0);
		i++;
	}
	return (1);
}

int	check_input(int ac, char **av)
{
	int i;
	int j;
	int *array;

	array = malloc((ac - 1) * sizeof(int));
	if (!array)
		return (0);
	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-')
			{
				if (!ft_isdigit(av[i][j + 1]))
				{
					free (array);
					return (0);
				}
				else if (j != 0 && av[i][j - 1] != ' ')
				{
					free (array);
					return (0);
				}
			}
			else if (!ft_isdigit(av[i][j]) && av[i][j] != ' ')
			{
				free (array);
				return (0);
			}
			j++;
		}
		array[i - 1] = ft_atoi(av[i]);
	}
	if (!check_input_array(array, ac, av))
	{
		// i = 0;
		// printf("check_input_array error \n");
		// while (i < ac - 1)
		// {
		// 	printf("[%d] = %d\n", i, array[i]);
		// 	i ++;
		// }
		return (0);
	}

	free (array);
	return (1);
}
