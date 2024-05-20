/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:31:25 by ttrave            #+#    #+#             */
/*   Updated: 2024/04/01 20:37:28 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline static void	ft_init(char *error, t_list **lst)
{
	*error = 0;
	*lst = NULL;
}

char	**ft_read_lines(int fd)
{
	char	**file;
	t_list	*lst;
	char	*line;
	char	error;

	ft_init(&error, &lst);
	line = "";
	while (line)
	{
		line = gnl(fd, 1, &error);
		if (error)
		{
			ft_lstclear(&lst, free);
			return (NULL);
		}
		if (line && ft_lstnew_back(&lst, line))
		{
			free(line);
			ft_lstclear(&lst, free);
			return (NULL);
		}
	}
	file = ft_lst_to_arr(&lst);
	ft_lstclear(&lst, NULL);
	return (file);
}
