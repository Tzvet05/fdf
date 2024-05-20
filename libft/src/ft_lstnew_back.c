/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:35:08 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/08 13:38:05 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_lstnew_back(t_list **lst, void *content)
{
	t_list	*new;
	t_list	*current;

	new = malloc(sizeof(t_list));
	if (!new)
		return (1);
	new->content = content;
	new->next = NULL;
	if (!*lst)
	{
		*lst = new;
		return (0);
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
	return (0);
}
