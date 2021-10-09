/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:23:20 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/06 03:14:09 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	print_str_int(t_flags *flags, char *str)
{
	int	j;
	int	len;
	int	m;

	j = 0;
	len = ft_strlen_0(str);
	m = flags->width;
	if (str[0] == '-' && flags->accuracy_dot >= 0)
	{
		m--;
		len--;
	}
	if (!flags->minus && flags->width)
	{
		while (!flags->minus && m > len && m > flags->accuracy_dot)
			flags->len += write(1, " ", 1), m--;
		while (str[j] && j != len && flags->accuracy_dot == -1)
			flags->len += write(1, &str[j++], 1);
	}
	print_str_int2(flags, str, j, len);
	return (0);
}

void	print_str_int2(t_flags *flags, char *str, int j, int len)
{
	int	i;

	i = 0;
	if (flags->minus && flags->width)
	{
		while (flags->accuracy_dot > len)
		{
			if (str[j] == '-')
				flags->len += write(1, "-", 1), j++, i++;
			flags->len += write(1, "0", 1);
			flags->accuracy_dot--;
			flags->width--;
		}
		while (str[j])
		{
			if (flags->accuracy_dot == 0 && str[0] == '0')
				break ;
			flags->len += write(1, &str[j++], 1), i++;
		}
		while (flags->width > i)
			flags->len += write(1, " ", 1), i++;
	}
	print_str_int3(flags, str, j, len);
}

void	print_str_int3(t_flags *flags, char *str, int i, int len)
{
	if (flags->accuracy_dot >= 0)
	{
		while (flags->accuracy_dot > len)
		{
			if (str[i] == '-')
				flags->len += write(1, "-", 1), i++;
			flags->len += write(1, "0", 1);
			len++;
		}
		while (str[i])
		{
			if (str[0] == '0' && flags->accuracy_dot == 0
				&& flags->width && !flags->minus)
				flags->len += write(1, " ", 1);
			if ((flags->accuracy_dot == 0 && str[0] == '0')
				|| (flags->accuracy_dot == 0 && str[0] == '0' && flags->width))
				break ;
			flags->len += write(1, &str[i++], 1);
		}
	}
	else
		while (str[i])
			flags->len += write(1, &str[i++], 1);
}
