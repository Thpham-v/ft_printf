/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:29:50 by thpham-v          #+#    #+#             */
/*   Updated: 2021/03/18 16:37:09 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pass_flag(const char *format)
{
	int		i;
	char	flag;

	i = 0;
	flag = ft_find_flag(format);
	while (format[i] && format[i] != flag)
		i++;
	return (i + 2);
}

char	ft_find_flag(const char *format)
{
	int i;

	i = 0;
	while (format[i] && format[i] != 'c' && format[i] != 's' && format[i] != 'p'
			&& format[i] != 'd' && format[i] != 'i' && format[i] != 'u'
			&& format[i] != 'x' && format[i] != 'X' && format[i] != '%')
		i++;
	return (format[i]);
}

int		ft_parsing_flag(const char *format, va_list *args)
{
	char	flag;
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	flag = ft_find_flag(format + 1);
	if (flag == 'd' || flag == 'i' || flag == 'x' || flag == 'X' || flag == 'u')
		ret = print_diux(format, flag, args);
	if (flag == 's')
		ret = print_s(format, flag, args);
	if (flag == 'c')
		ret = print_c(format, flag, args);
	if (flag == 'p')
		ret = print_p(format, flag, args);
	if (flag == '%')
		ret = print_pourcent(format, flag, args);
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	ret = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			ret = ret + ft_parsing_flag(format, &args);
			format = format + ft_pass_flag(format + 1);
		}
		else
		{
			ft_putchar(*format);
			format++;
			ret++;
		}
	}
	return (ret);
}

int		main()
{
	printf(" <- [%d]\n", ft_printf("|%015c|\n", 2147483647));
	printf(" <- [%d]\n", printf("|%015c|\n", 2147483647));
	return (0);
}