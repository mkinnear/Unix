/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:21:31 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/08 21:16:52 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	res;

	i = 0;
	len = ft_strlen(str);
	while (len - 1 > i)
	{
		res = str[i];
		str[i] = str[len - 1];
		str[len - 1] = res;
		len--;
		i++;
	}
	return (str);
}
