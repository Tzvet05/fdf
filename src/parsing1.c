/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:11:02 by ttrave            #+#    #+#             */
/*   Updated: 2024/04/09 16:12:03 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

inline static size_t	get_next_point(char *line)
{
	size_t	i;
	ssize_t	i_sign;
	char	c;

	i = 0;
	i_sign = -1;
	c = line[0];
	while (c && !ft_isdigit(c))
	{
		if (i_sign == -1 && (c == '-' || c == '+'))
			i_sign = (ssize_t)i;
		if (i_sign != -1 && c != '-' && c != '+')
			i_sign = -1;
		i++;
		c = line[i];
	}
	if (i_sign != -1)
		return (i_sign);
	return (i);
}

inline static t_point	*init_arr(char *line, size_t len, size_t i_line)
{
	t_point	*new;
	size_t	i_point;
	size_t	i_char;

	new = malloc(len * sizeof(t_point));
	if (!new)
		return (NULL);
	i_char = 0;
	i_point = 0;
	while (i_point < len)
	{
		i_char += get_next_point(&line[i_char]);
		new[i_point].x = i_point;
		new[i_point].y = i_line;
		new[i_point].z = get_number(&line[i_char], &i_char);
		new[i_point].color = get_color(&line[i_char], &i_char);
		i_point++;
	}
	return (new);
}

inline static char	init_lst(t_list **lst, int fd, size_t *len, char error)
{
	size_t	i_line;
	char	*line;
	t_point	*new;

	i_line = 0;
	while (1)
	{
		line = gnl(fd, 256, &error);
		if (error)
		{
			gnl(-1, 0, &error);
			return (1);
		}
		if (!line)
			return (0);
		if (!i_line)
			*len = count_points(line);
		new = init_arr(line, *len, i_line++);
		free(line);
		if (!new || ft_lstnew_back(lst, new))
		{
			gnl(-1, 0, &error);
			return (1);
		}
	}
}

inline static char	init_map(t_matrix *map, t_list **lst, size_t width)
{
	size_t	len;
	size_t	i;
	t_list	*current;

	len = ft_lstsize(*lst);
	map->matrix = malloc(len * sizeof(t_point *));
	if (!map->matrix)
		return (1);
	map->w = width;
	map->h = len;
	current = *lst;
	i = 0;
	while (current)
	{
		map->matrix[i] = current->content;
		current = current->next;
		i++;
	}
	return (0);
}

char	parse(t_matrix *map, char *filename)
{
	int		fd;
	size_t	len;
	t_list	*lst;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		puterr(ERROR_OPEN, filename);
		return (1);
	}
	len = 0;
	lst = NULL;
	if (init_lst(&lst, fd, &len, 0) || init_map(map, &lst, len))
	{
		close(fd);
		ft_lstclear(&lst, free);
		puterr(ERROR_MALLOC, NULL);
		return (1);
	}
	close(fd);
	ft_lstclear(&lst, NULL);
	return (0);
}
