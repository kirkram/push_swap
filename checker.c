/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:08:11 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/10 16:50:09 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>

int		checker_p_swap(t_list **stack_a, t_list **stack_b, char **av);
int		check_rot_op(t_list **stack_a, t_list **stack_b, char *buf);
int		check_push_op(t_list **stack_a, t_list **stack_b, char *buf);
int		check_swap_op(t_list **stack_a, t_list **stack_b, char *buf);

void	apply_sa(t_list **stack_a);
void	apply_sb(t_list **stack_b);
void	apply_ss(t_list **stack_a, t_list **stack_b);
void	apply_pa(t_list **stack_a, t_list **stack_b);
void	apply_pb(t_list **stack_a, t_list **stack_b);
void	apply_ra(t_list **stack_a);
void	apply_rb(t_list **stack_b);
void	apply_rr(t_list **stack_a, t_list **stack_b);
void	apply_rra(t_list **stack_a);
void	apply_rrb(t_list **stack_b);
void	apply_rrr(t_list **stack_a, t_list **stack_b);

void	print_current_stack(t_list *stack_a, t_list *stack_b);

int main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int is_error;

	stack_b = NULL;
	if (ac > 1 && check_input(ac, av))
	{
		stack_a = create_stack_a(ac, av);
		if (!stack_a)
			ft_putstr_fd("Error\n", 2);
		else
		{
			is_error = checker_p_swap(&stack_a, &stack_b, av);
			if (is_error)
				ft_putstr_fd("Error\n", 2);
			else if (is_sorted(stack_a) && !stack_b)
				ft_printf("OK\n");
			else if (!is_error)
				ft_printf("KO\n");
		}
	}
	else if (ac == 1)
		return (0);
	else
		ft_putstr_fd("Error\n", 2);
	ft_lstclear(&stack_a, NULL);
	return (0);
}

//ccf checker_stack_operations.c checker_stack_operations_2.c helper_functions.c input_check.c checker.c libft.a create_stack.c -o checker

int	checker_p_swap(t_list **stack_a, t_list **stack_b, char **av)
{
	char	*buf;
	int		is_error;

	(void)av;
	//print_current_stack(*stack_a, *stack_b);
	is_error = 0;
	buf = ft_calloc(42, 1);
	while (42)
	{
		if (is_error || buf[0] == '\n')
			break ;
		read (0, buf, 4);
		if ( buf[0] == '\0')
			break ;
		if (buf[2] != '\n' && buf[3] != '\n')
			return (1);
		else if (buf[0] == 'r')
			is_error = check_rot_op(stack_a, stack_b, buf);
		else if (buf[0] == 'p')
			is_error = check_push_op(stack_a, stack_b, buf);
		else if (buf[0] == 's')
			is_error = check_swap_op(stack_a, stack_b, buf);
		else if (buf[0] != '\n')
			is_error = 1;
	}
	free (buf);
	return (is_error);
}

void	apply_ss(t_list **stack_a, t_list **stack_b)
{
	apply_sa (stack_a);
	apply_sb (stack_b);
}

int	check_rot_op(t_list **stack_a, t_list **stack_b, char *buf)
{
	if (buf[2] != '\n' && buf[3] != '\n')
		return (1);
	else if (!ft_strncmp(buf, "rrr", 3))
	{
		//ft_printf("PRINTING RRR\n");
		apply_rrr(stack_a, stack_b);
	}
	else if (!ft_strncmp(buf, "rra", 3))
	{
		//ft_printf("PRINTING RRA\n");
		apply_rra(stack_a);
	}
	else if (!ft_strncmp(buf, "rrb", 3))
	{
		//ft_printf("PRINTING RRB\n");
		apply_rrb(stack_b);
	}
	else if (!ft_strncmp(buf, "rr", 2) && !ft_isprint(buf[2]))
	{
		//ft_printf("PRINTING RR\n");
		apply_rr(stack_a, stack_b);
	}
	else if (!ft_strncmp(buf, "ra", 2) && !ft_isprint(buf[2]))
	{
		//ft_printf("PRINTING RA\n");
		apply_ra(stack_a);
	}
	else if (!ft_strncmp(buf, "rb", 2) && !ft_isprint(buf[2]))
	{
		//ft_printf("PRINTING RB\n");
		apply_rb(stack_b);
	}
	else
	{
		return (1);
	}
	return (0);
}

int	check_push_op(t_list **stack_a, t_list **stack_b, char *buf)
{
	if (buf[2] != '\n' && buf[3] != '\n')
		return (1);
	else if (!ft_strncmp(buf, "pa", 2) && !ft_isprint(buf[2]))
	{
		//ft_printf("PRINTING PA\n");
		apply_pa(stack_a, stack_b);
	}
	else if (!ft_strncmp(buf, "pb", 2) && !ft_isprint(buf[2]))
	{
		//ft_printf("PRINTING PB\n");
		apply_pb(stack_a, stack_b);
	}
	else
		return (1);
	return (0);
}

int	check_swap_op(t_list **stack_a, t_list **stack_b, char *buf)
{
	if (buf[2] != '\n' && buf[3] != '\n')
		return (1);
	else if (!ft_strncmp(buf, "sa", 2) && !ft_isprint(buf[2]))
	{
		//ft_printf("PRINTING SA\n");
		apply_sa(stack_a);
	}
	else if (!ft_strncmp(buf, "sb", 2) && !ft_isprint(buf[2]))
	{
		//ft_printf("PRINTING SB\n");
		apply_sb(stack_b);
	}
	else if (!ft_strncmp(buf, "ss", 2) && !ft_isprint(buf[2]))
	{
		//ft_printf("PRINTING SS\n");
		apply_ss(stack_a, stack_b);
	}
	else
		return (1);
	return (0);
}
