/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurgia- <mmurgia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:16:26 by mmurgia-          #+#    #+#             */
/*   Updated: 2022/06/16 13:30:43 by mmurgia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	int		rd;
	char	*tmp;

	tmp =  malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (0);
	rd = 1;
	while (rd != 0 && (!ft_strchr(str)))
	{
		rd = read(fd, tmp, BUFFER_SIZE);
		//printf("RD: %lu\n", rd);
		//printf("TMP: %s\n", tmp);
		if (rd == -1)
		{
			free(tmp);
			return (0);
		}
	tmp[rd] = '\0';
	str = ft_strjoin(str, tmp);
	}
	//printf("RD: %lu\n", rd);
	//printf("TMP: %s\n", tmp);
	printf("STR: %s\n", str);
	free(tmp);
	return (str);
}

/* char	*ft_get_line(char *strrd, int fd)
{
	char	*s2;

	s2 = ft_read(fd, strrd, BUFFER_SIZE);
	printf("LINE: %s", strrd);
	return (s2);
} */

char	*get_next_line(int fd)
{
	static char	*str;
	//char		*tmp;
	int			i;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		return (0);
	}
	i = 0;
	str = ft_read(fd, str);
	printf("STR GNL: %s\n", str);
	return (0);
}

int	main(void)
{
	int		fd;
	char	*file;

	fd = open("file.txt", O_RDONLY);
	file = get_next_line(fd);
	free(file);
	close(fd);
	return (0);
}
