/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_stdin_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:13:28 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/12 11:38:26 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker_bonus.h"

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
		bytes_read = read(0, cache, 5);
		if (bytes_read < 5 && bytes_read > 1)
			is_err = stdin_to_buf(buf, cache, bytes_read);
		else if (bytes_read == 0)
			break ;
		else
			is_err = 1;
		ft_bzero(cache, 5);
	}
	free (cache);
	return (is_err);
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
