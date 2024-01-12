/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano@student.hive.fi <klukiano>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:14:14 by klukiano@st       #+#    #+#             */
/*   Updated: 2023/11/03 15:23:45 by klukiano@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strchr(char *str, int c)
{
	c = (char)c;
	while (*str != c && *str != '\0')
		str ++;
	if (*str == '\0' && c != '\0')
		return (NULL);
	else
		return (str);
}
