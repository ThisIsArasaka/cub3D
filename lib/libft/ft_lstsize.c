/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:56:58 by michen            #+#    #+#             */
/*   Updated: 2023/11/29 18:43:16 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
// int	main(void)
//{
//	t_list *node;
//	char *str;

//	str = "123";
//	node = ft_lstnew(str);
//	str = "abc";
//	node->next = ft_lstnew(str);
//	// node = node->next;
//	// printf("%s", (char *)node->content);
//	printf("%d", ft_lstsize(node));
//}