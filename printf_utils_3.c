/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:16:50 by thpham-v          #+#    #+#             */
/*   Updated: 2021/03/18 16:16:59 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(unsigned int nb, char flag)
{
	char	*base_min;
	char	*base_maj;

	base_min = "0123456789abcdef";
	base_maj = "0123456789ABCDEF";
	if (nb >= 16)
		ft_putnbr_hex(nb / 16, flag);
	if (flag == 'x')
		ft_putchar(base_min[nb % 16]);
	else
		ft_putchar(base_maj[nb % 16]);
}

int		real_len(int nb, char flag)
{
	if (flag == 'd' || flag == 'i')
		return (ft_nbrlen(nb));
	if (flag == 'u')
		return (nbr_unsigned_len(nb, 10));
	if (flag == 'x' || flag == 'X')
		return (nbr_unsigned_len(nb, 16));
	return (0);
}

void	print_nb(long nb, char flag)
{
	if (flag == 'd' || flag == 'i')
		ft_putnbr(nb);
	else if (flag == 'u')
		ft_putnbr_u((unsigned int)nb);
	else
		ft_putnbr_hex(nb, flag);
}

int		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		addrlen(unsigned long long addr)
{
	int len;

	len = 0;
	while (addr)
	{
		addr /= 16;
		len++;
	}
	return (len);
}
