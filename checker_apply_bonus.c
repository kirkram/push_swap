/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_apply_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:42:20 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/12 11:39:54 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

void	apply_commands(t_list **stack_a, t_list **stack_b, char **buf)
{
	int		i;
	char	**split_buf;
	size_t	len;

	split_buf = ft_split(*buf, '\n');
	i = 0;
	while (split_buf[i])
	{
		len = ft_strlen(split_buf[i]);
		if (len == 2)
			apply_commands_2b(stack_a, stack_b, split_buf[i]);
		else if (len == 3)
			apply_commands_3b(stack_a, stack_b, split_buf[i]);
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
}

void	apply_commands_3b(t_list **stack_a, t_list **stack_b, char *command)
{
	if (!ft_strncmp(command, "rra", 3))
		apply_rra(stack_a);
	else if (!ft_strncmp(command, "rrb", 3))
		apply_rrb(stack_b);
	else if (!ft_strncmp(command, "rrr", 3))
		apply_rrr(stack_a, stack_b);
}

void	apply_ss(t_list **stack_a, t_list **stack_b)
{
	apply_sa (stack_a);
	apply_sb (stack_b);
}
