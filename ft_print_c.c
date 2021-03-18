/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:46:07 by thpham-v          #+#    #+#             */
/*   Updated: 2021/03/18 16:11:29 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		c_choice(t_params params, char c)
{
	if (params.n == 1)
		return (c_bpos_aneg_or_noafter(params, c));
	if (params.before > 0)
	{
		if (params.after < 0)
			return (c_bpos_aneg_or_noafter(params, c));
		else
			return (c_bpos_apos(params, c));
	}
	else
	{
		if (params.after < 0)
			return (c_bneg_aneg(params, c));
		else
			return (c_bneg_apos(params, c));
	}
	return (0);
}

int		c_bpos_apos(t_params params, char c)
{
	t_print	args;

	init_args_apos_cs(params, &args, 1);
	while (args.space--)
		ft_putchar(' ');
	ft_putchar(c);
	return (args.ret);
}

int		c_bpos_aneg_or_noafter(t_params params, char c)
{
	t_print	args;

	init_args_aneg_cs(params, &args, 1);
	if (params.before < 0)
	{
		ft_putchar(c);
		while (args.space--)
			ft_putchar(' ');
	}
	else
	{
		while (args.space--)
			ft_putchar(' ');
		ft_putchar(c);
	}
	return (args.ret);
}

int		c_bneg_aneg(t_params params, char c)
{
	t_print	args;

	init_args_aneg_cs(params, &args, 1);
	ft_putchar(c);
	while (args.space--)
		ft_putchar(' ');
	return (args.ret);
}

int		c_bneg_apos(t_params params, char c)
{
	t_print	args;

	init_args_apos_cs(params, &args, 1);
	ft_putchar(c);
	while (args.space--)
		ft_putchar(' ');
	return (args.ret);
}
