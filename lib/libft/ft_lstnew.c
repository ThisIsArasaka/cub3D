/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:54:51 by michen            #+#    #+#             */
/*   Updated: 2023/12/01 21:10:36 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
// int	main(void)
//{
//	t_list *node;
//	char *str;

//	str = "123";
//	node = ft_lstnew(str);
//	str = "abc";
//	node->next = ft_lstnew(str);
//	node = node->next;
//	printf("%s", (char *)node->content);
//}
