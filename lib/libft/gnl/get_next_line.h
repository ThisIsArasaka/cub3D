/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:15:40 by michen            #+#    #+#             */
/*   Updated: 2025/02/01 15:51:39 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

size_t	ft_strlen_(char *str);
size_t	ft_strlcpy_(char *dest, const char *src, size_t size);
int		ft_snipe(char *str, char target);
char	*ft_strjoin_(char *s1, char *s2);
char	*ft_newline(char *temp, char *buffer);
char	*get_next_line(int fd);
int		ft_toutvabien(char **line, char *buffer, int fd);

#endif