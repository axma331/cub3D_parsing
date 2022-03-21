/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <feschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 19:59:38 by feschall          #+#    #+#             */
/*   Updated: 2022/03/21 12:46:40 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit(const char *msg, int errnum)
{
	if (errnum)
	{
		write (2, "\033[31mError: ", ft_strlen("\033[31mError: "));
		write (2, msg, ft_strlen(msg));
		write (2, "\033[0m\n", 5);
	}
	else
	{
		write (2, "\033[32m", ft_strlen("\033[32m"));
		write (1, msg, ft_strlen(msg));
		write (1, "\033[0m\n", 5);
	}
	exit(errnum);
}
