/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:51:37 by thpham-v          #+#    #+#             */
/*   Updated: 2021/03/18 14:01:53 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		special_bpos(int before)
{
	int ret;

	before *= -1;
	if (before > 3)
		ret = before;
	else
		ret = 3;
	before -= 3;
	ft_putstr("0x0");
	if (before > 0)
		while (before--)
			ft_putchar(' ');
	return (ret);
}

int		special_bneg(int before)
{
	int ret;

	if (before > 3)
		ret = before;
	else
		ret = 3;
	before -= 3;
	if (before > 0)
		while (before--)
			ft_putchar(' ');
	ft_putstr("0x0");
	return (ret);
}

int		special_null(int before)
{
	int ret;

	if (before < 0)
		ret = special_bpos(before);
	else
		ret = special_bneg(before);
	return (ret);
}

int		p_bpos(t_params params, unsigned long long addr)
{
	t_print args;

	init_var_p(params, &args, addr);
	while (args.space-- > 0)
		ft_putchar(' ');
	print_addr(addr);
	return (args.ret);
}

int		p_bneg(t_params params, unsigned long long addr)
{
	t_print args;

	init_var_p(params, &args, addr);
	print_addr(addr);
	while (args.space-- > 0)
		ft_putchar(' ');
	return (args.ret);
}
