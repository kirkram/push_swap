#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <string.h>

t_list		*create_stack_a(int ac, char **av, t_list **save_params);
t_list		*create_stack_b(t_list *save_params);
t_list		*p_swap(t_list *stack_a, t_list *stack_b, t_list *save_params);
int			check_input(int ac, char **av);
int			check_input_array(int *array, int ac, char **av);
int			is_sorted(t_list *stack_a);
t_list		*sort_3(t_list *stack_a);
void		find_positions_and_minmax(t_list *stack);
void		find_min_max(t_list *stack);
void		assign_target_a(t_list *stack_a, t_list *stack_b);
void		find_price_a(t_list *stack_a, t_list *stack_b);

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
		stack_b = create_stack_b(save_params);
		stack_a = p_swap(stack_a, stack_b, save_params);
		while (stack_a)
		{
			printf("the posi is %d\n", stack_a->current_position);
			printf("%d\n", stack_a->number); //ft_printf
			stack_a = stack_a->next;
		}
	}
	else
		printf("Error\n");
	free(save_params);
	return (0);
}

int check_input(int ac, char **av)
{
	int i;
	int j;
	int *array;

	array = malloc((ac - 1) * sizeof(int));
	if (!array)
		return (0);
	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-')
			{
				if (!ft_isdigit(av[i][j + 1]))
				{
					free (array);
					return (0);
				}
				else if (j != 0 && av[i][j - 1] != ' ')
				{
					free (array);
					return (0);
				}
			}
			else if (!ft_isdigit(av[i][j]) && av[i][j] != ' ')
			{
				free (array);
				return (0);
			}
			j++;
		}
		array[i - 1] = ft_atoi(av[i]);
	}
	if (!check_input_array(array, ac, av))
		return (0);
	free (array);
	return (1);
}

int check_input_array(int *array, int ac, char **av)
{
	int i;
	int j;

	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (array[i] == array[j])
				return (0);
			j++;
		}
		if (array[i] == 0 && av[i + 1][0] != '0')
			return (0);
		if (array[i] == -1 && av[i + 1][0] != '-')
			return (0);
		i++;
	}
	return (1);
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

t_list	*create_stack_b(t_list *save_params)
{
	t_list	*stack_b;
	//t_list	*ptr;
	int		i;

	stack_b = ft_lstnew(NULL);
	//ptr = stack_b;
	i = 1; //because alread yhave one created
	while (i < save_params->array_size)
	{
		ft_lstadd_back(&stack_b, ft_lstnew(NULL));
		i ++;
	}
	return (stack_b);
}

int	is_sorted(t_list *stack_a)
{
	t_list	*ptr;

	ptr = stack_a;
	while (ptr->next)
	{
		if (ptr->number > ptr->next->number)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
t_list		*p_swap(t_list *stack_a, t_list *stack_b, t_list *save_params)
{
	(void)	stack_b;
	if (save_params->array_size == 3)
		stack_a = sort_3(stack_a);
	// else
	// 	stack_a = sort_more(stack_a, stack_b);
	if (is_sorted(stack_a))
		printf("Should be sorted properly\n");
	else
		printf("There is a mistake\n");
	return (stack_a);
}

t_list	*sort_3(t_list *stack_a)
{
	find_positions_and_minmax(stack_a);
	if (stack_a->min == 1 && stack_a->next->max == 0)
		return (stack_a);
	else if (stack_a->min == 1 && stack_a->next->max == 1)
	{
		sa(&stack_a);
		ra(&stack_a);
	}
	else if (stack_a->max == 1 && stack_a->next->min == 0)
	{
		sa(&stack_a);
		rra(&stack_a);
	}
	else if (stack_a->max == 1 && stack_a->next->min == 1)
		ra(&stack_a);
	else if (stack_a->max == 0 && stack_a->next->min == 1)
		sa(&stack_a);
	else if (stack_a->min == 0 && stack_a->next->max == 1)
		rra(&stack_a);
	else
		printf("There is an error in sort_3\n");
	find_positions_and_minmax(stack_a);
	return (stack_a);
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
	stack->array_size = i;
	ptr = stack;
	while (ptr)
	{
		if (ptr->current_position > (i + 1) / 2)
			ptr->above_middle = 1;
		else
			ptr->above_middle = 0;
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

void	find_price_a(t_list *stack_a, t_list *stack_b)
{
	t_list	*ptr_a;

	ptr_a = stack_a;
	find_positions_and_minmax(stack_a);
	find_positions_and_minmax(stack_b);
	assign_target_a(stack_a, stack_b);
	while (ptr_a)
	{
		
		//ptr->price = //how much to the top with the target node.
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

	ptr_a = stack_a;
	while (ptr_a)
	{
		ptr_b = stack_b;
		smallest_diff = INT_MAX;
		while (ptr_b)
		{
			if (ptr_b->number < ptr_a->number)
			{
				diff = ptr_a->number - ptr_b->number;
				if (diff < smallest_diff)
				{
					smallest_diff = diff;
					ptr_a->target_node = ptr_b;
				}
			}
			ptr_b = ptr_b->next;
		}
		ptr_a = ptr_a->next;
	}
}
// t_list	*sort_more(t_list *stack_a, t_list *stack_b)
// {
// 	//tiny sort for

// }
