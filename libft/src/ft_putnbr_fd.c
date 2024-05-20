/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:06:38 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/26 16:00:40 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putnbr_fd(int n, int fd)
{
	char	*nbr;
	ssize_t	res;

	nbr = ft_itoa(n);
	if (!nbr)
		return (1);
	res = write(fd, nbr, ft_strlen(nbr));
	free(nbr);
	return (res);
}
