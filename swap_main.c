/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:37:39 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/05 17:51:19 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <string.h>
#include <unistd.h>

t_list		*create_stack_a(int ac, char **av);
void		p_swap(t_list **stack_a, t_list **stack_b);
int			check_input(int ac, char **av);
int			is_sorted(t_list *stack_a);
void		sort_3(t_list **stack_a);
void		find_positions_and_minmax(t_list *stack);
void		find_min_max(t_list *stack);
void		assign_target_a(t_list *stack_a, t_list *stack_b);
void		price_a(t_list *stack_a, t_list *stack_b);
void		push_cheapest(t_list **stack_a, t_list **stack_b);
t_list		*find_cheapest(t_list **stack_a);
int			price_up(t_list *ptr_a, t_list *target);
int			price_down(t_list *ptr_a, t_list *target);
int			opposite_price(t_list *ptr_a, t_list *target);
void		print_current_stack(t_list *stack_a, t_list *stack_b);
t_list		*find_max(t_list *stack);
void		p_swap_2(t_list **stack_a, t_list **stack_b);
void		assign_target_b(t_list *stack_a, t_list *stack_b);
t_list		*find_min(t_list *stack);
void		sort_4(t_list **stack_a, t_list **stack_b);

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (check_input(ac, av) && ac > 1)
	{
		stack_a = create_stack_a(ac, av);
		if (!stack_a)
		{
			write(STDERR_FILENO, "Error\n", 7);
			return (0);
		}
		if (!is_sorted(stack_a))
		{
			stack_b = NULL;
			if (stack_a->array_size == 3)
				sort_3(&stack_a);
			else if (stack_a->array_size == 4)
				sort_4(&stack_a, &stack_b);
			else
				p_swap(&stack_a, &stack_b);
			p_swap_2(&stack_a, &stack_b);
		}
		// if (is_sorted(stack_a))
		// {
		// 	ft_printf("Sorted!\n");
		// 	print_current_stack(stack_a, stack_b);
		// }
		// else
		// 	ft_printf("Not sorted!\n");
	}
	else if (ac == 1)
		return (0);
	else
		write(STDERR_FILENO, "Error\n", 7);
	ft_lstclear(&stack_a, NULL);
	return (0);
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

t_list	*create_stack_a(int ac, char **av)
{
	t_list	*stack_a_head;
	t_list	*list_ptr;
	char	**str_array;
	int		i;

	i = 0;
	stack_a_head = ft_lstnew(NULL);
	list_ptr = stack_a_head;
	if (ac == 2)
	{
		str_array = ft_split(av[1], ' ');
		while (str_array[i])
			i ++;
		stack_a_head->array_size = i;
		i = 0;
		while (i < stack_a_head->array_size)
		{
			list_ptr->number = ft_atoi(str_array[i]);
			if (str_array[i][0] != '-' && list_ptr->number == -1)
				return (0);
			else if (str_array[i][0] == '-' && list_ptr->number == 0)
				return (0);
			if (i < stack_a_head->array_size - 1)
			{
				ft_lstadd_back(&list_ptr, ft_lstnew(NULL));
				list_ptr = list_ptr->next;
			}
			i ++;
		}
	}
	else
	{
		while (++i < ac)
		{
			list_ptr->number = ft_atoi(av[i]);
			if (i < ac - 1)
			{
				ft_lstadd_back(&list_ptr, ft_lstnew(NULL));
				list_ptr = list_ptr->next;
			}
		}
		stack_a_head->array_size = i - 1;
	}
	return (stack_a_head);
}

void	p_swap(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr;

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
	ptr = find_max(*stack_b);
	if (ptr->above_m)
		while ((*stack_b)->max != 1)
			rb(stack_b);
	else if (!ptr->above_m)
		while ((*stack_b)->max != 1)
			rrb(stack_b);
	if ((*stack_a)->array_size == 3)
		sort_3(stack_a);
}

void	p_swap_2(t_list **stack_a, t_list **stack_b)
{
	t_list *min_n;

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
	find_positions_and_minmax(*stack_a);
	min_n = find_min(*stack_a);
	if (min_n->above_m == 1)
		while (*stack_a != min_n)
			ra(stack_a);
	else if (min_n->above_m == 0)
		while (*stack_a != min_n)
			rra(stack_a);
}

void	print_current_stack(t_list *stack_a,t_list *stack_b)
{
	t_list	*ptr_a;
	t_list	*ptr_b;

	ft_printf("Stack A\t\tStack B\n");
	ft_printf("-------\t\t-------\n");
	ptr_a = stack_a;
	ptr_b = stack_b;
	while (ptr_a != NULL || ptr_b != NULL)
	{
		if (ptr_a != NULL)
		{
			ft_printf("%d\t\t", ptr_a->number);
			ptr_a = ptr_a->next;
		}
		else
			ft_printf(" \t\t");
		if (ptr_b != NULL)
		{
			ft_printf("%d\n", ptr_b->number);
			ptr_b = ptr_b->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("\n");
}


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
	//else
	//	ft_printf("There is an error in sort_3\n");
	find_positions_and_minmax((*stack_a));
}

void	price_a(t_list *stack_a, t_list *stack_b)
{
	t_list	*ptr_a;
	t_list	*target_node;
	int		s_price_up;
	int		s_price_down;

	ptr_a = stack_a;
	find_positions_and_minmax(stack_a);
	find_positions_and_minmax(stack_b);
	assign_target_a(stack_a, stack_b);
	while (ptr_a)
	{
		target_node = ptr_a->target;
		s_price_up = price_up(ptr_a, target_node);
		s_price_down = price_down(ptr_a, target_node);
		ptr_a->price = s_price_up + 1;
		if (s_price_down < s_price_up)
			ptr_a->price = s_price_down + 1;
		if (!target_node)
			ptr_a->price += 1;
		if (target_node && ptr_a->above_m != target_node->above_m)
			if ((opposite_price(ptr_a, target_node) + 1) < ptr_a->price)
				ptr_a->price = opposite_price(ptr_a, target_node) + 1;
		ptr_a = ptr_a->next;
	}
}

void	find_positions_and_minmax(t_list *stack)
{
	t_list	*ptr;
	int		i;

	ptr = stack;
	i = 0;
	while (ptr)
	{
		ptr->current_position = i;
		ptr->min = 0;
		ptr->max = 0;
		ptr = ptr->next;
		i ++;
	}
	ptr = stack;
	while (ptr)
	{
		ptr->array_size = i;
		if (ptr->current_position < (i + 1) / 2)
			ptr->above_m = 1;
		else
			ptr->above_m = 0;
		ptr = ptr->next;
	}
	find_min_max(stack);
}

void	find_min_max(t_list *stack)
{
	t_list	*ptr;
	int		min;
	int		max;

	ptr = stack;
	min = ptr->number;
	max = ptr->number;
	while (ptr)
	{
		if (ptr->number < min)
			min = ptr->number;
		if (ptr->number > max)
			max = ptr->number;
		ptr = ptr->next;
	}
	ptr = stack;
	while (ptr)
	{
		if (ptr->number == min)
			ptr->min = 1;
		if (ptr->number == max)
			ptr->max = 1;
		ptr = ptr->next;
	}
}

void	assign_target_a(t_list *stack_a, t_list *stack_b)
{
	t_list *ptr_a;
	t_list *ptr_b;
	int		diff;
	int		smallest_diff;

	ptr_a = stack_a;
	while (ptr_a)
	{
		ptr_b = stack_b;
		smallest_diff = INT_MAX;
		ptr_a->target = NULL;
		while (ptr_b)
		{
			if (ptr_b->number < ptr_a->number)
			{
				diff = ptr_a->number - ptr_b->number;
				if (diff < smallest_diff)
				{
					smallest_diff = diff;
					ptr_a->target = ptr_b;
				}
			}
			ptr_b = ptr_b->next;
		}
		ptr_a = ptr_a->next;
	}
}

void	push_cheapest(t_list **stack_a, t_list **stack_b)
{
	t_list *cheapest;
	t_list *min_n;


	cheapest = find_cheapest(stack_a);
	if (!cheapest->target)
	{
		min_n = find_min(*stack_b);

		if (cheapest->above_m && min_n->above_m)
		{
			while (*stack_a != cheapest && min_n->next)
				rr(stack_a, stack_b);
			while (*stack_a != cheapest)
				ra(stack_a);
			while (min_n->next)
				rb(stack_b);
		}
		else if (!cheapest->above_m && !min_n->above_m)
		{
			while (*stack_a != cheapest && min_n->next)
				rrr(stack_a, stack_b);
			while (*stack_a != cheapest)
				rra(stack_a);
			while (min_n->next)
				rrb(stack_b);
		}
		else
		{
			if (cheapest->above_m)
				while (*stack_a != cheapest)
					ra(stack_a);
			else if (!cheapest->above_m)
				while (*stack_a != cheapest)
					rra(stack_a);
			if (min_n->above_m)
				while (min_n->next)
					rb(stack_b);
			else if (!min_n->above_m)
				while (min_n->next)
					rrb(stack_b);
		}
	}
	else if (cheapest->above_m && cheapest->target->above_m)
	{
		while (*stack_a != cheapest || *stack_b != cheapest->target)
		{
			if (*stack_a != cheapest && *stack_b != cheapest->target)
				rr(stack_a, stack_b);
			else if (*stack_a != cheapest)
				ra(stack_a);
			else if (*stack_b != cheapest->target)
				rb(stack_b);
			//else
			//	ft_printf("Mistake in the push_cheapest 1\n");
		}
	}
	else if (!(cheapest)->above_m && !(cheapest)->target->above_m)
	{
		while (*stack_a != cheapest || *stack_b != cheapest->target)
		{
			if (*stack_a != cheapest && *stack_b != cheapest->target)
				rrr(stack_a, stack_b);
			else if (*stack_a != cheapest)
				rra(stack_a);
			else if (*stack_b != cheapest->target)
				rrb(stack_b);
			//else
			//	ft_printf("Mistake in the push_cheapest 2\n");
		}
	}
	else if (cheapest->above_m != cheapest->target->above_m)
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
		//else
		//	ft_printf("Mistake in the push_cheapest 3\n");
	}
	//else
	//	ft_printf("Mistake in the push_cheapest 4\n");
	pb(stack_a, stack_b);
	if (!cheapest->target)
		rb(stack_b);
}

t_list	*find_cheapest(t_list **stack_a)
{
	t_list *ptr_a;
	t_list *cheapest;

	ptr_a = *stack_a;
	cheapest = ptr_a;
	while (ptr_a)
	{
		if (ptr_a->price < cheapest->price)
			cheapest = ptr_a;
		ptr_a = ptr_a->next;
	}
	return (cheapest);
}

int	price_up(t_list *ptr_a, t_list *target)
{
	int price;

	price = ptr_a->current_position;
	if (target && target->current_position > price)
		price = target->current_position;
	return (price);
}

int	price_down(t_list *ptr_a, t_list *target)
{
	int price;

	price = ptr_a->array_size - ptr_a->current_position;
	if (target && target->array_size - target->current_position > price)
		price = target->array_size - target->current_position;
	return (price);
}

int	opposite_price(t_list *ptr_a, t_list *target)
{
	int price;
	int size_a;
	int size_b;

	size_a = ptr_a->array_size;
	size_b = target->array_size;
	if (ptr_a->above_m == 1)
		price = ptr_a->current_position + size_b - target->current_position;
	else
		price = size_a - ptr_a->current_position + target->current_position;
	return (price);
}


void	assign_target_b(t_list *stack_a, t_list *stack_b)
{
	t_list *ptr_a;
	t_list *ptr_b;
	int		diff;
	int		smallest_diff;

	ptr_b = stack_b;
	while (ptr_b)
	{
		ptr_a = stack_a;
		smallest_diff = INT_MAX;
		ptr_b->target = NULL;
		while (ptr_a)
		{
			if (ptr_a->number > ptr_b->number)
			{
				diff = ptr_a->number - ptr_b->number;
				if (diff < smallest_diff)
				{
					smallest_diff = diff;
					ptr_b->target = ptr_a;
				}
			}
			ptr_a = ptr_a->next;
		}
		ptr_b = ptr_b->next;
	}
}
