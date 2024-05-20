/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:07:47 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/13 13:40:41 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr1;
	t_list	*ptr2;

	ptr1 = *lst;
	*lst = NULL;
	while (ptr1)
	{
		ptr2 = ptr1->next;
		if (del)
			del(ptr1->content);
		free(ptr1);
		ptr1 = ptr2;
	}
}
