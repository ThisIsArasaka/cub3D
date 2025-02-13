/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:50:38 by michen            #+#    #+#             */
/*   Updated: 2023/11/13 19:51:44 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char			*str;
	unsigned int	i;
	unsigned char	r;

	str = s;
	r = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		str[i] = r;
		i++;
	}
	return (str);
}
