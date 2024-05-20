/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:44:14 by ttrave            #+#    #+#             */
/*   Updated: 2024/05/20 15:44:51 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	get_browse(t_matrix display, long *browsing_data, char start_dir)
{
	if (start_dir == 3 || start_dir == 4)
	{
		browsing_data[0] = 0;
		browsing_data[1] = (long)display.h - 1;
		browsing_data[2] = 1;
	}
	else
	{
		browsing_data[0] = (long)display.h - 1;
		browsing_data[1] = 0;
		browsing_data[2] = -1;
	}
	if (start_dir == 2 || start_dir == 3)
	{
		browsing_data[3] = 0;
		browsing_data[4] = (long)display.w - 1;
		browsing_data[5] = 1;
	}
	else
	{
		browsing_data[3] = (long)display.w - 1;
		browsing_data[4] = 0;
		browsing_data[5] = -1;
	}
}
