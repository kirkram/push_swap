/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:08:11 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/11 15:31:42 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>

int		checker_read_stdin(char **buf);
int		check_rot_op(char *buf);
int		check_push_op(char *buf);
int		check_swap_op(char *buf);
int		check_2_bytes(char *cache);
int		check_3_bytes(char *cache);
int		check_4_bytes(char *cache);
int		stdin_to_buf(char **buf, char *cache, int bytes_read);

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

void	apply_commands(t_list **stack_a, t_list **stack_b, char **buf);
void	apply_commands_2b(t_list **stack_a, t_list **stack_b, char *command);
void	apply_commands_3b(t_list **stack_a, t_list **stack_b, char *command);

void	print_current_stack(t_list *stack_a, t_list *stack_b);

int main(int ac, char **av)
{
	t_list		*stack_a;
	t_list		*stack_b;
	int			is_error;
	char		*buf;

	buf = ft_calloc(600000, 1);
	stack_b = NULL;
	if (ac > 1 && check_input(ac, av))
	{
		stack_a = create_stack_a(ac, av);
		if (!stack_a)
			ft_putstr_fd("Error\n", 2);
		else
		{
			is_error = checker_read_stdin(&buf);
			if (is_error)
				ft_putstr_fd("Error\n", 2);
			else
				apply_commands(&stack_a, &stack_b, &buf);
			if (!is_error && is_sorted(stack_a) && !stack_b)
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


int	checker_read_stdin(char **buf)
{
	char	*cache;
	int		is_err;
	int		bytes_read;

	cache = ft_calloc(5, 1);
	is_err = 0;
	while (42)
	{
		if (is_err)
			break ;
		bytes_read = read(0, cache, 50);
		if (bytes_read < 5 && bytes_read > 1)
			is_err = stdin_to_buf(buf, cache, bytes_read);
		else if (bytes_read == 0)
			break ;
		else
		{
			ft_printf("The bytes read is %d\n", bytes_read);
			is_err = 1;
		}
		ft_bzero(cache, 5);
	}
	free (cache);
	return (is_err);
}

void	apply_commands(t_list **stack_a, t_list **stack_b, char **buf)
{
	int		i;
	char	**split_buf;
	size_t	len;

	split_buf = ft_split(*buf, '\n');
	free (*buf);
	i = 0;
	while (split_buf[i])
	{
		len = ft_strlen(split_buf[i]);
		if (len == 2)
			apply_commands_2b(stack_a, stack_b, split_buf[i]);
		else if (len == 3)
			apply_commands_3b(stack_a, stack_b, split_buf[i]);
		else
			ft_printf ("Mistake in apply commands len\n");
		i ++;
	}
	free_n_0(NULL, split_buf);
}
void	apply_commands_2b(t_list **stack_a, t_list **stack_b, char *command)
{
	if (!ft_strncmp(command, "sa", 2))
		apply_sa(stack_a);
	else if (!ft_strncmp(command, "sb", 2))
		apply_sb(stack_b);
	else if (!ft_strncmp(command, "ss", 2))
		apply_ss(stack_a, stack_b);
	else if (!ft_strncmp(command, "pa", 2))
		apply_pa(stack_a, stack_b);
	else if (!ft_strncmp(command, "pb", 2))
		apply_pb(stack_a, stack_b);
	else if (!ft_strncmp(command, "ra", 2))
		apply_ra(stack_a);
	else if (!ft_strncmp(command, "rb", 2))
		apply_rb(stack_b);
	else if (!ft_strncmp(command, "rr", 2))
		apply_rr(stack_a, stack_b);
	else
	{
		ft_printf("ERROR IN COMMANDS 2b, EXIT\n");
		exit (1);
	}
}

void	apply_commands_3b(t_list **stack_a, t_list **stack_b, char *command)
{
	if (!ft_strncmp(command, "rra", 3))
		apply_rra(stack_a);
	else if (!ft_strncmp(command, "rrb", 3))
		apply_rrb(stack_b);
	else if (!ft_strncmp(command, "rrr", 3))
		apply_rrr(stack_a, stack_b);
	else
	{
		ft_printf("ERROR IN COMMANDS 2b, EXIT\n");
		exit (1);
	}
}

int	stdin_to_buf(char **buf, char *cache, int bytes_read)
{
	int	is_error;

	is_error = 0;
	if (bytes_read == 4)
		is_error = check_4_bytes(cache);
	else if (bytes_read == 3)
		is_error = check_3_bytes(cache);
	else if (bytes_read == 2)
		is_error = check_2_bytes(cache);
	if (!is_error)
		ft_strlcat(*buf, cache, -1);
	return (is_error);
}

int	check_2_bytes(char *cache)
{
	if (!ft_strncmp(cache, "sa", 2))
		return (0);
	else if (!ft_strncmp(cache, "sb", 2))
		return (0);
	else if (!ft_strncmp(cache, "ss", 2))
		return (0);
	else if (!ft_strncmp(cache, "pa", 2))
		return (0);
	else if (!ft_strncmp(cache, "pb", 2))
		return (0);
	else if (!ft_strncmp(cache, "ra", 2))
		return (0);
	else if (!ft_strncmp(cache, "rb", 2))
		return (0);
	else if (!ft_strncmp(cache, "rr", 2))
		return (0);
	return (1);
}

int	check_3_bytes(char *cache)
{
	if (!ft_strncmp(cache, "rra", 3))
		return (0);
	else if (!ft_strncmp(cache, "rrb", 3))
		return (0);
	else if (!ft_strncmp(cache, "rrr", 3))
		return (0);
	else if (!ft_strncmp(cache, "sa\n", 3))
		return (0);
	else if (!ft_strncmp(cache, "sb\n", 3))
		return (0);
	else if (!ft_strncmp(cache, "ss\n", 3))
		return (0);
	else if (!ft_strncmp(cache, "pa\n", 3))
		return (0);
	else if (!ft_strncmp(cache, "pb\n", 3))
		return (0);
	else if (!ft_strncmp(cache, "ra\n", 3))
		return (0);
	else if (!ft_strncmp(cache, "rb\n", 3))
		return (0);
	else if (!ft_strncmp(cache, "rr\n", 3))
		return (0);
	return (1);
}

int	check_4_bytes(char *cache)
{
	if (!ft_strncmp(cache, "rra\n", 4))
		return (0);
	else if (!ft_strncmp(cache, "rrb\n", 4))
		return (0);
	else if (!ft_strncmp(cache, "rrr\n", 4))
		return (0);
	return (1);
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

// void	apply_commands(t_list **stack_a, t_list **stack_b, char *buf)
// {
// 	int i;

// 	while (*buf)
// 	{
// 		i = 0;
// 		while (buf[i] && buf[i] != '\n' )
// 			i ++;
// 		if (i == 3)
// 		{
// 			if (!ft_strncmp(buf, "rrr", 3))
// 				apply_rrr(stack_a, stack_b);
// 			else if (!ft_strncmp(buf, "rra", 3))
// 				apply_rra(stack_a);
// 			else if (!ft_strncmp(buf, "rrb", 3))
// 				apply_rrb(stack_b);
// 			buf += 4;
// 		}
// 		else if (i == 2)
// 		{
// 			if (!ft_strncmp(buf, "sa", 2))
// 				apply_sa(stack_a);
// 			else if (!ft_strncmp(buf, "sb", 2))
// 				apply_sb(stack_a);
// 			else if (!ft_strncmp(buf, "ss", 2))
// 				apply_ss(stack_a, stack_b);
// 			else if (!ft_strncmp(buf, "pa", 2))
// 				apply_pa(stack_a, stack_b);
// 			else if (!ft_strncmp(buf, "pb", 2))
// 				apply_pb(stack_a, stack_b);
// 			else if (!ft_strncmp(buf, "rr", 2))
// 				apply_rr(stack_a, stack_b);
// 			else if (!ft_strncmp(buf, "ra", 2))
// 				apply_ra(stack_a);
// 			else if (!ft_strncmp(buf, "rb", 2))
// 				apply_rb(stack_b);
// 			buf += 3;
// 		}
// 		else if (!buf[i])
// 		{
// 			break;
// 		}
// 	}
// 	return ;
// }
