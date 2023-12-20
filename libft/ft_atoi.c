/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano@student.hive.fi <klukiano>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:30:59 by klukiano@st       #+#    #+#             */
/*   Updated: 2023/11/13 16:16:07 by klukiano@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str ++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str ++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - 48;
		if (num < 0)
		{
			if (sign > 0)
				return (-1);
			return (0);
		}
		str ++;
	}
	return (num * sign);
}
