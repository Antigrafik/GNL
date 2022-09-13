/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurgia- <mmurgia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:16:26 by mmurgia-          #+#    #+#             */
/*   Updated: 2022/09/12 13:19:11 by mmurgia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *str)
{
	int		rd;
	char	*tmp;

	tmp = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (0);
	rd = 1;
	while (rd != 0 && (!ft_strchr(str, '\n')))
	{
		rd = read(fd, tmp, BUFFER_SIZE);
		if (rd == -1)
		{
			free(tmp);
			return (0);
		}
	tmp[rd] = '\0';
	str = ft_strjoin(str, tmp);
	}
	free(tmp);
	return (str);
}

char	*ft_get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
		i++;
	line = malloc (sizeof(char) * (i + 1));
	if (!line)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_save_line(char *str)
{
	char	*tmp;
	int		i;
	int		count;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (0);
	}
	tmp = malloc(sizeof (char) * (ft_strlen(str) - i + 1));
	if (!tmp)
		return (0);
	count = 0;
	while (str[i])
		tmp[count++] = str[++i];
	tmp[count] = '\0';
	free(str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char		*str[FILES_MAX];
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > FILES_MAX)
		return (0);
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_get_line(str[fd]);
	str[fd] = ft_save_line(str[fd]);
	return (line);
}

/* int	main(void)
{
	int		fd;
	int		fd2;
	char	*file;

	fd = open("file3.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	file = get_next_line(fd);
	printf("%s", file);
	file = get_next_line(fd2);
	printf("%s", file);
	file = get_next_line(fd);
	printf("%s", file);
	file = get_next_line(fd2);
	printf("%s", file);
	//fd = open("file.txt", O_RDONLY);
	file = get_next_line(fd);
	printf("%s", file);
	file = get_next_line(fd2);
	printf("%s", file);
	file = get_next_line(fd);
	printf("%s", file);
	file = get_next_line(fd2);
	printf("%s", file);
	free(file);
	close(fd);
	close(fd2);
	return (0);
} */
