/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:23:23 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/05 22:33:56 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	print_str_null(t_flags *flags)
{
	int		j;
	int		len;
	int		m;
	char	*s;

	j = 0;
	m = flags->width;
	s = "(null)";
	len = ft_strlen(s);
	if (!flags->minus && flags->width > 0)
	{
		if (flags->accuracy_dot >= 0 && len > flags->accuracy_dot)
			len = flags->accuracy_dot;
		while (!flags->minus && m > len)
			flags->len += write(1, " ", 1), m--;
		while (s[j] && j != len)
			flags->len += write(1, &s[j], 1), j++;
	}
	print_str_null2(flags, j, len, s);
}

void	print_str_null2(t_flags *flags, int j, int len, char *s)
{
	if (flags->minus && flags->width)
	{
		if (flags->accuracy_dot >= 0 && len > flags->accuracy_dot)
			len = flags->accuracy_dot;
		while (s[j] && j < len)
			flags->len += write(1, &s[j++], 1);
		while (flags->width > j)
			flags->len += write(1, " ", 1), j++;
	}
	else if (flags->accuracy_dot >= 0)
	{
		while (s[j] && j != flags->accuracy_dot)
			flags->len += write(1, &s[j++], 1);
	}
	else
		while (s[j])
			flags->len += write(1, &s[j++], 1);
}
