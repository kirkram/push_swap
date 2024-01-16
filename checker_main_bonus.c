/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:08:11 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/12 11:39:50 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker_bonus.h"

int	main(int ac, char **av)
{
	t_list		*stack_a;
	t_list		*stack_b;
	char		*buf;

	buf = ft_calloc(600000, 1);
	stack_b = NULL;
	if (ac > 1 && check_input(ac, av))
	{
		stack_a = create_stack_a(ac, av);
		if (!stack_a)
			ft_putstr_fd("Error\n", 2);
		else
			checker_hub(&stack_a, &stack_b, &buf);
	}
	else if (ac == 1)
		return (0);
	else
		ft_putstr_fd("Error\n", 2);
	free (buf);
	ft_lstclear(&stack_a, NULL);
	return (0);
}

void	checker_hub(t_list **stack_a, t_list **stack_b, char **buf)
{
	int	is_error;

	is_error = checker_read_stdin(buf);
	if (is_error)
		ft_putstr_fd("Error\n", 2);
	else
		apply_commands(stack_a, stack_b, buf);
	if (!is_error && is_sorted(*stack_a) && !*stack_b)
		ft_printf("OK\n");
	else if (!is_error)
		ft_printf("KO\n");
}
