/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:33:32 by kboughal          #+#    #+#             */
/*   Updated: 2022/10/23 18:33:54 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_sticky(int fd, char *sticky);
char	*ft_remove_excess(char *str);
char	*ft_get_new_sticky(char *str);

int		ft_new_line(char *str);
int		ft_get_pos(char *str);

size_t	ft_strlen(char *str);

#endif