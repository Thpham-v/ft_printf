/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:16:21 by thpham-v          #+#    #+#             */
/*   Updated: 2021/03/18 16:16:09 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_addr(unsigned long long addr)
{
	char *base;

	base = "0123456789abcdef";
	if (!addr)
	{
		ft_putstr("0x");
		return ;
	}
	print_addr(addr / 16);
	ft_putchar(base[addr % 16]);
}

int		pourcent_special_zero(int before)
{
	int ret;

	ret = before;
	while (before-- > 1)
		ft_putchar('0');
	ft_putchar('%');
	return (ret);
}

void	ft_init_struct(t_params *params, char flag, va_list *args)
{
	params->before = 0;
	params->after = 0;
	params->flag = flag;
	params->args = args;
	params->ret = 0;
	params->zero_arg = ' ';
	params->n = 0;
}
