/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:55:01 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/12 11:40:28 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list **stack_b)
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
	ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
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
	ft_printf("rr\n");
}

void	rra(t_list **stack_a)
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
	ft_printf("rra\n");
}

void	rrb(t_list **stack_b)
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
	ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
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
	ft_printf("rrr\n");
}
