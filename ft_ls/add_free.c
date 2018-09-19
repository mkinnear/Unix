/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 15:43:05 by mkinnear          #+#    #+#             */
/*   Updated: 2018/07/11 16:15:54 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_info(t_exp *info, t_dir *dir, t_stat stat)
{
	info->d_name = dir->d_name;
	ft_strmode(stat, info);
	info->nlink = (stat.st_nlink);
	info->group = getgrgid(info->id);
	info->user = getpwuid(geteuid());
	info->size = stat.st_size;
	formatdate(&info->time_date, stat.st_mtimespec.tv_sec);
	info->real_time = stat.st_mtimespec.tv_sec;
}

void	add_to_lst(t_data **data, t_exp info)
{
	t_data	*tmp;
	t_data	*tmp1;

	tmp = (t_data*)malloc(sizeof(t_data));
	tmp->info = info;
	tmp->next = NULL;
	if ((*data) == NULL)
	{
		(*data) = tmp;
		return ;
	}
	tmp1 = (*data);
	while (tmp1->next != NULL)
		tmp1 = tmp1->next;
	tmp1->next = tmp;
}

void	free_lst(t_data **data)
{
	t_data	*tmp;
	t_data	*tmp_next;

	if (!(data))
		return ;
	tmp = *data;
	while (tmp)
	{
		tmp_next = tmp->next;
		free(tmp->info.time_date);
		free(tmp);
		tmp = tmp_next;
	}
	*data = NULL;
}
