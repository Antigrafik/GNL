/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurgia- <mmurgia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:19:18 by mmurgia-          #+#    #+#             */
/*   Updated: 2022/07/20 11:01:01 by mmurgia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

/* # define BUFFER_SIZE 5 */

/* get_next_line.c */
char	*get_next_line(int fd);
char	*ft_read(int fd, char *str);

# define FILES_MAX 4096

/* get_next_line_utils.c */
size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);

#endif