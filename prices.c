/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prices.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:39:20 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/09 18:50:34 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	price_a(t_list *stack_a, t_list *stack_b)
{
	t_list	*target_node;

	find_positions_and_minmax(stack_a);
	find_positions_and_minmax(stack_b);
	assign_target_a(stack_a, stack_b);
	while (stack_a)
	{
		target_node = stack_a->target;
		price_and_dir_up(stack_a, target_node);
		price_and_dir_down(stack_a, target_node);
		if (!target_node)
			stack_a->price += 1;
		if (target_node && stack_a->above_m != target_node->above_m)
		{
			if ((opposite_price(stack_a, target_node)) + 1 < stack_a->price)
			{
				stack_a->price = opposite_price(stack_a, target_node) + 1;
				stack_a->direction = 0;
			}
		}
		stack_a = stack_a->next;
	}
}

void	price_and_dir_up(t_list *ptr_a, t_list *target)
{
	int	price;

	price = ptr_a->current_position;
	if (target && target->current_position > price)
		price = target->current_position;
	ptr_a->price = price;
	ptr_a->direction = 1;
}

void	price_and_dir_down(t_list *ptr_a, t_list *target)
{
	int	price;

	price = ptr_a->array_size - ptr_a->current_position;
	if (target && target->array_size - target->current_position > price)
		price = target->array_size - target->current_position;
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

	size_a = ptr_a->array_size;
	size_b = target->array_size;
	if (ptr_a->above_m == 1)
		price = ptr_a->current_position + size_b - target->current_position;
	else
		price = size_a - ptr_a->current_position + target->current_position;
	return (price);
}
