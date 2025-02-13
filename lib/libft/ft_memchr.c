/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:16:06 by michen            #+#    #+#             */
/*   Updated: 2023/11/13 19:51:40 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t				i;
	char unsigned		chr;

	str = (const unsigned char *)s;
	i = 0;
	chr = (unsigned char)c;
	while (n > 0)
	{
		if (str[i] == chr)
			return ((int *)&str[i]);
		i++;
		n--;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*str = "hello worls!";
	char	*result;

result = ft_memchr(str, 'o', sizeof(str));
	if (result != NULL) {
		printf("'o' a été trouvé à l'adresse mémoire : %s\n", result);
	} else {
		printf("Le caractère 'o' n'a pas été trouvé.\n");
	}

	return (0);

}*/
