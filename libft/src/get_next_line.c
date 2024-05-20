/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:05:28 by ttrave            #+#    #+#             */
/*   Updated: 2024/04/01 20:10:37 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_reinit_lst(t_gnl **fd_arr, int fd)
{
	t_gnl	*ptr1;
	t_gnl	*ptr2;
	size_t	i;

	i = 0;
	ptr1 = fd_arr[fd];
	while (ptr1->next)
	{
		ptr2 = ptr1->next;
		free(ptr1->content);
		free(ptr1);
		ptr1 = ptr2;
	}
	fd_arr[fd] = ptr1;
	i = fd_arr[fd]->i;
	while (i < fd_arr[fd]->len && fd_arr[fd]->content[i] != '\n')
		i++;
	i += (i < fd_arr[fd]->len && fd_arr[fd]->content[i] == '\n');
	fd_arr[fd]->i = i;
	if (fd_arr[fd]->i >= fd_arr[fd]->len)
	{
		free(fd_arr[fd]->content);
		free(fd_arr[fd]);
		fd_arr[fd] = NULL;
	}
}

static char	ft_parse_line(t_gnl **fd_arr, int fd, size_t size)
{
	int		len_read;
	char	*buffer;

	len_read = size;
	buffer = NULL;
	while ((size_t)len_read == size && !ft_in_gnl(buffer, 0, size))
	{
		buffer = malloc(size * sizeof(char));
		if (!buffer)
			return (1);
		len_read = read(fd, buffer, size);
		if (len_read == -1)
		{
			free(buffer);
			return (1);
		}
		if (!len_read)
			free (buffer);
		else if (ft_lstnew_back_gnl(fd_arr, fd, buffer, len_read))
			return (1);
	}
	return (0);
}

static char	*ft_alloc_line(t_gnl **fd_arr, int fd, char *line,
	size_t size)
{
	t_gnl	*ptr;
	size_t	len;
	size_t	i;

	len = 0;
	ptr = fd_arr[fd];
	i = ptr->i;
	while (ptr && !(i >= ptr->len && ptr->len < size))
	{
		len++;
		if (ptr->content[i] == '\n')
			break ;
		if (i + 1 >= ptr->len)
		{
			ptr = ptr->next;
			i = 0;
		}
		else
			i++;
	}
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[len] = '\0';
	return (line);
}

static char	*ft_join_lst(t_gnl **fd_arr, int fd, t_gnl *ptr, size_t size)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	ptr = fd_arr[fd];
	j = ptr->i;
	line = ft_alloc_line(fd_arr, fd, NULL, size);
	if (!line)
		return (NULL);
	while (ptr && !(j >= ptr->len && ptr->len < size))
	{
		line[i++] = ptr->content[j];
		if (ptr->content[j] == '\n')
			break ;
		if (j + 1 >= ptr->len)
		{
			ptr = ptr->next;
			j = 0;
		}
		else
			j++;
	}
	ft_reinit_lst(fd_arr, fd);
	return (line);
}

char	*gnl(int fd, size_t size, char *error)
{
	char			*line;
	static t_gnl	*fds[1024] = {NULL};

	if (fd < 0)
		ft_gnlclear(fds);
	if (fd < 0 || fd > 1023 || size == 0)
		return (NULL);
	if (!fds[fd] || (fds[fd]->len == size
			&& !ft_in_gnl(fds[fd]->content, fds[fd]->i, fds[fd]->len)))
	{
		if (ft_parse_line(fds, fd, size))
		{
			*error = 1;
			return (ft_gnlclear(fds));
		}
	}
	if (!fds[fd])
		return (NULL);
	line = ft_join_lst(fds, fd, NULL, size);
	if (!line)
	{
		*error = 1;
		return (ft_gnlclear(fds));
	}
	return (line);
}
