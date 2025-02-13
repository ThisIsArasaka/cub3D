/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:07:16 by michen            #+#    #+#             */
/*   Updated: 2023/11/20 18:32:54 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	size_t	k;

	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (j < len && big[j] != '\0')
	{
		k = 0;
		if (big[j] == little[k])
		{
			while (j + k < len && big[j + k] && big[j + k] == little[k])
				k++;
			if (!little[k])
				return ((char *)(&big[j]));
			j++;
		}
		else
			j++;
	}
	return (NULL);
}

//#include <bsd/string.h>

// int	main(void)
//{
//	const char str[] = "aaabcabcd";
//	char *result = ft_strnstr(str, "aabc", -1);
//	char *res = strnstr(str, "aabc", -1);

//	if (result != NULL)
//	{
//		printf("La sous-chaîne a été trouvée : %s\n VRAI = %s", result, res);
//	}
//	if (result == NULL)
//	{
//		printf("La sous-chaîne n'a pas été trouvée\n VRAI = %s", res);
//	}
//	// else
//	//	printf("unknow\n");

//	return (0);
//}