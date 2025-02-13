/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:20:53 by michen            #+#    #+#             */
/*   Updated: 2023/11/28 16:34:15 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strsize(int n)
{
	int	size;
	int	nb;

	size = 1;
	nb = n;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		size++;
		n *= -1;
	}
	while (n >= 10)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nb;
	int		size;

	nb = n;
	i = 0;
	size = ft_strsize(n);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (n < 0)
		nb = -nb;
	while (i < size)
	{
		str[size - i - 1] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

// int	main(void)
//{
//	t_list	list;

//	list.content = "1";
//	list.next.content = "12";
//	list.next.next.content = "123";
//	list.next.next.next.content = NULL;
//}
