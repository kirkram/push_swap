/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_targets_and_positions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:46:21 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/12 13:50:17 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_target_a(t_list *stack_a, t_list *stack_b)
{
	t_list	*ptr_b;
	long	diff;
	long	smallest_diff;

	while (stack_a)
	{
		ptr_b = stack_b;
		smallest_diff = LONG_MAX;
		stack_a->target = NULL;
		while (ptr_b)
		{
			if (ptr_b->number < stack_a->number)
			{
				diff = (long)stack_a->number - (long)ptr_b->number;
				if (diff < smallest_diff)
				{
					smallest_diff = diff;
					stack_a->target = ptr_b;
				}
			}
			ptr_b = ptr_b->next;
		}
		stack_a = stack_a->next;
	}
}

void	find_positions_and_minmax(t_list *stack)
{
	t_list	*ptr;
	int		i;

	ptr = stack;
	i = 0;
	while (ptr)
	{
		ptr->current_position = i;
		ptr->min = 0;
		ptr->max = 0;
		ptr = ptr->next;
		i ++;
	}
	ptr = stack;
	while (ptr)
	{
		ptr->array_size = i;
		if (ptr->current_position <= (i + 1) / 2)
			ptr->above_m = 1;
		else
			ptr->above_m = 0;
		ptr = ptr->next;
	}
	find_min_max(stack);
}

void	find_min_max(t_list *stack)
{
	t_list	*ptr;
	int		min;
	int		max;

	ptr = stack;
	min = ptr->number;
	max = ptr->number;
	while (ptr)
	{
		if (ptr->number < min)
			min = ptr->number;
		if (ptr->number > max)
			max = ptr->number;
		ptr = ptr->next;
	}
	ptr = stack;
	while (ptr)
	{
		if (ptr->number == min)
			ptr->min = 1;
		if (ptr->number == max)
			ptr->max = 1;
		ptr = ptr->next;
	}
}

void	assign_target_b(t_list *stack_a, t_list *stack_b)
{
	t_list	*ptr_a;
	long	diff;
	long	smallest_diff;

	while (stack_b)
	{
		ptr_a = stack_a;
		smallest_diff = LONG_MAX;
		stack_b->target = NULL;
		while (ptr_a)
		{
			if (ptr_a->number > stack_b->number)
			{
				diff = (long)ptr_a->number - (long)stack_b->number;
				if (diff < smallest_diff)
				{
					smallest_diff = diff;
					stack_b->target = ptr_a;
				}
			}
			ptr_a = ptr_a->next;
		}
		stack_b = stack_b->next;
	}
}
