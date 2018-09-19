/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 10:20:23 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/15 01:49:11 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringmy.h"

int		my_getnbr(char *nbr)
{
	int		int_nbr;
	char	digit;
	char	last_digit;
	int		sign;

	int_nbr = 0;
	sign = 1;
	last_digit = '\0';
	while (*nbr != '\0')
	{
		digit = *nbr;
		if ((digit - '0') >= 0 && (digit - '0') <= 9)
		{
			int_nbr = int_nbr * 10 + digit - '0';
			if (int_nbr < 0)
				return (0);
		}
		else if (digit == '-')
			sign = -sign;
		else if ((last_digit - '0') >= 0 && (last_digit - '0') <= 9)
			return (int_nbr * sign);
		last_digit = digit;
		nbr++;
	}
	return (int_nbr * sign);
}
