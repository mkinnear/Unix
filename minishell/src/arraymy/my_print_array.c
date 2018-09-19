/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 09:50:23 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/15 01:43:46 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stringmy.h"

void	my_print_array(char **arr)
{
	int		i;

	i = 0;
	while (arr[i] != NULL)
	{
		my_putstr(arr[i]);
		my_putchar('\n');
		i = i + 1;
	}
}
