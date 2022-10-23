#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd);
char *ft_strjoin(char *s1, char *s2);
char	*ft_get_sticky(int fd, char *sticky);
char *ft_remove_excess(char *str);
char *ft_get_new_sticky(char *str);

int ft_new_line(char *str);

size_t ft_strlen(char *str);

#endif