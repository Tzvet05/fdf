/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:05:39 by ttrave            #+#    #+#             */
/*   Updated: 2024/04/01 20:18:26 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnlclear(t_gnl **fds)
{
	size_t	i;
	t_gnl	*current;
	t_gnl	*previous;

	i = 0;
	while (i < 1024)
	{
		current = fds[i];
		while (current)
		{
			previous = current;
			current = current->next;
			free(previous->content);
			free(previous);
		}
		fds[i] = NULL;
		i++;
	}
	return (NULL);
}

char	ft_lstnew_back_gnl(t_gnl **fd_arr, int fd, char *content, size_t len)
{
	t_gnl	*new;
	t_gnl	*lst;

	new = malloc(sizeof(t_gnl));
	if (!new)
	{
		free(content);
		return (1);
	}
	new->content = content;
	new->len = len;
	new->i = 0;
	new->next = NULL;
	if (!fd_arr[fd])
		fd_arr[fd] = new;
	else
	{
		lst = fd_arr[fd];
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
	return (0);
}

char	ft_in_gnl(char *s, size_t i_start, size_t len)
{
	if (!s || i_start >= len)
		return (0);
	while (i_start < len)
	{
		if (s[i_start] == '\n')
			return (1);
		i_start++;
	}
	return (0);
}
