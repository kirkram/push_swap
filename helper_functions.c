/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:05:18 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/09 14:28:13 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

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

int	free_n_0(int **int_array, char **str_array)
{
	int	i;

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

void	print_current_stack(t_list *stack_a, t_list *stack_b)
{
	t_list	*ptr_a;
	t_list	*ptr_b;

	ft_printf("Stack A\t\tStack B\n");
	ft_printf("-------\t\t-------\n");
	ptr_a = stack_a;
	ptr_b = stack_b;
	while (ptr_a != NULL || ptr_b != NULL)
	{
		if (ptr_a != NULL)
		{
			ft_printf("%d\t\t", ptr_a->number);
			ptr_a = ptr_a->next;
		}
		else
			ft_printf(" \t\t");
		if (ptr_b != NULL)
		{
			ft_printf("%d\n", ptr_b->number);
			ptr_b = ptr_b->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("\n");
}
