/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:23:34 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/05 22:23:35 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	print_x(t_flags *flags, unsigned int n, char c)
{
	int					zero;
	int					i;

	i = 0;
	zero = 0;
	if (flags->width && flags->zero && flags->accuracy_dot == -1)
	{
		zero = flags->width;
		flags->width = 0;
	}
	if (flags->accuracy_dot >= 0 && !flags->zero && !flags->width)
	{
		zero = flags->accuracy_dot;
		flags->accuracy_dot = 0;
	}
	print_x2(flags, n, c, zero);
	return (0);
}

int	print_x2(t_flags *flags, unsigned int n, char c, int zero)
{
	char	*str;
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (c == 'X')
		str = ft_itoa_hex((unsigned long int)n, 'X');
	else
		str = ft_itoa_hex((unsigned long int)n, 'x');
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
	free(str);
	return (0);
}
