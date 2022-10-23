#include "get_next_line.h"

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
		if(read_bytes < 0)
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
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*sticky;
	char				*line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	sticky = ft_get_sticky(fd, sticky);
	if (!sticky)
		return (NULL);
	line = ft_remove_excess(sticky);
	sticky = ft_get_new_sticky(sticky);
	return (line);
}

/*
int main()
{
	char	*line;
	int		fd;

	fd = open("test/text1.txt", O_RDONLY);
	if(fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (!line)
		{
			free(line);
			break;
		}
		free(line);
	}
	
	close(fd);
	return (0);
}*/
