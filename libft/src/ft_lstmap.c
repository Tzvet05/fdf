/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 01:03:34 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/13 13:41:37 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*old_ptr;
	t_list	*new_ptr;

	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		return (NULL);
	old_ptr = lst->next;
	new_ptr = new_lst;
	while (old_ptr)
	{
		new_ptr->next = ft_lstnew(f(old_ptr->content));
		if (!new_ptr->next)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		old_ptr = old_ptr->next;
		new_ptr = new_ptr->next;
	}
	return (new_lst);
}
