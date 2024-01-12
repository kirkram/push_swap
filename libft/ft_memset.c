/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano@student.hive.fi <klukiano>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:54:31 by klukiano          #+#    #+#             */
/*   Updated: 2023/11/03 16:31:05 by klukiano@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	newchar;
	unsigned char	*newstr;

	newchar = (unsigned char)c;
	newstr = (unsigned char *)str;
	while (len > 0)
	{
		*newstr = newchar;
		newstr ++;
		len --;
	}
	return (str);
}
