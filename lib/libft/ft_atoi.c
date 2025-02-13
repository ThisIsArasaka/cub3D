/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:23:34 by michen            #+#    #+#             */
/*   Updated: 2023/11/15 19:07:32 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char	*str;
	int		i;
	int		minus;
	int		res;

	str = (char *)nptr;
	i = 0;
	minus = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (minus * res);
}
/*#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("42:%d\n", atoi("  \n  42t4457"));
	printf("-42:%d\n", atoi(" --+-42sfs:f545"));
	printf("0:%d\n", atoi("\0 1337"));
	printf("0:%d\n", atoi("-0"));
	printf("0:%d\n", atoi(" - 1 3 2 5 6 3 2 1 6 7"));
	printf("-1325632167:%d\n", atoi("-1325632167"));
	printf("-100:%d\n", atoi("-100"));
	printf("min:%d\n", atoi("\t---+2147483648"));
	printf("max:%d\n", atoi("\v2147483647"));
}*/
