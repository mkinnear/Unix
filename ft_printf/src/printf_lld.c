/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_lld.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:14:29 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/14 19:27:01 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_putlld_r(long long lld)
{
	if (lld)
		ft_putlld_r(lld / 10);
	if (lld)
		ft_putchar((lld % 10) * (lld < 0 ? -1 : 1) + '0');
}

void	ft_putlld(long long lld)
{
	if (lld < 0)
		ft_putchar('-');
	if (lld == 0)
		ft_putchar('0');
	else
		ft_putlld_r(lld);
}

void	ft_putlong_r(long n)
{
	if (n)
		ft_putlong_r(n / 10);
	if (n)
		ft_putchar((n % 10) * (n < 0 ? -1 : 1) + '0');
}

void	ft_putlong(long n)
{
	if (n < 0)
		ft_putchar('-');
	if (n == 0)
		ft_putchar('0');
	else
		ft_putlong_r(n);
}
