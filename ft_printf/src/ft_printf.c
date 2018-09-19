/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:10:15 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/14 19:22:04 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void			ft_handle_star(t_f *f, va_list ap)
{
	f->star = va_arg(ap, int);
	if (f->star == 0)
		f->zero = 1;
	if (f->star < 0)
	{
		f->star = -f->star;
		f->left = 1;
	}
}

static	int		norm_fix(char **fmt, t_f *ft, va_list ap)
{
	int len;

	len = 0;
	if (*(*fmt) == '%')
	{
		len += ft_printf_format(ft, fmt, ap);
		while (ft->left && len < ft->mfw)
			len += write(1, " ", 1);
	}
	else if (*(*fmt) == '{')
		len += set_color(fmt);
	else
	{
		len += write(1, (*fmt), 1);
		(*fmt)++;
	}
	return (len);
}

int				ft_printf(const char *format, ...)
{
	va_list			ap;
	int				len;
	t_f				ft;
	char			*fmt;

	fmt = (char *)format;
	va_start(ap, format);
	ft_ftoken_reset(&ft);
	len = 0;
	while (*fmt)
		len += norm_fix(&fmt, &ft, ap);
	va_end(ap);
	return (len);
}
