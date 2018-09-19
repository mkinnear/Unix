/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 18:23:52 by mkinnear          #+#    #+#             */
/*   Updated: 2018/07/11 18:26:39 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_rec	*dynamic_alloc(t_rec *head, char *path)
{
	t_rec	*trav;

	trav = head;
	if (trav == NULL)
	{
		trav = new_rec(path);
		head = trav;
	}
	else
	{
		trav = add_rec(head, path);
		trav = head;
	}
	return (trav);
}

char	*create_path(char *pathway, char *curr_dir)
{
	char	*new;
	char	*ret;

	new = ft_strjoin(curr_dir, "/");
	ret = ft_strjoin(new, pathway);
	free(new);
	return (ret);
}

void	looper(t_rec *head)
{
	t_rec	*trav;

	trav = head;
	while (trav)
	{
		recursion(trav->dir);
		trav = trav->next;
	}
}

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
