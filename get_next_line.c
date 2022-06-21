/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurgia- <mmurgia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:16:26 by mmurgia-          #+#    #+#             */
/*   Updated: 2022/06/21 12:54:53 by mmurgia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		if (rd == -1 || rd == 0)
		{
			free(tmp);
			return (0);
		}
	tmp[rd] = '\0';
	str = ft_strjoin(str, tmp);
	printf("str despues: %s\n", str);
	}
	printf("str antes free: %s\n", str);
	free(tmp);
	printf("str free: %s\n", str);
	return (str);
}

char	*ft_get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != 0)
		i++;
	line = (char *)malloc (sizeof(char) * (i + 2));
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
	if (!str)
	{
		free (str);
		return (0);
	}
	tmp = (char *)malloc(sizeof (char) * (ft_strlen(str) - i + 1));
	if (!tmp)
		return (0);
	i++;
	count = 0;
	while (str[i] != '\0')
		tmp[count++] = str[i++];
	tmp[count] = '\0';
	free(str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char		*str;
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	str = ft_read(fd, str);
	if (!str)
		return (0);
	line = ft_get_line(str);
	str = ft_save_line(str);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*file;

	fd = open("file.txt", O_RDONLY);
	file = get_next_line(fd);
	printf("%s", file);
	file = get_next_line(fd);
	printf("%s", file);
	file = get_next_line(fd);
	printf("%s", file);
	file = get_next_line(fd);
	printf("%s", file);
	free(file);
	close(fd);
	return (0);
}
