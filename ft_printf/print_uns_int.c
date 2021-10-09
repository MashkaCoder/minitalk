/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uns_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:23:31 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/05 22:23:32 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	print_uns_int(t_flags *flags, unsigned int n)
{
	int		zero;
	int		i;

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
	print_uns_int2(flags, n, zero);
	return (0);
}

int	print_uns_int2(t_flags *flags, int n, int zero)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	str = ft_itoa_uns(n);
	len = ft_strlen(str);
	while (zero > len)
	{
		if (str[i] == '-')
		{
			flags->len += write(1, "-", 1);
			i++;
			if (!flags->zero)
				zero++;
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
