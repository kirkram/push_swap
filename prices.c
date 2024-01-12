/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prices.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:39:20 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/12 14:29:23 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	price_a(t_list *stack_a, t_list *stack_b)
{
	t_list	*target_node;

	find_positions_and_minmax(stack_a);
	find_positions_and_minmax(stack_b);
	assign_target_a(stack_a, stack_b);
	while (stack_a)
	{
		target_node = stack_a->target;
		if (!target_node)
			target_node = find_min(stack_b);
		price_and_dir_up(stack_a, target_node);
		price_and_dir_down(stack_a, target_node);
		if (stack_a->above_m != target_node->above_m)
		{
			if ((opposite_price(stack_a, target_node)) < stack_a->price)
			{
				stack_a->price = opposite_price(stack_a, target_node);
				stack_a->direction = 0;
			}
		}
		if (!stack_a->target)
			stack_a->price += 1;
		stack_a = stack_a->next;
	}
}

void	price_and_dir_up(t_list *ptr_a, t_list *target)
{
	int	price;

	price = ptr_a->current_position;
	if (ptr_a->target && target->current_position > price)
		price = target->current_position;
	else if (!ptr_a->target && target->current_position + 1 > price)
		price = target->current_position + 1;
	ptr_a->price = price;
	ptr_a->direction = 1;
}

void	price_and_dir_down(t_list *ptr_a, t_list *target)
{
	int	price;
	int	t_arr_s;

	t_arr_s = target->array_size;
	price = ptr_a->array_size - ptr_a->current_position;
	if (ptr_a->target && t_arr_s - target->current_position > price)
		price = target->array_size - target->current_position;
	else if (!ptr_a->target && t_arr_s - target->current_position - 1 > price)
		price = target->array_size - target->current_position - 1;
	if (price < ptr_a->price)
	{
		ptr_a->price = price;
		ptr_a->direction = -1;
	}
}

int	opposite_price(t_list *ptr_a, t_list *target)
{
	int	price;
	int	size_a;
	int	size_b;
	int	targ_pos;

	size_a = ptr_a->array_size;
	size_b = target->array_size;
	targ_pos = target->current_position;
	if (ptr_a->above_m == 1)
	{
		if (ptr_a->target)
			price = ptr_a->current_position + size_b - targ_pos;
		else
			price = ptr_a->current_position + size_b - targ_pos - 1;
	}
	else
	{
		if (ptr_a->target)
			price = size_a - ptr_a->current_position + targ_pos;
		else
			price = size_a - ptr_a->current_position + targ_pos + 1;
	}
	return (price);
}
