/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 10:19:18 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/15 01:48:40 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stringmy.h"

char	*merge_strings(char *str, char *plus, int n)
{
	char	*result;
	int		total_len;

	total_len = my_strlen(str) + my_strlen(plus) + 1;
	result = (char*)malloc(sizeof(char) * total_len);
	if (result != NULL)
	{
		if (str != NULL)
		{
			my_strcpy(result, str);
			my_strncat(result, plus, n);
			free(str);
		}
		else
			my_strncpy(result, plus, n);
		return (result);
	}
	return (str);
}
