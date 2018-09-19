/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 15:31:37 by mkinnear          #+#    #+#             */
/*   Updated: 2018/07/11 16:42:38 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data	*lst_swap(t_data *p1, t_data *p2)
{
	p1->next = p2->next;
	p2->next = p1;
	return (p2);
}

t_data	*lst_sort_ascii(t_data *data)
{
	if (!data)
		return (NULL);
	if (data->next && ft_strcmp(data->info.d_name, data->next->info.d_name) > 0)
		data = lst_swap(data, data->next);
	data->next = lst_sort_ascii(data->next);
	if (data->next && ft_strcmp(data->info.d_name, data->next->info.d_name) > 0)
	{
		data = lst_swap(data, data->next);
		data->next = lst_sort_ascii(data->next);
	}
	return (data);
}

t_data	*lst_sort_time(t_data *data)
{
	if (!data)
		return (NULL);
	if (data->next && (data->info.real_time < data->next->info.real_time))
		data = lst_swap(data, data->next);
	data->next = lst_sort_time(data->next);
	if (data->next && (data->info.real_time < data->next->info.real_time))
	{
		data = lst_swap(data, data->next);
		data->next = lst_sort_time(data->next);
	}
	return (data);
}

t_data	*reverse_lst(t_data *data)
{
	t_data *new;
	t_data *tmp1;
	t_data *tmp2;

	new = NULL;
	tmp1 = data;
	tmp2 = (data)->next;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		tmp1->next = new;
		new = tmp1;
		tmp1 = tmp2;
	}
	return (new);
}

void	formatdate(char **str, time_t val)
{
	strftime((*str), 36, "\t%d.%m.%Y  %H:%M:%S ", localtime(&val));
}
