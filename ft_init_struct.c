/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:12:40 by thpham-v          #+#    #+#             */
/*   Updated: 2021/03/18 16:16:02 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_var_apos_diux(t_params params, t_print *args, int nb)
{
	args->print_len = real_len(nb, params.flag);
	args->zero = 0;
	args->space = 0;
	if (params.after > args->print_len)
		args->zero = params.after - args->print_len;
	if (nb < 0 && (params.flag == 'd' || params.flag == 'i'))
		args->print_len++;
	if (params.before < 0)
		params.before = -(params.before);
	if (params.before > (args->zero + args->print_len))
		args->space = params.before - (args->zero + args->print_len);
	args->ret = args->print_len + args->space + args->zero;
}

void	init_var_aneg_diux(t_params params, t_print *args, int nb)
{
	args->print_len = real_len(nb, params.flag);
	if (params.before < 0)
		params.before = -(params.before);
	args->space = 0;
	if (params.before > args->print_len)
		args->space = params.before - args->print_len;
	if (nb < 0 && (params.flag == 'd' || params.flag == 'i'))
	{
		args->space--;
		args->print_len++;
	}
	if (params.before > args->print_len)
		args->ret = params.before;
	else
		args->ret = args->print_len;
}

void	init_args_apos_cs(t_params params, t_print *args, int length)
{
	args->print_len = length;
	if (params.before < 0)
		params.before = -(params.before);
	if (params.flag == 's' && params.after < args->print_len)
		args->print_len = params.after;
	args->space = 0;
	if (params.before > args->print_len)
		args->space = params.before - args->print_len;
	args->ret = args->space + args->print_len;
}

void	init_args_aneg_cs(t_params params, t_print *args, int length)
{
	args->print_len = length;
	if (params.before < 0)
		params.before = -(params.before);
	args->space = 0;
	if (params.before > args->print_len)
		args->space = params.before - args->print_len;
	args->ret = args->print_len + args->space;
}

void	init_var_p(t_params params, t_print *args, unsigned long long addr)
{
	args->print_len = addrlen(addr) + 2;
	if (params.before < 0)
		params.before = -(params.before);
	args->space = 0;
	if (params.before > args->print_len)
		args->space = params.before - args->print_len;
	if (params.before > args->print_len)
		args->ret = params.before;
	else
		args->ret = args->print_len;
}
