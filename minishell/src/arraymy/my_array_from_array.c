/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_array_from_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 09:47:42 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/15 01:42:01 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stringmy.h"
#include "arraymy.h"

char	**my_array_from_array(char **arr)
{
	char	**new_array;
	int		len;
	int		str_len;
	int		i;

	len = my_array_length(arr);
	new_array = (char**)malloc(sizeof(char*) * (len + 1));
	if (new_array != NULL)
	{
		i = 0;
		while (i < len)
		{
			str_len = my_strlen(arr[i]);
			new_array[i] = (char*)malloc(sizeof(char) * (str_len + 1));
			if (new_array[i] != NULL)
				my_strcpy(new_array[i], arr[i]);
			i = i + 1;
		}
		new_array[i] = NULL;
	}
	return (new_array);
}
