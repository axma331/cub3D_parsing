/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <feschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:56:40 by feschall          #+#    #+#             */
/*   Updated: 2022/03/23 13:22:05 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s || len <= 0)
		return (ft_calloc(1, sizeof(char)));
	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (ft_strlen(s) < len)
		sub = ft_calloc((ft_strlen(s)), sizeof(char));
	else
		sub = ft_calloc((len + 1), sizeof(char));
	if (sub == NULL)
		return ((void *)0);
	ft_strlcpy(sub, s + start, len + 1);
	sub[len + 1] = '\0';
	return (sub);
}
