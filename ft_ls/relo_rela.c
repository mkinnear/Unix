/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relo_rela.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 18:18:53 by mkinnear          #+#    #+#             */
/*   Updated: 2018/07/11 18:30:50 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	relax(t_data *data, int argc, char **argv)
{
	init_flags(&data->flags);
	arg_reader(argc, argv, &data->flags);
	if (data->flags.rr == 1)
		recursion(".");
	else if (data->flags.ls && data->flags.l == 0)
		horizontal_print(&data);
	else if (data->flags.ls && data->flags.l == 1)
		vertical_print(&data);
}

void	relocate(t_exp *info, t_dir **dir, t_stat *stat, t_data **data)
{
	info->time_date = (char*)malloc(sizeof(char) * (37));
	info->time_date[36] = '\0';
	lstat((*dir)->d_name, stat);
	add_info(info, *dir, *stat);
	add_to_lst(data, *info);
}
