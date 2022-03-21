/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <feschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:29:44 by feschall          #+#    #+#             */
/*   Updated: 2021/12/20 12:33:14 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	sym;
	int		i;

	str = (char *)s;
	sym = (char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == sym)
			return (str + i);
		i++;
	}
	if (str[i] == '\0' && sym == '\0')
		return (str + i);
	return (NULL);
}
