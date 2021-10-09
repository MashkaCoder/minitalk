/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:23:26 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/06 03:02:45 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	print_str(t_flags *flags, char *str)
{
	int	j;
	int	len;
	int	m;

	j = 0;
	if (str == NULL)
	{
		print_str_null(flags);
		return (0);
	}
	len = ft_strlen(str);
	m = flags->width;
	if (len > flags->accuracy_dot && flags->accuracy_dot >= 0)
		len = flags->accuracy_dot;
	if (!flags->minus && flags->width)
	{
		while (!flags->minus && m > len)
			flags->len += write(1, " ", 1), m--;
		while (str[j] && j != len && flags->accuracy_dot == -1)
			flags->len += write(1, &str[j++], 1);
	}
	print_str2(flags, str, len, j);
	return (0);
}

int	print_str2(t_flags *flags, char *str, int len, int j)
{
	int	i;

	i = 0;
	if (flags->minus && flags->width)
	{
		while (str[j] && j < len)
			flags->len += write(1, &str[j++], 1);
		while (flags->width > j)
		{
			flags->len += write(1, " ", 1);
			j++;
		}
	}
	else if (flags->accuracy_dot >= 0)
	{
		while (str[i] && i != flags->accuracy_dot)
			flags->len += write(1, &str[i++], 1);
	}
	else
		while (str[j])
			flags->len += write(1, &str[j++], 1);
	return (0);
}
