#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <string.h>

t_list		*create_stack_a(int ac, char **av, t_list **save_params);
t_list		*create_stack_b(t_list *save_params);

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*save_params;
	t_list	*stack_b;
	int 	i;

	i = 0;
	save_params = ft_lstnew(NULL); //dont forget to free
	if (ac >= 2)
	{
		stack_a = create_stack_a(ac, av, &save_params);
		stack_b = create_stack_b(save_params);
		//stack_a = p_swap(stack_a, stack_b, save_params);
		while (stack_a->next)
		{
			printf("%d\n", stack_a->number); //ft_printf
			stack_a = stack_a->next;
		}
	}
	else
		return (0);
	return (0);
}

t_list	*create_stack_a(int ac, char **av, t_list **save_params)
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
	t_list	*ptr;
	int		i;

	stack_b = ft_lstnew(NULL);
	ptr = stack_b;
	i = 1; //because alread yhave one created
	while (i < save_params->array_size)
	{
		ft_lstadd_back(&stack_b, ft_lstnew(NULL));
		i ++;
	}
	return (stack_b);
}

// int	*p_swap(stack_a, stack_b)
// {

// }
