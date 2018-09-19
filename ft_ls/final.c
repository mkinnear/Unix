/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 17:49:34 by mkinnear          #+#    #+#             */
/*   Updated: 2018/07/11 18:24:33 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recursion1(char **pathway, char *path, t_rec **head, t_exp *info)
{
	lstat(direct2->d_name, &stat1);
	if (direct2->d_type == DT_DIR)
	{
		*pathway = create_path(direct2->d_name, path);
		*head = dynamic_alloc(*head, (*pathway));
	}
	info->time_date = (char*)malloc(sizeof(char) * (37));
	info->time_date[36] = '\0';
	add_info(info, direct2, stat1);
}

void	recursion(char *path)
{
	t_data			*data;
	DIR				*dp;
	char			*pathway;
	t_rec			*head;
	t_exp			info;

	data = NULL;
	printf("%s\n\n\n", path);
	head = NULL;
	if (!(dp = opendir(path)))
		return ;
	while ((direct2 = readdir(dp)))
	{
		if (strcmp(direct2->d_name, ".") == 0 ||
				strcmp(direct2->d_name, "..") == 0)
			continue ;
		recursion1(&pathway, path, &head, &info);
		add_to_lst(&data, info);
	}
	rec_ver_print(&data);
	free_lst(&data);
	looper(head);
}

int		main(int argc, char **argv)
{
	t_data	*data;
	t_dir	*dir;
	t_stat	stat;
	t_file	file_info;
	t_exp	info;

	data = NULL;
	if (argc > 1)
	{
		if ((argv[1][0] == '-' && argv[1][1] == '\0') || argv[1][0] != '-')
		{
			perror("ft_ls - ");
			return (-1);
		}
	}
	file_info.file = opendir(".");
	while ((dir = readdir(file_info.file)))
	{
		relocate(&info, &dir, &stat, &data);
	}
	relax((t_data *)data, (int)argc, (char **)argv);
	closedir(file_info.file);
	free_lst(&data);
	return (0);
}
