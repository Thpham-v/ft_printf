/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_and_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:29:43 by thpham-v          #+#    #+#             */
/*   Updated: 2021/03/18 16:07:04 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_star(const char *format, t_params *params)
{
	if ((format = ft_memchr(format, '*',
	ft_check(format, params->flag))) == NULL)
		return (0);
	if (format[1] == '.')
		return (1);
	if (format[1] == params->flag)
		return (2);
	return (0);
}

int		ft_first_star(const char *format, t_params *params)
{
	params->before = va_arg(*(params->args), int);
	if (*format == '-' && params->before > 0)
		params->before = -params->before;
	if ((params->temp = ft_memchr(format, '.', params->flag_len)))
	{
		if (ft_is_star(params->temp, params) == 2)
		{
			params->after = va_arg(*(params->args), int);
			params->ret = 3;
		}
	}
	return (params->ret);
}

int		ft_second_star(const char *format, t_params *params)
{
	if ((params->temp = ft_memchr(format, '.', ft_check(format, params->flag))))
	{
		params->after = va_arg(*(params->args), int);
		params->ret = 2;
		return (params->ret);
	}
	else
	{
		params->before = va_arg(*(params->args), int);
		if (*format == '-' && params->before > 0)
			params->before = -params->before;
		params->ret = 1;
		return (params->ret);
	}
	return (0);
}

int		ft_third_star(const char *format, t_params *params)
{
	params->before = ft_atoi(format);
	params->ret = (params->ret == 0) ? 1 : 3;
	if (params->ret == 1)
	{
		if ((params->temp = ft_memchr(format, '.',
		ft_check(format, params->flag))))
		{
			params->temp++;
			params->after = ft_atoi(params->temp);
			params->ret = 3;
		}
	}
	return (params->ret);
}

int		ft_before_after(const char *format, t_params *params)
{
	if (*format == '0' && format[1] != '-')
		params->zero_arg = '0';
	if (*format == '0' && format[1] == '-')
		format++;
	params->ret = ft_is_star(format, params);
	if (params->ret == 1)
		ft_first_star(format, params);
	else if (params->ret == 2)
		ft_second_star(format, params);
	if (params->ret == 0 || params->ret == 2)
		ft_third_star(format, params);
	if (params->ret == 1)
	{
		if ((params->temp = ft_memchr(format, '.',
		ft_check(format, params->flag))))
		{
			params->temp++;
			params->after = ft_atoi(params->temp);
			params->ret = 3;
		}
	}
	return (params->ret);
}
