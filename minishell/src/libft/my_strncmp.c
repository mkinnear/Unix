/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:01:04 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/15 01:53:48 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringmy.h"

int		my_strncmp(char *s1, char *s2, int n)
{
	int		result;
	int		i;

	if (n > 0)
	{
		result = 0;
		i = 0;
		while (i < n && s1[i] != '\0' && s2[i] != '\0'
		&& !result)
		{
			result = s1[i] - s2[i];
			i++;
		}
		if (i < n - 1 && s1[i] == '\0' && s2[i] != '\0')
			return (-100);
		else if (i < n - 1 && s2[i] == '\0' && s1[i] != '\0')
			return (100);
		else
			return (result);
	}
	return (0);
}
