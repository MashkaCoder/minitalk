/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:23:10 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/05 22:23:11 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	print_int(t_flags *flags, int n)
{
	int		zero;

	zero = 0;
	if (flags->minus_in_pres)
	{
		flags->width = flags->accuracy_dot;
		flags->minus = 1;
	}
	if (flags->width && flags->zero && flags->accuracy_dot == -1)
	{
		zero = flags->width;
		flags->width = 0;
	}
	if (flags->accuracy_dot >= 0 && !flags->zero && !flags->width)
		zero = flags->accuracy_dot;
	print_int2(flags, n, zero);
	return (0);
}

int	print_int2(t_flags *flags, int n, int zero)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	str = ft_itoa(n);
	len = ft_strlen(str);
	while (zero > len)
	{
		if (str[i] == '-')
		{
			flags->len += write(1, "-", 1);
			i++;
		}
		flags->len += write(1, "0", 1);
		zero--;
		flags->accuracy_dot--;
	}
	print_str_int(flags, &str[i]);
	if (str)
		free(str);
	return (0);
}
