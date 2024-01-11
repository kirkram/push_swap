/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:37:39 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/11 17:14:55 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <string.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (ac > 1 && check_input(ac, av))
	{
		stack_a = create_stack_a(ac, av);
		if (!stack_a)
			ft_putstr_fd("Error\n", 2);
		else if (!is_sorted(stack_a))
		{
			if (stack_a->array_size == 3)
				sort_3(&stack_a);
			else
				p_swap(&stack_a, &stack_b);
			p_swap_2(&stack_a, &stack_b);
		}
	}
	else if (ac == 1)
		return (0);
	else
		ft_putstr_fd("Error\n", 2);
	ft_lstclear(&stack_a, NULL);
	return (0);
}

void	p_swap(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->array_size == 2)
		return ;
	else if ((*stack_a)->array_size == 4)
	{
		sort_4(stack_a, stack_b);
		return ;
	}
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if ((*stack_b)->number < (*stack_b)->next->number)
		sb(stack_b);
	price_a(*stack_a, *stack_b);
	while ((*stack_a)->array_size > 3)
	{
		push_cheapest(stack_a, stack_b);
		price_a(*stack_a, *stack_b);
	}
	rot_b_to_top(stack_b);
	if ((*stack_a)->array_size == 3)
		sort_3(stack_a);
}

void	p_swap_2(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
	{
		assign_target_b(*stack_a, *stack_b);
		find_positions_and_minmax(*stack_a);
		if (!(*stack_b)->target)
			while (*stack_b && !(*stack_b)->target)
				pa(stack_a, stack_b);
		else
		{
			if ((*stack_b)->target->above_m)
				while (*stack_a != (*stack_b)->target)
					ra(stack_a);
			else
				while (*stack_a != (*stack_b)->target)
					rra(stack_a);
			pa(stack_a, stack_b);
		}
	}
	final_rot(stack_a);
}
