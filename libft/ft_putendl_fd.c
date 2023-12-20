/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano@student.hive.fi <klukiano>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:14:43 by klukiano@st       #+#    #+#             */
/*   Updated: 2023/11/03 15:22:17 by klukiano@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (*s != '\0')
		{
			write (fd, &*s, 1);
			s ++;
		}
	}
	write (fd, "\n", 1);
}
