/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:20:45 by thpham-v          #+#    #+#             */
/*   Updated: 2021/03/18 16:17:19 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_diux(const char *format, char flag, va_list *args)
{
	t_params	params;
	int			ret;
	long		nbr;

	ret = 0;
	format++;
	ft_init_struct(&params, flag, args);
	if ((params.flag_len = ft_check(format, flag)) > 0)
	{
		params.n = ft_before_after(format, &params);
		nbr = va_arg(*args, int);
		if (params.n == 3 && params.after == 0 && nbr == 0)
			return (ret += (special_zero(params.before)));
		ret = diux_choice(params, nbr);
		return (ret);
	}
	nbr = va_arg(*args, int);
	print_nb(nbr, flag);
	ret = real_len(nbr, flag);
	if (nbr < 0 && (flag == 'd' || flag == 'i'))
		ret++;
	return (ret);
}

int		print_s(const char *format, char flag, va_list *args)
{
	char		*str;
	int			ret;
	t_params	params;

	ret = 0;
	format++;
	ft_init_struct(&params, flag, args);
	if ((params.flag_len = ft_check(format, flag)) > 0)
	{
		params.n = ft_before_after(format, &params);
		str = va_arg(*args, char *);
		if (!str)
			str = "(null)";
		if (params.n == 1)
			return (s_bpos_aneg_or_noafter(params, str));
		if (params.n == 3 && params.after == 0 && !str)
			return (ret += (special_zero(params.before)));
		ret = s_choice(params, str);
		return (ret);
	}
	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	ft_putstr(str);
	return ((int)ft_strlen(str));
}

int		print_p(const char *format, char flag, va_list *args)
{
	unsigned long long	addr;
	t_params			params;

	format++;
	ft_init_struct(&params, flag, args);
	if ((params.flag_len = ft_check(format, flag)) > 0)
	{
		params.n = ft_before_after(format, &params);
		addr = (unsigned long long)va_arg(*(params.args), void *);
		if (!addr && params.n != 3)
			return (special_null(params.before));
		if (params.before > 0)
			return (p_bpos(params, addr));
		return (p_bneg(params, addr));
	}
	addr = (unsigned long long)va_arg(*args, void *);
	if (!addr)
		return (special_null(params.before));
	print_addr(addr);
	return (addrlen(addr) + 2);
}

int		print_c(const char *format, char flag, va_list *args)
{
	char		c;
	int			ret;
	t_params	params;

	ret = 0;
	format++;
	ft_init_struct(&params, flag, args);
	if ((params.flag_len = ft_check(format, flag)) > 0)
	{
		params.n = ft_before_after(format, &params);
		c = va_arg(*args, int);
		ret = c_choice(params, c);
		return (ret);
	}
	c = va_arg(*args, int);
	ft_putchar(c);
	return (1);
}

int		print_pourcent(const char *format, char flag, va_list *args)
{
	t_params	params;

	ft_init_struct(&params, flag, args);
	format++;
	if ((params.flag_len = ft_check(format, flag)) > 0)
	{
		params.n = ft_before_after(format, &params);
		if (params.before > 0 && params.zero_arg == '0')
			return (pourcent_special_zero(params.before));
		return (c_choice(params, flag));
	}
	ft_putchar('%');
	return (1);
}
