/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano@student.hive.fi <klukiano>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:29:42 by klukiano@st       #+#    #+#             */
/*   Updated: 2023/11/06 21:52:16 by klukiano@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int			check_char(char c1, char const *set);

char	*ft_strtrim(const char *s1, char const *set)
{
	int		i;
	char	*newstr;
	int		start;

	if (s1 && set)
	{
		i = 0;
		while (check_char(s1[i], set))
			i ++;
		start = i;
		if (s1[i] != '\0')
		{
			while (s1[i] != '\0')
				i ++;
			i --;
			while (check_char(s1[i], set))
				i --;
		}
		newstr = (ft_substr(s1, start, i + 1 - start));
		return (newstr);
	}
	return (NULL);
}

static int	check_char(char c1, char const *set)
{
	while (*set)
	{
		if (c1 == *set)
			return (1);
		set ++;
	}
	return (0);
}
