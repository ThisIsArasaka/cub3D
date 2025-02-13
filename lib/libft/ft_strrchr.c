/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:08:15 by michen            #+#    #+#             */
/*   Updated: 2023/11/16 16:43:13 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t				i;
	const unsigned char	*sptr;
	unsigned char		cc;

	cc = (unsigned char)c;
	i = 0;
	sptr = (const unsigned char *)s;
	while (sptr[i])
		i++;
	while (i != 0)
	{
		if (sptr[i] == cc)
			return ((char *)(sptr + i));
		i--;
	}
	if (sptr[0] == cc)
		return ((char *)(sptr));
	return (NULL);
}
/*#include <string.h>
int	main(void)
{
	const char *str = "oHell, wrld!o";
	char *ptr = ft_strrchr(str, 'o');

	if (ptr != NULL)
	{
		printf("The character 'o' was found at position %ld\n", ptr - str);
	}
	else
	{
		printf("The character 'o' was not found\n");
	}

	return (0);
}*/
