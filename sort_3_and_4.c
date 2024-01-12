/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_and_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:51:32 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/12 11:40:33 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack_a)
{
	find_positions_and_minmax(*stack_a);
	if ((*stack_a)->min == 1 && (*stack_a)->next->max == 0)
		return ;
	else if ((*stack_a)->min == 1 && (*stack_a)->next->max == 1)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->max == 1 && (*stack_a)->next->min == 0)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->max == 1 && (*stack_a)->next->min == 1)
		ra(stack_a);
	else if ((*stack_a)->max == 0 && (*stack_a)->next->min == 1)
		sa(stack_a);
	else if ((*stack_a)->min == 0 && (*stack_a)->next->max == 1)
		rra(stack_a);
	find_positions_and_minmax((*stack_a));
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr_min;

	find_positions_and_minmax(*stack_a);
	ptr_min = find_min(*stack_a);
	if (ptr_min->current_position == 1)
		sa(stack_a);
	else if (ptr_min->current_position == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (ptr_min->current_position == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_3(stack_a);
}
