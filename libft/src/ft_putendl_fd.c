/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:57:34 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/26 16:06:13 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putendl_fd(char *s, int fd)
{
	size_t	len;
	ssize_t	res;

	len = ft_strlen(s);
	s[len] = '\n';
	res = write(fd, s, len + 1);
	s[len] = '\0';
	return (res);
}
