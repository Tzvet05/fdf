/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:30:58 by ttrave            #+#    #+#             */
/*   Updated: 2023/11/04 18:30:58 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len_nbr(int n)
{
	size_t	size;

	size = (n < 0);
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char			*nbr;
	unsigned int	n_ui;
	size_t			i;

	i = ft_len_nbr(n);
	nbr = malloc((i + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	nbr[i] = '\0';
	if (n == 0)
		nbr[0] = '0';
	if (n < 0)
	{
		nbr[0] = '-';
		n_ui = -n;
	}
	else
		n_ui = n;
	while (n_ui > 0)
	{
		nbr[i - 1] = n_ui - (n_ui / 10 * 10) + 48;
		n_ui /= 10;
		i--;
	}
	return (nbr);
}
