/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:43:21 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/27 18:13:38 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lst_to_arr(t_list **lst)
{
	char	**arr;
	t_list	*current;
	size_t	len;
	size_t	i;

	len = ft_lstsize(*lst);
	arr = malloc((len + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr[len] = NULL;
	current = *lst;
	i = 0;
	while (i < len)
	{
		arr[i] = current->content;
		current = current->next;
		i++;
	}
	return (arr);
}
