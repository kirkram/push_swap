/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano@student.hive.fi <klukiano>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:15:09 by klukiano@st       #+#    #+#             */
/*   Updated: 2023/11/03 17:59:01 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void		ft_putnbr_fd(int n, int fd);
static void	putchar_fd(char c, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		putchar_fd('-', fd);
		putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		n = -n;
		putchar_fd('-', fd);
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	putchar_fd(n % 10 + '0', fd);
}

static void	putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
