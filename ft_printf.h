/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:30:34 by thpham-v          #+#    #+#             */
/*   Updated: 2021/03/18 16:20:22 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef	struct		s_params
{
	int				before;
	int				after;
	char			flag;
	int				flag_len;
	int				ret;
	char			*temp;
	va_list			*args;
	int				n;
	char			zero_arg;
}					t_params;

typedef	struct		s_print
{
	int				print_len;
	int				zero;
	int				space;
	int				ret;
}					t_print;

int					ft_printf(const char *format, ...);
void				ft_putstr(char *str);
char				ft_find_flag(const char *format);
int					ft_parsing_flag(const char *format, va_list *args);
void				ft_putchar(char c);
int					print_diux(const char *format, char flag, va_list *args);
int					ft_check(const char *format, char flag);
int					ft_nbrlen(int nbr);
void				ft_putnbr(long nb);
int					ft_before_after(const char *format, t_params *params);
void				ft_init_struct(t_params *params, char flag, va_list *args);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_atoi(const char *str);
int					ft_strlen(const char *s);
int					ft_is_star(const char *format, t_params *params);
int					d_bneg_apos(t_params params, long nb);
int					d_bneg_aneg(t_params params, long nb);
int					d_bpos_aneg(t_params params, long nb);
int					d_bpos_apos(t_params params, long nb);
void				init_var_apos_diux(t_params params, t_print *args, int nb);
void				init_var_aneg_diux(t_params params, t_print *var, int nb);
int					diux_choice(t_params params, long nbr);
int					real_len(int nb, char flag);
void				ft_putnbr_hex(unsigned int nb, char flag);
void				print_nb(long nb, char flag);
int					nbr_unsigned_len(unsigned int nb, unsigned int base);
void				ft_putnbr_u(unsigned int nb);
int					special_zero(int before);
int					addrlen(unsigned long long addr);
void				init_args_apos_cs
(t_params params, t_print *var, int length);
void				init_args_aneg_cs
(t_params params, t_print *var, int length);
int					print_s(const char *format, char flag, va_list *args);
void				print_addr(unsigned long long addr);
int					s_choice(t_params params, char *str);
int					s_bpos_apos(t_params params, char *str);
int					s_bpos_aneg_or_noafter(t_params params, char *str);
int					s_bneg_aneg(t_params params, char *str);
int					s_bneg_apos(t_params params, char *str);
int					print_c(const char *format, char flag, va_list *args);
int					pourcent_special_zero(int before);
int					c_choice(t_params params, char c);
int					c_bpos_apos(t_params params, char c);
int					c_bpos_aneg_or_noafter(t_params params, char c);
int					c_bneg_aneg(t_params params, char c);
int					c_bneg_apos(t_params params, char c);
void				init_var_p
(t_params params, t_print *args, unsigned long long addr);
int					print_p(const char *format, char flag, va_list *args);
int					special_bpos(int before);
int					special_bneg(int before);
int					special_null(int before);
int					p_bpos(t_params params, unsigned long long addr);
int					p_bneg
(t_params params, unsigned long long addr);
int					print_pourcent
(const char *format, char flag, va_list *args);

#endif
