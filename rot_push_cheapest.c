/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_push_cheapest.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:41:59 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/09 16:42:51 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	rot_above_m(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	while (*stack_a != cheapest || *stack_b != cheapest->target)
	{
		if (*stack_a != cheapest && *stack_b != cheapest->target)
			rr(stack_a, stack_b);
		else if (*stack_a != cheapest)
			ra(stack_a);
		else if (*stack_b != cheapest->target)
			rb(stack_b);
	}
}

void	rot_below_m(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	while (*stack_a != cheapest || *stack_b != cheapest->target)
	{
		if (*stack_a != cheapest && *stack_b != cheapest->target)
			rrr(stack_a, stack_b);
		else if (*stack_a != cheapest)
			rra(stack_a);
		else if (*stack_b != cheapest->target)
			rrb(stack_b);
	}
}

void	rot_diff_pos_0(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	if (cheapest->above_m)
	{
		while (*stack_a != cheapest)
			ra(stack_a);
		while (*stack_b != cheapest->target)
			rrb(stack_b);
	}
	else if (!(cheapest)->above_m)
	{
		while (*stack_a != cheapest)
			rra(stack_a);
		while (*stack_b != cheapest->target)
			rb(stack_b);
	}
}

void	rot_diff_pos_1(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	while (*stack_a != cheapest || *stack_b != cheapest->target)
	{
		if (*stack_a != cheapest && *stack_b != cheapest->target)
			rr(stack_a, stack_b);
		else if (*stack_a != cheapest)
			ra(stack_a);
		else if (*stack_b != cheapest->target)
			rb(stack_b);
	}
}

void	rot_diff_pos_min1(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	while (*stack_a != cheapest || *stack_b != cheapest->target)
	{
		if (*stack_a != cheapest && *stack_b != cheapest->target)
			rrr(stack_a, stack_b);
		else if (*stack_a != cheapest)
			rra(stack_a);
		else if (*stack_b != cheapest->target)
			rrb(stack_b);
	}
}
