/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:05:18 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/08 12:23:20 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

int	free_n_0(int **int_array, char **str_array)
{
	int i;

	i = 0;
	if (int_array && *int_array)
		free (*int_array);
	if (str_array)
	{
		while (str_array[i])
		{
			free (str_array[i]);
			i ++;
		}
		free (str_array);
	}
	return (0);
}

t_list	*find_max(t_list *stack)
{
	while (stack)
	{
		if (stack->max == 1)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}

t_list	*find_min(t_list *stack)
{
	while (stack)
	{
		if (stack->min == 1)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}
