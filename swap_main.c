/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:37:39 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/09 12:27:20 by klukiano         ###   ########.fr       */
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
			else if (stack_a->array_size == 4)
				sort_4(&stack_a, &stack_b);
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
			if (i < stack_a_head->array_size - 1)
			{
				list_ptr->next = ft_lstnew(NULL);
				list_ptr = list_ptr->next;
			}
			i ++;
		}
		free_n_0(NULL, str_array);
	}
	else
	{
		while (++i < ac)
		{
			list_ptr->number = ft_atoi(av[i]);
			if (i < ac - 1)
			{
				list_ptr->next = ft_lstnew(NULL);
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
	if ((*stack_a)->array_size == 2)
		return ;
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
		ptr_a->price = s_price_up;
		ptr_a->direction = 1;
		if (s_price_down < s_price_up)
		{
			ptr_a->price = s_price_down;
			// was +1
			ptr_a->direction = -1;
		}
		if (!target_node)
			ptr_a->price += 1;
		//wtf i changed it to 2 and it decreased by 700!!!
		// and the logic was rght before, but i think it now prioritizes the ones without a target less?
		// tje best result for now was from +1 +1 + 2 and +1 for opp strange, 6 out of 500 cases and bigget is 5555
		// but... its wrong
		// i will try price down 0
		// 0 0 1 1 is 4 out of 500 max move 5588
		// now opp 0
		// ok the best result was 0 0 1 0 4/500 and 5538
		// last test with no target +2;
		// intresting... 0 0 2 0 is 3/500 but the highest max with 5597
		// target +3 just for fun...
		// 3/500 but had a move of 5601. thats too much and already close to messing for the result. need to try rising opposite price with 0 0 1 1
		// 0 0 1 1 test again --- great result with 3/500 and 5514, running it again
		// now its 4/500 5580 kinda similar
		// last try out of 1000 - 0 0 1 0
		// omg it was 5665 thats too much, same test with  0 0 1 1 was 5129!!!
		// last try with 1000 tests of 0 0 1 1 and then other worse tester
		// 7/1000 max move 5544, average 5153 - good enough! now to the worse tester
		// same, 6 or 7 out of 1000, max 5567 - good!
		if (target_node && ptr_a->above_m != target_node->above_m)
		{
			if ((opposite_price(ptr_a, target_node)) + 1 < ptr_a->price)
			{
				ptr_a->price = opposite_price(ptr_a, target_node) + 1;
				ptr_a->direction = 0;
			}
		}
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
	t_list	*ptr_a;
	t_list	*ptr_b;
	long	diff;
	long	smallest_diff;

	ptr_a = stack_a;
	while (ptr_a)
	{
		ptr_b = stack_b;
		smallest_diff = LONG_MAX;
		ptr_a->target = NULL;
		while (ptr_b)
		{
			if (ptr_b->number < ptr_a->number)
			{
				diff = (long)ptr_a->number - (long)ptr_b->number;
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
		}
	}
	else if (cheapest->above_m != cheapest->target->above_m)
	{
		if (cheapest->direction == 0)
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
		else if (cheapest->direction == 1)
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
		else if (cheapest->direction == -1)
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
	}
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
	t_list	*ptr_a;
	t_list	*ptr_b;
	long	diff;
	long	smallest_diff;

	ptr_b = stack_b;
	while (ptr_b)
	{
		ptr_a = stack_a;
		smallest_diff = LONG_MAX;
		ptr_b->target = NULL;
		while (ptr_a)
		{
			if (ptr_a->number > ptr_b->number)
			{
				diff = (long)ptr_a->number - (long)ptr_b->number;
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
