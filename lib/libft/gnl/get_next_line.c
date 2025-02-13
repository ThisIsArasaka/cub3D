/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:59:46 by michen            #+#    #+#             */
/*   Updated: 2025/02/01 15:52:41 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_newline(char *line, char *buffer)
{
	int	j;

	j = ft_snipe(line, '\n');
	ft_strlcpy_(buffer, line + j + 1, ft_strlen_(line) - j);
	line[j + 1] = '\0';
	return (line);
}
int	ft_toutvabien(char **line, char *buffer, int fd)
{
	ssize_t	bytes;

	while (ft_snipe(*line, '\n') == -1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		*line = ft_strjoin_(*line, buffer);
		if (!*line)
			return (0);
	}
	return (1);
}
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0)
		return (NULL);
	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	(ft_strlcpy_(line, buffer, ft_strlen_(buffer) + 1), buffer[0] = '\0');
	if (!ft_toutvabien(&line, buffer, fd))
		return (NULL);
	if (ft_snipe(line, '\n') != -1)
		line = ft_newline(line, buffer);
	else
		buffer[0] = '\0';
	if (line[0] == '\0')
		return (free(line), NULL);
	return (line);
}

// int	main(int ac, char **av)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open(av[1], O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	(void)ac;
// 	return (0);
// }
