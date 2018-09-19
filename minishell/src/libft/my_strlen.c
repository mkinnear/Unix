/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 10:28:29 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/15 01:52:51 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stringmy.h"

int		my_strlen(char *str)
{
	int		len;
	char	*buf;

	if (str == NULL)
		return (0);
	buf = str;
	len = 0;
	while (*buf != '\0')
	{
		len++;
		buf++;
	}
	return (len);
}
