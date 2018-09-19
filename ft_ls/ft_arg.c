/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 15:36:29 by mkinnear          #+#    #+#             */
/*   Updated: 2018/07/12 08:07:13 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	arg_reader(int argc, char **argv, t_flags *flags)
{
	int		i;
	int		j;

	i = 1;
	if (argc == 1)
		return ;
	while (i < argc)
	{
		j = 1;
		while (argv[i][j] != '\0')
		{
			if (argv[i][0] != '-' || (argv[i][0] == '-' && argv[i][1] == '\0'))
			{
				printf("error passing the flags");
			}
			flags->l = ((argv[i][j] == 'l') ? 1 : flags->l);
			flags->a = ((argv[i][j] == 'a') ? 1 : flags->a);
			flags->r = ((argv[i][j] == 'r') ? 1 : flags->r);
			flags->rr = ((argv[i][j] == 'R') ? 1 : flags->rr);
			flags->t = ((argv[i][j] == 't') ? 1 : flags->t);
			j++;
		}
		i++;
	}
}

void	arg_solver(t_data **data, t_data **tmp)
{
	if ((*data)->flags.r == 1 && (*data)->flags.t == 0)
		(*tmp) = reverse_lst(*tmp);
	else if ((*data)->flags.r == 0 && (*data)->flags.t == 1)
		(*tmp) = lst_sort_time(*tmp);
	else if ((*data)->flags.r == 1 && (*data)->flags.t == 1)
	{
		(*tmp) = lst_sort_time(*tmp);
		(*tmp) = reverse_lst(*tmp);
	}
}

void	ft_strmode(t_stat stat, t_exp *info)
{
	const char	chars[] = "?rwxrwxrwx";
	size_t		bit;
	size_t		i;
	size_t		j;

	bit = 16;
	i = 1;
	j = 0;
	if (stat.st_mode & (1 << (16 - 1)))
	{
		if (stat.st_mode & (1 << (16 - 3)))
			info->perm[0] = 'l';
		else
			info->perm[0] = '-';
	}
	if (stat.st_mode & (1 << (16 - 2)))
		info->perm[0] = 'd';
	while (i < 10)
	{
		if (bit)
			info->perm[i++] = (stat.st_mode & (1 << (8 - j++)))
				? chars[i] : '-';
	}
	info->perm[10] = '\0';
}

void	init_flags(t_flags *flags)
{
	flags->ls = 1;
	flags->l = 0;
	flags->a = 0;
	flags->r = 0;
	flags->rr = 0;
	flags->t = 0;
}
