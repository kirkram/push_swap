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

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*save_params;
	t_list	*stack_b;

	save_params = ft_lstnew(NULL); //dont forget to free
	if (check_input(ac, av) && ac > 1)
	{
		stack_a = create_stack_a(ac, av, &save_params);
		stack_b = create_stack_b(save_params);
		stack_a = p_swap(stack_a, stack_b, save_params);
		while (stack_a->next)
		{
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
				if (!ft_isdigit(av[i][j + 1]) || j != 0)
				{
					free (array);
					return (0);
				}
			}
			else if (!ft_isdigit(av[i][j]))
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
			ft_lstadd_back(&list_ptr, ft_lstnew(NULL));
			list_ptr->number = ft_atoi(str_array[i]);
			list_ptr = list_ptr->next;
			i ++;
		}
	}
	else
	{
		while (++i < ac)
		{
			ft_lstadd_back(&list_ptr, ft_lstnew(NULL));
			list_ptr->number = ft_atoi(av[i]);
			list_ptr = list_ptr->next;
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

int is_sorted(t_list *stack_a)
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
	while (!is_sorted(stack_a))
	{
		
	}
	if (save_params->array_size == 3)
		stack_a = sort_3(stack_a);


	return (stack_a);
}

t_list	*sort_3(t_list *stack_a)
{
	stack_a = find_positions(stack_a);
	//find smallest or biggest
	//if (stack_a->number > stack_a->next);

}

t_list	*find_positions(t_list *stack)
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
		if (ptr->current_position > (i + 1) / 2)
			ptr->above_middle = 1;
		else
			ptr->above_middle = 0;
		ptr = ptr->next;
	}
	stack = find_min_max(stack);
	return (stack);
}

t_list	*find_min_max(t_list *stack)
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
	return (stack);
}	
