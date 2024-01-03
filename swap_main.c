#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <string.h>

t_list		*create_stack_a(int ac, char **av, t_list **save_params);
t_list		*create_stack_b(t_list *save_params);
void		p_swap(t_list **stack_a, t_list **stack_b, t_list *save_params);
int			check_input(int ac, char **av);
int			check_input_array(int *array, int ac, char **av);
int			is_sorted(t_list *stack_a);
void		sort_3(t_list **stack_a);
void		find_positions_and_minmax(t_list *stack);
void		find_min_max(t_list *stack);
void		assign_target_a(t_list *stack_a, t_list *stack_b);
void		assign_a(t_list *stack_a, t_list *stack_b);
void		push_cheapest(t_list **stack_a, t_list **stack_b);
t_list		*find_cheapest(t_list **stack_a);
int			price_up(t_list *ptr_a, t_list *target);
int			price_down(t_list *ptr_a, t_list *target);
int			opposite_price(t_list *ptr_a, t_list *target);

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*save_params;
	t_list	*stack_b;

	save_params = ft_lstnew(NULL); //dont forget to free
	if (check_input(ac, av) && ac > 1)
	{

		stack_a = create_stack_a(ac, av, &save_params);
		if (!stack_a)
			return(printf("Error\n"));
		//stack_b = create_stack_b(save_params);
		stack_b = NULL;
		p_swap(&stack_a, &stack_b, save_params);
		printf("Printing stack_a...\n");
		while (stack_a)
		{
			//printf("the posi is %d\n", stack_a->current_position);
			printf("%d\n", stack_a->number); //ft_printf
			stack_a = stack_a->next;
		}
		printf("Printing stack_b...\n");
		while (stack_b)
		{
			//printf("the posi is %d\n", stack_a->current_position);
			printf("%d\n", stack_b->number); //ft_printf
			stack_b = stack_b->next;
		}
	}
	else
		printf("Error\n");
	free(save_params);
	return (0);
}

t_list	*create_stack_a(int ac, char **av, t_list **save_params)
{
	t_list	*stack_a_head;
	t_list	*list_ptr;
	char	**str_array;
	int		i;
	//int		sign;

	i = 0;
	stack_a_head = ft_lstnew(NULL);
	list_ptr = stack_a_head;
	if (ac == 2)
	{
		str_array = ft_split(av[1], ' ');
		while (str_array[i])
			i ++;
		(*save_params)->array_size = i;
		i = 0;
		while (i < (*save_params)->array_size)
		{
			list_ptr->number = ft_atoi(str_array[i]);
			if (str_array[i][0] != '-' && list_ptr->number == -1)
				return (0);
			else if (str_array[i][0] == '-' && list_ptr->number == 0)
				return (0);
			if (i < (*save_params)->array_size - 1) // i hate this condition need to fix
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
			if (i < ac - 1) // i hate this condition need to fix
			{
				ft_lstadd_back(&list_ptr, ft_lstnew(NULL));
				list_ptr = list_ptr->next;
			}
		}
		(*save_params)->array_size = i - 1;
	}
	return (stack_a_head);
}

void	p_swap(t_list **stack_a, t_list **stack_b, t_list *save_params)
{
	(*stack_a)->array_size = save_params->array_size;
	if ((*stack_a)->array_size == 3)
		sort_3(stack_a);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if ((*stack_b)->number < (*stack_b)->next->number)
		sb(stack_b);
	assign_a(*stack_a, *stack_b);
	// int *array_visual_a = malloc((*stack_a)->array_size * sizeof(int));
	// int *array_visual_b = malloc((*stack_a)->array_size * sizeof(int));
	t_list *ptr_a;
	t_list *ptr_b;
	while ((*stack_a)->array_size > 3)
	{
		push_cheapest(stack_a, stack_b);
		assign_a(*stack_a, *stack_b);
		ptr_a = *stack_a;
		ptr_b = *stack_b;

		printf("Stack A\t\tStack B\n");
		printf("-------\t\t-------\n");

		// Iterate as long as either stack has elements
		while (ptr_a != NULL || ptr_b != NULL)
		{
			// Check if stack_a has an element
			if (ptr_a != NULL)
			{
				printf("%d\t\t", ptr_a->number);
				ptr_a = ptr_a->next;
			}
			else
				printf(" \t\t");
			// Check if stack_b has an element
			if (ptr_b != NULL)
			{
				printf("%d\n", ptr_b->number);
				ptr_b = ptr_b->next;
			}
			else
				printf("\n");
		}
		printf("\n");
	}
	//assign_a(*stack_a, *stack_b);
	while((*stack_b)->max != 1)
		rb(stack_b);
	if ((*stack_a)->array_size == 3)
	{
		printf("sort 3 after pushing\n");
		sort_3(stack_a);
	}
	if (is_sorted(*stack_a) && is_sorted(*stack_b))
		printf("First phase sorted properly\n");
	else
		printf("There is a mistake in phase 1\n");
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
	else
		printf("There is an error in sort_3\n");
	find_positions_and_minmax((*stack_a));
}

void	find_positions_and_minmax(t_list *stack)
{
	t_list	*ptr;
	int		i;

	ptr = stack;
	i = 0; // careful with that 0 when calculating
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
	//find_price(stack);
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

void	assign_a(t_list *stack_a, t_list *stack_b)
{
	t_list	*ptr_a;
	t_list	*target_node;
	int		s_price_up;
	int		s_price_down;

	ptr_a = stack_a;
	find_positions_and_minmax(stack_a);
	find_positions_and_minmax(stack_b);
	assign_target_a(stack_a, stack_b);
	// if (stack_a->target)
	// 	printf("the target for the first A node is %d", stack_a->target->number);
	while (ptr_a)
	{
		target_node = ptr_a->target;
		s_price_up = price_up(ptr_a, target_node);
		s_price_down = price_down(ptr_a, target_node);
		ptr_a->price = s_price_up + 1;
		if (s_price_down < s_price_up)
			ptr_a->price = s_price_down + 1;
		if (target_node && ptr_a->above_m != target_node->above_m)
			if ((opposite_price(ptr_a, target_node) + 1) < ptr_a->price)
				ptr_a->price = opposite_price(ptr_a, target_node) + 1;
		ptr_a = ptr_a->next;
	}
}

void	assign_target_a(t_list *stack_a, t_list *stack_b)
{
	//could be modified to be used for stack b as well?
	t_list *ptr_a;
	t_list *ptr_b;
	int		diff;
	int		smallest_diff;

	int		testnumber;

	ptr_a = stack_a;
	while (ptr_a)
	{
		testnumber = ptr_a->number;
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

	cheapest = find_cheapest(stack_a);
	// NULL Point
	if (!cheapest->target)
	{
		if (cheapest->above_m)
			while (*stack_a != cheapest)
				ra(stack_a);
		else
			while (*stack_a != cheapest)
				rra(stack_a);
	}
	else if (cheapest->above_m && cheapest->target->above_m)
	{
		while (*stack_a != cheapest && *stack_b != cheapest->target)
		{
			if (*stack_a != cheapest && *stack_b != cheapest->target)
				rr(stack_a, stack_b);
			else if (*stack_a != cheapest)
				ra(stack_a);
			else if (*stack_b != cheapest->target)
				rb(stack_b);
			else
				printf("Mistake in the push stack 1\n");
		}

	}
	else if (!(cheapest)->above_m && !(cheapest)->target->above_m)
	{
		while (*stack_a != cheapest && *stack_b != cheapest->target)
		{
			if (*stack_a != cheapest && *stack_b != cheapest->target)
				rrr(stack_a, stack_b);
			else if (*stack_a != cheapest)
				rra(stack_a);
			else if (*stack_b != cheapest->target)
				rrb(stack_b);
			else
				printf("Mistake in the push stack 2\n");
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
		else
			printf("Mistake in the push stack 3\n");
	}
	else
		printf("Mistake in the push stack 4\n");
	pb(stack_a, stack_b);
	//if (!cheapest->target)
	//	rb(stack_b);
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
