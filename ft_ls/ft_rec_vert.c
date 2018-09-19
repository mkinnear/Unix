/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rec_vert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:33:28 by mkinnear          #+#    #+#             */
/*   Updated: 2018/07/12 07:48:39 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_rec	*new_rec(char *path)
{
	t_rec	*new;

	new = (t_rec *)malloc(sizeof(t_rec));
	new->dir = strdup(path);
	new->next = NULL;
	return (new);
}

t_rec	*add_rec(t_rec *head, char *path)
{
	t_rec	*trav;

	trav = head;
	while (trav->next)
		trav = trav->next;
	trav->next = (t_rec*)malloc(sizeof(t_rec));
	trav->next->dir = strdup(path);
	trav->next->next = NULL;
	return (trav);
}

void	rec_ver_print(t_data **data)
{
	t_data	*tmp;

	tmp = (*data);
	while (tmp)
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
		tmp = tmp->next;
	}
}
