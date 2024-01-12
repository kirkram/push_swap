/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano@student.hive.fi <klukiano>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:28:26 by klukiano@st       #+#    #+#             */
/*   Updated: 2023/11/03 15:23:16 by klukiano@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2 && n > 0 && *s1 && *s2)
	{
		s1 ++;
		s2 ++;
		n --;
	}
	if (n == 0)
		return (0);
	return ((int)((unsigned char)*s1 - (unsigned char)*s2));
}
