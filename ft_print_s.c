/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:28:17 by thpham-v          #+#    #+#             */
/*   Updated: 2021/03/18 12:46:22 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		s_choice(t_params params, char *str)
{
	if (params.before > 0)
	{
		if (params.after < 0)
			return (s_bpos_aneg_or_noafter(params, str));
		else
			return (s_bpos_apos(params, str));
	}
	else
	{
		if (params.after < 0)
			return (s_bneg_aneg(params, str));
		else
			return (s_bneg_apos(params, str));
	}
	return (0);
}

int		s_bpos_apos(t_params params, char *str)
{
	int		i;
	t_print	args;

	i = 0;
	init_args_apos_cs(params, &args, (int)ft_strlen(str));
	while (args.space--)
		ft_putchar(' ');
	while (i < args.print_len)
		ft_putchar(str[i++]);
	return (args.ret);
}

int		s_bpos_aneg_or_noafter(t_params params, char *str)
{
	t_print	args;

	init_args_aneg_cs(params, &args, (int)ft_strlen(str));
	if (params.before < 0)
	{
		ft_putstr(str);
		while (args.space--)
			ft_putchar(' ');
	}
	else
	{
		while (args.space--)
			ft_putchar(' ');
		ft_putstr(str);
	}
	return (args.ret);
}

int		s_bneg_aneg(t_params params, char *str)
{
	t_print	args;

	init_args_aneg_cs(params, &args, (int)ft_strlen(str));
	ft_putstr(str);
	while (args.space--)
		ft_putchar(' ');
	return (args.ret);
}

int		s_bneg_apos(t_params params, char *str)
{
	int		i;
	t_print	args;

	i = 0;
	init_args_apos_cs(params, &args, (int)ft_strlen(str));
	while (args.print_len--)
		ft_putchar(str[i++]);
	while (args.space--)
		ft_putchar(' ');
	return (args.ret);
}
