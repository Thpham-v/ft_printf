/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_diux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:31:50 by thpham-v          #+#    #+#             */
/*   Updated: 2021/03/18 16:14:07 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		diux_choice(t_params params, long nbr)
{
	if (params.before > 0)
	{
		if (params.after <= 0)
			return (d_bpos_aneg(params, nbr));
		else
			return (d_bpos_apos(params, nbr));
	}
	else
	{
		if (params.after <= 0)
			return (d_bneg_aneg(params, nbr));
		else
			return (d_bneg_apos(params, nbr));
	}
	return (0);
}

int		d_bpos_apos(t_params params, long nb)
{
	t_print var;

	init_var_apos_diux(params, &var, nb);
	while (var.space-- > 0)
		ft_putchar(' ');
	if (nb < 0 && (params.flag == 'd' || params.flag == 'i'))
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (var.zero-- > 0)
		ft_putchar('0');
	print_nb(nb, params.flag);
	return (var.ret);
}

int		d_bpos_aneg(t_params params, long nb)
{
	t_print var;

	init_var_aneg_diux(params, &var, nb);
	if (params.zero_arg == '0' && params.after == 0 && params.n == 3)
		params.zero_arg = ' ';
	if (params.zero_arg == '0' && nb < 0 &&
	(params.flag == 'd' || params.flag == 'i'))
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (var.space-- > 0)
		ft_putchar(params.zero_arg);
	print_nb(nb, params.flag);
	return (var.ret);
}

int		d_bneg_aneg(t_params params, long nb)
{
	t_print var;

	init_var_aneg_diux(params, &var, nb);
	print_nb(nb, params.flag);
	while (var.space-- > 0)
		ft_putchar(' ');
	return (var.ret);
}

int		d_bneg_apos(t_params params, long nb)
{
	t_print var;

	init_var_apos_diux(params, &var, nb);
	if (nb < 0 && (params.flag == 'd' || params.flag == 'i'))
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (var.zero-- > 0)
		ft_putchar('0');
	print_nb(nb, params.flag);
	while (var.space-- > 0)
		ft_putchar(' ');
	return (var.ret);
}
