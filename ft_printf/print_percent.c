/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:23:16 by chasimir          #+#    #+#             */
/*   Updated: 2021/10/05 22:23:17 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	print_percent(t_flags *flags)
{
	while (flags->width > 1 && !flags->minus && !flags->zero)
	{
		flags->len += write(1, " ", 1);
		flags->width--;
	}
	while (flags->zero && flags->width > 1 && !flags->minus)
	{
		flags->len += write(1, "0", 1);
		flags->width--;
	}
	flags->len += write(1, "%", 1);
	while (flags->width > 1 && flags->minus)
	{
		flags->len += write(1, " ", 1);
		flags->width--;
	}
	return (0);
}
