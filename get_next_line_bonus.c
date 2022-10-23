/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:42:19 by kboughal          #+#    #+#             */
/*   Updated: 2022/10/23 18:24:37 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_sticky(int fd, char *sticky)
{
	char	*buf;
	int		read_bytes;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_bytes = 1;
	while (!ft_new_line(sticky) && read_bytes)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		sticky = ft_strjoin(sticky, buf);
	}
	if (!sticky && !read_bytes)
		return (NULL);
	free(buf);
	return (sticky);
}

char	*ft_remove_excess(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char			*sticky[INT_MAX];
	char				*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	sticky[fd] = ft_get_sticky(fd, sticky[fd]);
	if (!sticky[fd])
		return (NULL);
	line = ft_remove_excess(sticky[fd]);
	sticky[fd] = ft_get_new_sticky(sticky[fd]);
	return (line);
}
