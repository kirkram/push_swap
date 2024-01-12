/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:37:34 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/12 13:50:13 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		a_two_args(&stack_a_head, str_array);
		free_n_0(NULL, str_array);
	}
	else
		a_several_args(ac, av, &stack_a_head);
	return (stack_a_head);
}

void	a_several_args(int ac, char **av, t_list **stack_a_head)
{
	t_list	*list_ptr;
	int		i;

	i = 0;
	list_ptr = *stack_a_head;
	while (++i < ac)
	{
		list_ptr->number = ft_atoi(av[i]);
		if (i < ac - 1)
		{
			list_ptr->next = ft_lstnew(NULL);
			list_ptr = list_ptr->next;
		}
	}
	(*stack_a_head)->array_size = i - 1;
}

void	a_two_args(t_list **stack_a_head, char **str_array)
{
	t_list	*list_ptr;
	int		i;

	i = 0;
	list_ptr = *stack_a_head;
	while (i < (*stack_a_head)->array_size)
	{
		list_ptr->number = ft_atoi(str_array[i]);
		if (i < (*stack_a_head)->array_size - 1)
		{
			list_ptr->next = ft_lstnew(NULL);
			list_ptr = list_ptr->next;
		}
		i ++;
	}
}
