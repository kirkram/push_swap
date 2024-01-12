/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano@student.hive.fi <klukiano>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:08:54 by klukiano@st       #+#    #+#             */
/*   Updated: 2023/11/03 15:23:19 by klukiano@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*copy;
	int		i;

	if (s && f)
	{
		i = 0;
		copy = malloc((ft_strlen((char *)s) + 1) * sizeof(*s));
		if (copy == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			copy[i] = f(i, s[i]);
			i ++;
		}
		copy[i] = '\0';
		return (copy);
	}
	return (NULL);
}
