/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano@student.hive.fi <klukiano>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:31:22 by klukiano@st       #+#    #+#             */
/*   Updated: 2023/11/08 15:35:59 by klukiano@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	buf_size;

	buf_size = SIZE_MAX;
	if (count != 0)
	{
		if (buf_size / count < size)
			return (NULL);
	}
	buf_size = count * size;
	ptr = malloc(buf_size);
	if (!ptr)
		return (NULL);
	ft_bzero (ptr, buf_size);
	return (ptr);
}
