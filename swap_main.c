#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <string.h>

t_list		*create_stack_a(int ac, char **av, t_list **save_params);
t_list		*create_stack_b(t_list *save_params);
//t_list		*p_swap(stack_a, stack_b);
int			check_input(int ac, char **av);
int			check_input_array(int *array, int ac, char **av);

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*save_params;
	t_list	*stack_b;
	//int 	i;

	//i = 0;
	save_params = ft_lstnew(NULL); //dont forget to free
	if (check_input(ac, av) && ac > 1)
	{
		stack_a = create_stack_a(ac, av, &save_params);
		stack_b = create_stack_b(save_params);
		(void) stack_b;

		//In case of error, it must display "Error" followed by a ’\n’ on the standard error.
		//Errors include for example: some arguments aren’t integers, some arguments are
		//bigger than an integer and/or there are duplicates.

		//stack_a = p_swap(stack_a, stack_b, save_params);
		while (stack_a->next)
		{
			printf("%d\n", stack_a->number); //ft_printf
			stack_a = stack_a->next;
		}
	}
	else
		printf("Error\n");
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
	printf("passed the char check\n");	
	if (!check_input_array(array, ac, av))
		return (0);
	free (array);
	return (1);
}
//this function will check for duplicates and numbers that cant fit into int
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
			//sign = 0;
			ft_lstadd_back(&list_ptr, ft_lstnew(NULL));
			// if (str_array[i][0] = '-')
			// 	sign = -1;
			list_ptr->number = ft_atoi(str_array[i]);
			// if (sign == -1 && list_ptr->number == 0 || sign == 0 && list_ptr->number == -1)
			// {
			// 	((*save_params)->array_size = -1);
			// 	ft_lstclear(stack_a_head);
			// 	break;
			// }
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

// t_list	*p_swap(stack_a, stack_b)
// {
// 	while (!is_sorted(stack_a))
// 	{

// 	}
// }

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

