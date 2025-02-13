/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:55:52 by michen            #+#    #+#             */
/*   Updated: 2023/11/13 19:51:26 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
/*
int	main(void) {
	char str[20] = "Hello, World!";

	printf("Before bzero: %s\n", str);

	ft_bzero(str, 7);

	printf("After bzero: %s\n", str);

	return (0);
}*/
