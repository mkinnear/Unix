/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_array_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 09:48:56 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/15 01:42:46 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "arraymy.h"

int		my_array_length(char **arr)
{
	int		i;

	if (arr == NULL)
		return (0);
	i = 0;
	while (arr[i] != NULL)
		i = i + 1;
	return (i);
}
