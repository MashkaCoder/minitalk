/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:26:13 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/05 22:26:14 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flags
{
	int		width;
	int		minus;
	int		zero;
	int		len;
	int		hex_len;
	int		accuracy_dot;
	int		minus_in_pres;
	int		i_print;
	va_list	ap;
}			t_flags;

int		ft_printf(const char *s, ...);
void	check_flags(t_flags *flags);
int		ft_type(char c, t_flags *flags);
int		indef_flags(const char *s, t_flags *flags, int *i);
int		print_str(t_flags *flags, char *str);
int		print_str2(t_flags *flags, char *str, int len, int j);
int		print_char(t_flags *flags, int c);
int		print_int(t_flags *flags, int n);
int		print_int2(t_flags *flags, int n, int zero);
int		print_uns_int(t_flags *flags, unsigned int n);
int		print_uns_int2(t_flags *flags, int n, int zero);
int		print_x(t_flags *flags, unsigned int n, char c);
int		print_x2(t_flags *flags, unsigned int n, char c, int zero);
int		print_p(t_flags *flags, void *p);
int		print_p2(t_flags *flags, void *p, char *str, int len);
char	*ft_itoa_uns(unsigned int n);
char	*ft_itoa_hex(unsigned long n, char c);
int		width_hex_dig(t_flags *flags, unsigned int n);
int		trans_hex(t_flags *flags, unsigned int n);
int		trans_heX(t_flags *flags, unsigned int n);
void	print_str_null(t_flags *flags);
void	print_str_null2(t_flags *flags, int j, int len, char *s);
ssize_t	ft_strlen_0(char *s);
int		print_str_int(t_flags *flags, char *str);
void	print_str_int2(t_flags *flags, char *str, int j, int len);
void	print_str_int3(t_flags *flags, char *str, int i, int len);
int		print_percent(t_flags *flags);

#endif
