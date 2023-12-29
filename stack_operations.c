/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:22:51 by klukiano          #+#    #+#             */
/*   Updated: 2023/12/26 17:22:51 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void sa(t_list **stack_a)
{
	int temp;

	if (*stack_a && (*stack_a)->next)
	{
		temp = (*stack_a)->number;
		(*stack_a)->number = (*stack_a)->next->number;
		(*stack_a)->next->number = temp;
	}
}

void sb(t_list **stack_b)
{
	int temp;

	if (*stack_b && (*stack_b)->next)
	{
		temp = (*stack_b)->number;
		(*stack_b)->number = (*stack_b)->next->number;
		(*stack_b)->next->number = temp;
	}
}

void ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void pa(t_list **stack_a, t_list **stack_b)
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

void pb(t_list **stack_a, t_list **stack_b)
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

void ra(t_list **stack_a)
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

void rb(t_list **stack_b)
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

void rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void rra(t_list **stack_a)
{
	t_list *temp;
	t_list *ptr;

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
}

void rrb(t_list **stack_b)
{
	t_list *temp;
	t_list *ptr;

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

void rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
