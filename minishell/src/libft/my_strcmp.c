/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 10:25:57 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/15 01:51:53 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringmy.h"

int		my_strcmp(char *s1, char *s2)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && !result)
	{
		result = s1[i] - s2[i];
		i++;
	}
	if (s1[i] == '\0' && s2[i] != '\0')
		return (-100);
	else if (s2[i] == '\0' && s1[i] != '\0')
		return (100);
	return (result);
}
