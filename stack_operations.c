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

void	sa(t_list **stack_a)
{
	t_list	*temp;

	if (*stack_a && (*stack_a)->next)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = (*stack_a)->next;
		(*stack_a)->next = temp;
	}
	ft_printf("sa\n");
}

void	sb(t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b && (*stack_b)->next)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = (*stack_b)->next;
		(*stack_b)->next = temp;
	}
	ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_a && (*stack_a)->next)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = (*stack_a)->next;
		(*stack_a)->next = temp;
	}
	if (*stack_b && (*stack_b)->next)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = (*stack_b)->next;
		(*stack_b)->next = temp;
	}
	ft_printf("ss\n");
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b)
	{
		temp = (*stack_b)->next;
		(*stack_b)->next = *stack_a;
		*stack_a = *stack_b;
		*stack_b = temp;
	}
	ft_printf("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_a)
	{
		temp = (*stack_a)->next;
		(*stack_a)->next = *stack_b;
		*stack_b = *stack_a;
		*stack_a = temp;
	}
	ft_printf("pb\n");
}

void	ra(t_list **stack_a)
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
	ft_printf("ra\n");
}

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
