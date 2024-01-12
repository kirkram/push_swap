/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:40:42 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/12 15:16:26 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_rot(t_list **stack_a)
{
	t_list	*min_n;

	find_positions_and_minmax(*stack_a);
	min_n = find_min(*stack_a);
	if (min_n->above_m == 1)
		while (*stack_a != min_n)
			ra(stack_a);
	else if (min_n->above_m == 0)
		while (*stack_a != min_n)
			rra(stack_a);
}

void	rot_b_to_top(t_list **stack_b)
{
	t_list	*ptr;

	ptr = find_max(*stack_b);
	if (ptr->above_m)
		while ((*stack_b)->max != 1)
			rb(stack_b);
	else if (!ptr->above_m)
		while ((*stack_b)->max != 1)
			rrb(stack_b);
}

void	rot_no_target(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	t_list	*min_n;

	min_n = find_min(*stack_b);
	if (cheapest->direction == 1)
	{
		while (*stack_a != cheapest && min_n->next)
			rr(stack_a, stack_b);
		while (*stack_a != cheapest)
			ra(stack_a);
		while (min_n->next)
			rb(stack_b);
	}
	else if (cheapest->direction == -1)
	{
		while (*stack_a != cheapest && min_n->next)
			rrr(stack_a, stack_b);
		while (*stack_a != cheapest)
			rra(stack_a);
		while (min_n->next)
			rrb(stack_b);
	}
	else
		rot_notrgt_opp(stack_a, stack_b, cheapest, min_n);
}

void	rot_notrgt_opp(t_list **a, t_list **b, t_list *cheapest, t_list *min_n)
{
	if (cheapest->above_m)
		while (*a != cheapest)
			ra(a);
	else if (!cheapest->above_m)
		while (*a != cheapest)
			rra(a);
	if (min_n->current_position < (min_n->array_size + 1) / 2)
		min_n->above_m = 1;
	else
		min_n->above_m = 0;
	if (min_n->above_m)
		while (min_n->next)
			rb(b);
	else if (!min_n->above_m)
		while (min_n->next)
			rrb(b);
}
