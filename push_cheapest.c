/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:48:24 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/09 19:04:59 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	push_cheapest(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	cheapest = find_cheapest(stack_a);
	if (!cheapest->target)
		rot_no_target(stack_a, stack_b, cheapest);
	else if (cheapest->above_m && cheapest->target->above_m)
		rot_above_m(stack_a, stack_b, cheapest);
	else if (!(cheapest)->above_m && !(cheapest)->target->above_m)
		rot_below_m(stack_a, stack_b, cheapest);
	else if (cheapest->direction == 0)
		rot_diff_pos_0(stack_a, stack_b, cheapest);
	else if (cheapest->direction == 1)
		rot_diff_pos_1(stack_a, stack_b, cheapest);
	else if (cheapest->direction == -1)
		rot_diff_pos_min1(stack_a, stack_b, cheapest);
	pb(stack_a, stack_b);
	if (!cheapest->target)
		rb(stack_b);
}

t_list	*find_cheapest(t_list **stack_a)
{
	t_list	*ptr_a;
	t_list	*cheapest;

	ptr_a = *stack_a;
	cheapest = ptr_a;
	while (ptr_a)
	{
		if (ptr_a->price < cheapest->price)
			cheapest = ptr_a;
		else if (ptr_a->price == cheapest->price)
			if (ptr_a->max || ptr_a->min)
				cheapest = ptr_a;
		ptr_a = ptr_a->next;
	}
	return (cheapest);
}
