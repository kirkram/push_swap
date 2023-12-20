/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano@student.hive.fi <klukiano>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:42:12 by klukiano@st       #+#    #+#             */
/*   Updated: 2023/11/07 12:23:05 by klukiano@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_strcpy(char *dest, char *src, char*src2);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;

	if (s1 && s2)
	{
		newstr = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
		if (newstr == NULL)
			return (NULL);
		ft_strcpy(newstr, (char *)s1, (char *)s2);
		return (newstr);
	}
	return (NULL);
}

static void	ft_strcpy(char *dest, char *src, char*src2)
{
	while (*src != '\0')
	{
		*dest = *src;
		dest ++;
		src ++;
	}
	while (*src2 != '\0')
	{
		*dest = *src2;
		dest ++;
		src2 ++;
	}
	*dest = '\0';
}
