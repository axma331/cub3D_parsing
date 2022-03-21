/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:26:03 by feschall          #+#    #+#             */
/*   Updated: 2021/07/21 10:07:49 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	check_end(char **line, char *end, char *buff)
{
	char	*temp;
	char	*unend;

	unend = ft_strchr(end, '\n');
	if (unend)
	{
		*unend = '\0';
		temp = ft_strdup(*line);
		free(*line);
		*line = ft_strjoin(temp, end);
		free(temp);
		ft_strcpy(end, ++unend);
		free(buff);
		return (1);
	}
	else
	{
		temp = ft_strdup(*line);
		free(*line);
		*line = ft_strjoin(temp, end);
		free(temp);
	}
	return (0);
}

char	check_n(char **line, char *buff, char *end)
{
	char	*temp;
	char	*un;

	un = ft_strchr(buff, '\n');
	if (un)
	{
		*un = '\0';
		ft_strcpy(end, ++un);
		temp = ft_strdup(*line);
		free(*line);
		*line = ft_strjoin(temp, buff);
		free(temp);
		free(buff);
		return (1);
	}
	else
	{
		temp = ft_strdup(*line);
		free(*line);
		*line = ft_strjoin(temp, buff);
		free(temp);
	}
	return (0);
}

int	check_byte_was_read(char **line, char *buff, int fd, char *end)
{
	int	byte_was_read;

	byte_was_read = 1;
	while (byte_was_read)
	{
		byte_was_read = read(fd, buff, BUFFER_SIZE);
		buff[byte_was_read] = '\0';
		if (check_n(line, buff, end) == 1)
			return (-1);
	}
	return (byte_was_read);
}

int	get_next_line(int fd, char **line)
{
	static char	end[BUFFER_SIZE + 1];
	char		*buff;
	int			byte_was_read;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
	{
		free(buff);
		return (-1);
	}
	*line = ft_strdup("");
	if (check_end(line, end, buff) == 1)
		return (1);
	byte_was_read = check_byte_was_read(line, buff, fd, end);
	if (byte_was_read == -1)
		return (1);
	if (byte_was_read == 0 && *end)
		ft_bzero(end, ft_strlen(end));
	free(buff);
	return (0);
}
