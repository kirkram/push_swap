/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_stack_operations_2_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:19:33 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/12 11:39:48 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

void	apply_rb(t_list **stack_b)
{
	t_list	*temp;
	t_list	*ptr;

	if (*stack_b && (*stack_b)->next)
	{
		temp = *stack_b;
		ptr = *stack_b;
		while (ptr->next)
			ptr = ptr->next;
		*stack_b = (*stack_b)->next;
		ptr->next = temp;
		temp->next = NULL;
	}
}

void	apply_rr(t_list **stack_a, t_list **stack_b)
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
	if (*stack_b && (*stack_b)->next)
	{
		temp = *stack_b;
		ptr = *stack_b;
		while (ptr->next)
			ptr = ptr->next;
		*stack_b = (*stack_b)->next;
		ptr->next = temp;
		temp->next = NULL;
	}
}

void	apply_rra(t_list **stack_a)
{
	t_list	*temp;
	t_list	*ptr;

	if (*stack_a)
	{
		temp = *stack_a;
		ptr = *stack_a;
		while (ptr->next->next)
		{
			ptr = ptr->next;
		}
		*stack_a = ptr->next;
		ptr->next = NULL;
		(*stack_a)->next = temp;
	}
}

void	apply_rrb(t_list **stack_b)
{
	t_list	*temp;
	t_list	*ptr;

	if (*stack_b)
	{
		temp = *stack_b;
		ptr = *stack_b;
		while (ptr->next->next)
			ptr = ptr->next;
		*stack_b = ptr->next;
		ptr->next = NULL;
		(*stack_b)->next = temp;
	}
}

void	apply_rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*ptr;

	if (*stack_a)
	{
		temp = *stack_a;
		ptr = *stack_a;
		while (ptr->next->next)
			ptr = ptr->next;
		*stack_a = ptr->next;
		ptr->next = NULL;
		(*stack_a)->next = temp;
	}
	if (*stack_b)
	{
		temp = *stack_b;
		ptr = *stack_b;
		while (ptr->next->next)
			ptr = ptr->next;
		*stack_b = ptr->next;
		ptr->next = NULL;
		(*stack_b)->next = temp;
	}
}
