/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_stack_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:04:57 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/10 16:40:55 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	apply_sa(t_list **stack_a)
{
	t_list	*temp;

	if (*stack_a && (*stack_a)->next)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = (*stack_a)->next;
		(*stack_a)->next = temp;
	}
}

void	apply_sb(t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b && (*stack_b)->next)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = (*stack_b)->next;
		(*stack_b)->next = temp;
	}
}

void	apply_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b)
	{
		temp = (*stack_b)->next;
		(*stack_b)->next = *stack_a;
		*stack_a = *stack_b;
		*stack_b = temp;
	}
}

void	apply_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_a)
	{
		temp = (*stack_a)->next;
		(*stack_a)->next = *stack_b;
		*stack_b = *stack_a;
		*stack_a = temp;
	}
}

void	apply_ra(t_list **stack_a)
{
	t_list	*temp;
	t_list	*ptr;

	if (*stack_a && (*stack_a)->next)
	{
		temp = *stack_a;
		ptr = *stack_a;
		while (ptr->next)
			ptr = ptr->next;
		*stack_a = (*stack_a)->next;
		ptr->next = temp;
		temp->next = NULL;
	}
}
