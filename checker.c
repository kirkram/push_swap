/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:08:11 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/10 19:34:41 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>

int		checker_p_swap(t_list **stack_a, t_list **stack_b);
int		check_rot_op(char *buf);
int		check_push_op(char *buf);
int		check_swap_op(char *buf);

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

void	apply_commands(t_list **stack_a, t_list **stack_astack_b, char *buf);

void	print_current_stack(t_list *stack_a, t_list *stack_b);

int main(int ac, char **av)
{
	t_list		*stack_a;
	t_list		*stack_b;
	int			is_error;
	// static char	*buf = ft_calloc(600000, 1);

	stack_b = NULL;
	if (ac > 1 && check_input(ac, av))
	{
		stack_a = create_stack_a(ac, av);
		if (!stack_a)
			ft_putstr_fd("Error\n", 2);
		else
		{
			is_error = checker_p_swap(&stack_a, &stack_b);
			if (is_error)
				ft_putstr_fd("Error\n", 2);
			else if (is_sorted(stack_a) && !stack_b)
				ft_printf("OK\n");
			else if (!is_error)
			{
				//print_current_stack(stack_a, stack_b);
				ft_printf("KO\n");
			}

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

int	checker_p_swap(t_list **stack_a, t_list **stack_b)
{
	char	*buf = ft_calloc(600000, 1);
	char	*ptr_buf;
	int		is_error;


	is_error = 0;
	//ft_strlcpy(buf, "pb\npb\npb\nrb\nrb\npb\npb\npb\nrb\npb\nrb\nrb\nrb\nrb\npb\nrb\nrr\npb\nra\nrrb\npb\nrb\nrrb\npb\nrrr\nrra\npb\nrra\npb\nrra\nrb\npb\nrrr\nrra\nrra\npb\nrrr\npb\nrrr\nrra\nrra\npb\nrb\nrb\nrb\npb\nrrr\nrrr\nrrr\npb\npb\nrrr\nrrr\nrrr\npb\nrrb\npb\nrb\npb\nrb\npb\nrb\nrb\nrb\npb\nrb\npb\nrb\nrb\npb\nrb\nrb\npb\nrrr\nrrr\nrrr\nrrb\nrrb\nrrb\nrrb\nrrb\nrrb\nrrb\nrrb\nrrb\npb\nrb\nrr\nrr\nrb\npb\nrb\nrb\nrb\nrb\npb\npb\nrr\nrr\nra\nra\npb\nrr\nrb\nrb\npb\nrr\nrb\nrb\nrb\nrb\nrb\nrb\npb\nrrr\nrra\nrra\nrra\nrra\nrra\nrra\nrra\npb\nrrr\nrrr\nrrr\npb\nrrr\nrrr\nrrr\nrrr\nrrb\nrrb\nrrb\nrrb\nrrb\nrrb\nrrb\nrrb\nrrb\nrrb\nrrb\npb\nrb\nrr\nrr\nrb\nrb\npb\nrb\nrb\nrb\npb\nrrr\nrrr\nrrr\nrra\nrra\nrra\npb\nrrr\nrra\nrra\npb\nrrr\nrrr\nrrr\nrrr\nrrr\nrra\npb\nrrr\nrrr\npb\nra\nra\nra\nra\nra\npb\nrrr\nrrr\npb\nrrb\npb\nrr\nrr\npb\nrrr\nrrb\nrrb\npb\nrrr\nrrb\npb\nrr\nra\nra\nra\npb\nrr\nrr\nrb\nrb\nrb\npb\nrr\nra\npb\nrr\nrr\nrb\nrb\npb\nrb\npb\nrra\nrra\nrra\nrra\nrra\npb\nrr\nrr\nrb\nrb\nrb\nrb\npb\nrra\nrra\nrra\nrb\npb\nrr\nrr\nrr\nrr\nrr\nrb\nrb\nrb\nrb\npb\nrr\nrr\nrr\nrb\npb\nrr\nrr\nrr\nrr\nrr\npb\nrr\nrr\nrr\nrr\npb\nrra\nrra\nrra\nrra\nrra\npb\nrra\nrb\nrb\nrb\nrb\npb\nrra\npb\nrra\nrra\nrb\npb\nrrr\nrrr\nrrr\nrrr\nrrr\npb\nra\npb\nrrr\nrrb\nrrb\nrrb\nrrb\nrrb\nrrb\npb\nrrr\npb\nrrr\nrrr\nrrb\nrrb\npb\nrr\nra\nra\nra\nra\nra\npb\nrr\nrr\nrr\nrr\npb\nrb\nrb\npb\nra\nra\nrrb\nrrb\nrrb\npb\nrrr\nrrr\nrrr\nrrr\nrrr\nrrb\nrrb\nrrb\npb\nrra\nrra\npb\nra\nra\nra\nrrb\nrrb\nrrb\nrrb\npb\nrrr\nrrr\nrrr\nrrb\nrrb\nrrb\nrrb\nrrb\nrrb\nrrb\nrrb\npb\nra\npb\nrrr\nrrr\nrrr\nrrr\nrrr\nrrr\nrrb\nrrb\nrrb\nrrb\nrrb\npb\nrrr\nrrr\nrrr\nrrr\nrrr\nrrr\nrra\nrra\npb\nrrr\nrrb\npb\nrrr\nrrr\npb\nrr\npb\nra\npb\nra\nra\nra\nra\npb\nrrr\npb\nra\nra\npb\nra\nra\npb\nrb\nrb\nrb\nrb\nrb\nrb\npb\nrra\npb\nrra\npb\nrra\nrra\nrb\npb\nrb\nrb\nrb\nrb\npb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\npb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\npb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nsa\nrra\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\nrra\npa\npa\npa\npa\npa\npa\nrra\npa\npa\nrra\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa\npa", -1);
	//ft_strlcpy(buf, "pb\npb\nsb\npa\npa", -1);
	ptr_buf = buf;
	while (42)
	{
		read (0, ptr_buf, 4);
		if (is_error || ptr_buf[0] == '\0')
			break ;
		if (ptr_buf[2] != '\n' && ptr_buf[3] != '\n')
		{
			if (ptr_buf[2] != '\0' && ptr_buf[3] != '\0')
				is_error = 1;
		}
		else if (ptr_buf[0] == 'r')
			is_error = check_rot_op(ptr_buf);
		else if (ptr_buf[0] == 'p')
			is_error = check_push_op(ptr_buf);
		else if (ptr_buf[0] == 's')
			is_error = check_swap_op(ptr_buf);
		else if (ptr_buf[0] != '\0')
			is_error = 1;
		if (ptr_buf[2] == '\n' || ptr_buf[2] == '\0')
			ptr_buf = ptr_buf + 3;
		else if (ptr_buf[3] == '\n' || ptr_buf[3] == '\0')
			ptr_buf = ptr_buf + 4;
		else
			is_error = 1;
		if (is_error)
			break ;
	}
	ptr_buf[0] = '\0';


	if (!is_error)
		apply_commands(stack_a, stack_b, buf);
	free (buf);
	return (is_error);
}

void	apply_ss(t_list **stack_a, t_list **stack_b)
{
	apply_sa (stack_a);
	apply_sb (stack_b);
}

int	check_rot_op(char *buf)
{
	if (!ft_strncmp(buf, "rrr", 3))
		return (0);
	else if (!ft_strncmp(buf, "rra", 3))
		return (0);
	else if (!ft_strncmp(buf, "rrb", 3))
		return (0);
	else if (!ft_strncmp(buf, "rr", 2) && !ft_isprint(buf[2]))
		return (0);
	else if (!ft_strncmp(buf, "ra", 2) && !ft_isprint(buf[2]))
		return (0);
	else if (!ft_strncmp(buf, "rb", 2) && !ft_isprint(buf[2]))
		return (0);
	else
		return (1);
}

int	check_push_op(char *buf)
{
	if (!ft_strncmp(buf, "pa", 2) && !ft_isprint(buf[2]))
		return (0);
	else if (!ft_strncmp(buf, "pb", 2) && !ft_isprint(buf[2]))
		return (0);
	else
		return (1);
}

int	check_swap_op(char *buf)
{
	if (!ft_strncmp(buf, "sa", 2) && !ft_isprint(buf[2]))
		return (0);
	else if (!ft_strncmp(buf, "sb", 2) && !ft_isprint(buf[2]))
		return (0);
	else if (!ft_strncmp(buf, "ss", 2) && !ft_isprint(buf[2]))
		return (0);
	else
		return (1);
}

void	apply_commands(t_list **stack_a, t_list **stack_b, char *buf)
{
	int i;

	//ft_printf("THE buf before is %s\n", buf);
	//buf = "rra\npb\nsa\nrra\npa";
	while (*buf)
	{
		i = 0;
		while (buf[i] && buf[i] != '\n' )
			i ++;
		if (i == 3)
		{
			if (!ft_strncmp(buf, "rrr", 3))
				apply_rrr(stack_a, stack_b);
			else if (!ft_strncmp(buf, "rra", 3))
				apply_rra(stack_a);
			else if (!ft_strncmp(buf, "rrb", 3))
				apply_rrb(stack_b);
			buf += 4;
		}
		else if (i == 2)
		{
			if (!ft_strncmp(buf, "sa", 2))
				apply_sa(stack_a);
			else if (!ft_strncmp(buf, "sb", 2))
				apply_sb(stack_a);
			else if (!ft_strncmp(buf, "ss", 2))
				apply_ss(stack_a, stack_b);
			else if (!ft_strncmp(buf, "pa", 2))
				apply_pa(stack_a, stack_b);
			else if (!ft_strncmp(buf, "pb", 2))
				apply_pb(stack_a, stack_b);
			else if (!ft_strncmp(buf, "rr", 2))
				apply_rr(stack_a, stack_b);
			else if (!ft_strncmp(buf, "ra", 2))
				apply_ra(stack_a);
			else if (!ft_strncmp(buf, "rb", 2))
				apply_rb(stack_b);
			buf += 3;
		}
		else if (!buf[i])
		{
			//ft_printf("End of file\n");
			break;
		}
		// else
		// {
		// 	// ft_printf("The I is now %d", i);
		// 	// ft_printf("ERROR IN APPLY\n");
		// 	break;
		// }

	}
	return ;
}
