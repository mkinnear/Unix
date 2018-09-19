/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 08:07:55 by mkinnear          #+#    #+#             */
/*   Updated: 2018/07/12 08:10:31 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir	**ver_sort(void)
{
	struct dirent	**namelist;
	int				n;
	t_dir			**arr;

	arr = NULL;
	n = scandir(".", &namelist, 0, alphasort);
	if (n < 2)
		perror("scandir");
	else
	{
		arr = namelist;
		while (n--)
		{
			free(namelist[n]);
		}
		free(namelist);
	}
	return (arr);
}
