/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:53:08 by mkinnear          #+#    #+#             */
/*   Updated: 2018/07/12 07:48:43 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	lets_print(t_data *tmp)
{
	ft_putstr(tmp->info.perm);
	ft_putchar(' ');
	ft_putnbr((long long)(tmp->info.nlink));
	ft_putchar('\t');
	ft_putstr(tmp->info.user->pw_name);
	ft_putchar(' ');
	ft_putstr(tmp->info.group->gr_name);
	ft_putchar(' ');
	ft_putnbr(tmp->info.size);
	ft_putchar('\t');
	ft_putstr(tmp->info.time_date);
	ft_putchar(' ');
	ft_putstr(tmp->info.d_name);
	ft_putchar('\n');
}

void	vertical_print(t_data **data)
{
	t_data *tmp;

	tmp = (*data);
	arg_solver(data, &tmp);
	if ((*data)->flags.a == 0)
	{
		while (tmp)
		{
			if (tmp->info.d_name[0] != '.')
				lets_print(tmp);
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp)
		{
			lets_print(tmp);
			tmp = tmp->next;
		}
	}
}
