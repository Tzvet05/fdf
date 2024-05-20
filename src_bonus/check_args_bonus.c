/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:23:23 by ttrave            #+#    #+#             */
/*   Updated: 2024/05/17 19:57:58 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

char	valid_filename(char *filename)
{
	size_t	len;
	size_t	i_filename;
	size_t	i_format;

	len = ft_strlen(filename);
	if (len < ft_strlen(FILE_FORMAT))
	{
		puterr(ERROR_FILENAME, filename);
		return (1);
	}
	i_format = 0;
	i_filename = len - ft_strlen(FILE_FORMAT);
	while (i_filename < len)
	{
		if (FILE_FORMAT[i_format] != filename[i_filename])
		{
			puterr(ERROR_FILENAME, filename);
			return (1);
		}
		i_filename++;
		i_format++;
	}
	return (0);
}

void	check_params(int argc)
{
	if (argc != 2)
	{
		puterr(ERROR_ARGS, NULL);
		exit(1);
	}
}
