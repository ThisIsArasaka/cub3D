/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:21:38 by michen            #+#    #+#             */
/*   Updated: 2023/11/14 16:32:28 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	const char		*sptr;
	unsigned char	cc;

	cc = (unsigned char)c;
	i = 0;
	sptr = s;
	while (sptr[i] != '\0')
	{
		if (sptr[i] == cc)
		{
			return ((char *)(sptr + i));
		}
		else
			i++;
	}
	if ((sptr[i] == '\0') && (sptr[i] == cc))
		return ((char *)(sptr + i));
	return (NULL);
}
/*
#include <string.h>

int	main(void) {
	char str[] = "Hello, world!";
	char *ptr = strchr(str, 'o');

	if (ptr != NULL) {
		printf("Le caractère 'o' a été trouvé à la position %ld\n", ptr - str);
	} else {
		printf("Le caractère 'o' n'a pas été trouvé\n");
	}

	return (0);
}
*/
