/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 17:08:11 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/08 21:20:46 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcount(char *s, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	if (s)
	{
		while (s[i] == c)
			s++;
		while (s[i])
		{
			if (i == 0 && s[i] != c)
				word++;
			else if (s[i] != c && s[i - 1] == c)
				word++;
			i++;
		}
	}
	return (word);
}
