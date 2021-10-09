/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:23:13 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/05 22:23:14 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

ssize_t	ft_strlen_0(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	print_p(t_flags *flags, void *p)
{
	unsigned long	point;
	char			*str;
	int				len;
	int				i;

	i = 0;
	if (!p && flags->accuracy_dot == 0 && flags->width)
		flags->width++;
	point = (unsigned long)p;
	str = ft_itoa_hex(point, 'x');
	len = ft_strlen_0(str);
	while (flags->width > (len + 2) && !flags->minus)
	{
		flags->len += write(1, " ", 1);
		len++;
	}
	flags->len += write(1, "0x", 2);
	print_p2(flags, p, str, len);
	if (str)
		free(str);
	return (0);
}

int	print_p2(t_flags *flags, void *p, char *str, int len)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!p && flags->accuracy_dot == 0)
			break ;
		flags->len += write(1, &str[i++], 1);
	}
	while (flags->width && flags->minus && flags->width > len + 2)
	{
		flags->len += write(1, " ", 1);
		len++;
	}
	return (0);
}
