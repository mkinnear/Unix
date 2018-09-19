/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:47:54 by mkinnear          #+#    #+#             */
/*   Updated: 2018/07/12 07:48:24 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	show_it(t_data *tmp)
{
	ft_putstr(tmp->info.d_name);
	ft_putchar('\t');
}

void	horizontal_print(t_data **data)
{
	t_data *tmp;

	tmp = (*data);
	arg_solver(data, &tmp);
	if ((*data)->flags.a == 0)
	{
		while (tmp)
		{
			if (tmp->info.d_name[0] != '.')
				show_it(tmp);
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp)
		{
			show_it(tmp);
			tmp = tmp->next;
		}
	}
	printf("\n");
}
