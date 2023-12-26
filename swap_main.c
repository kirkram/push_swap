#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <string.h>

t_list		*create_stack_a(int ac, char **av, t_list **save_params);
t_list		*create_stack_b(t_list *save_params);
t_list		*p_swap(stack_a, stack_b);

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*save_params;
	t_list	*stack_b;
	//int 	i;

	//i = 0;
	save_params = ft_lstnew(NULL); //dont forget to free
	if (ac >= 2)
	{
		stack_a = create_stack_a(ac, av, &save_params);
		stack_b = create_stack_b(save_params);
		(void) stack_b;
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

t_list	*p_swap(stack_a, stack_b)
{
	while (!is_sorted(stack_a))
	{

	}
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

//write function to swap first two elements of stack a and b, do nothing if there is only one or no elements

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


